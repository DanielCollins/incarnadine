/* 
   Copyright (c) 2010 Daniel Flahive, Daniel Collins

   Permission to use, copy, modify, and distribute this software for any
   purpose with or without fee is hereby granted, provided that the above
   copyright notice and this permission notice appear in all copies.
 
   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "obj.h"

using namespace incarnadine;

ObjModel::ObjModel(std::string filename)
{
   m_windowListIndex = 0;
   m_useWindowList = false;

   std::ifstream file(filename.c_str(), std::ios::in);

   if (file.fail())
      throw 1;

   // Add a 'default' group to the list of groups.
   objGroup defaultGroup;
   defaultGroup.smooth = true;
   defaultGroup.faces = new std::vector<objFaceTriangle>();
   m_groups[std::string("")] = defaultGroup;

   objGroupIter activeGroup = m_groups.find(std::string(""));

   // Get file size and allocate a large enough buffer.
   file.seekg(0, std::ios::end);
   unsigned int filesize = (unsigned int)file.tellg();
   file.seekg(0, std::ios::beg);
   char *buffer = new char[filesize + 1];

   // Read file contents into buffer.
   file.read(buffer, filesize);
   buffer[filesize] = '\0';

   // Parse each line.
   char *leftBound = buffer;
   char *i;
   for (i = buffer; i < (buffer + filesize); i++)
   {
      if ((*i == '\r' || *i == '\n'))
      {
         *i = '\0';
         if (strlen(leftBound) > 0)
            parseLine(leftBound, activeGroup);

         // Handle the '\n' after a possible '\r'.
         if (*i == '\r' && *(i + 1) == '\n')
         {
            *(i + 1) = '\0';
            leftBound = i + 2;
         }
         else
         {
            leftBound = i + 1;
         }
      }
   }

   // If there wasn't a newline at the end of the file, handle the rest of the buffer here.
   if (leftBound < (buffer + filesize) - 1)
   {
      parseLine(leftBound, activeGroup);
   }

   delete [] buffer;

   file.close();

   // Clear the now-redundant data vectors.
   m_vertices.clear();
   m_normals.clear();
   m_texCoords.clear();

   // Generate window list.
   onContextReset();
}

ObjModel::~ObjModel()
{
   for (objGroupIter i = m_groups.begin(); i != m_groups.end(); i++)
   {
      if (i->second.faces != NULL)
      {
         delete i->second.faces;
         i->second.faces = NULL;
      }
   }

   m_groups.clear();
}

void ObjModel::parseLine(char *line, objGroupIter& activeGroup)
{
   // Consume whitespace at the start of the line, if any.
   while (*line == ' ' || *line == '\t')
      line++;

   size_t lineLength = strlen(line);

   if (lineLength >= 1 && line[0] == 'g')
   {
      if (lineLength > 1 && line[1] == ' ')
      {
         // Group name to follow?
      }
      else
      {
         // 'g' command with no group name.
      }
   }
   else if (lineLength > 2 && line[0] == 'v' && line[1] == ' ')
   {
      line += 2;
      char *strvertex[3] = { NULL, NULL, NULL };

      for (int i = 0; i < 3; i++)
      {
         // Consume whitespace at the start of the definition.
         while (*line == ' ' || *line == '\t')
            line++;

         // Store beginning of the vertex value.
         strvertex[i] = line;

         if (strlen(line) > 0)
         {
            // Consume characters until we reach whitespace (or the end of the line).
            while (*line != ' ' && *line != '\t' && *line != '\0')
               line++;

            // Convert the whitespace to a null character, hence giving us our
            // vertex value string.
            *line = '\0';
            line++;
         }
         else
         {
            return;
         }
      }

      if (strvertex[0] != NULL && strvertex[1] != NULL && strvertex[2] != NULL)
      {
         float vertex[3];
         vertex[0] = (float)atof(strvertex[0]);
         vertex[1] = (float)atof(strvertex[1]);
         vertex[2] = (float)atof(strvertex[2]);

         m_vertices.push_back(vector3(vertex[0], vertex[1], vertex[2]));
      }

   }
   else if (lineLength > 3 && line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
   {
      line += 3;
      char *strnormal[3] = { NULL, NULL, NULL };

      for (int i = 0; i < 3; i++)
      {
         // Consume whitespace at the start of the definition.
         while (*line == ' ' || *line == '\t')
            line++;

         // Store beginning of the normal value.
         strnormal[i] = line;

         if (strlen(line) > 0)
         {
            // Consume characters until we reach whitespace (or the end of the line).
            while (*line != ' ' && *line != '\t' && *line != '\0')
               line++;

            // Convert the whitespace to a null character, hence giving us our
            // normal value string.
            *line = '\0';
            line++;
         }
         else
         {
            return;
         }
      }

      if (strnormal[0] != NULL && strnormal[1] != NULL && strnormal[2] != NULL)
      {
         vector3 normal = vector3((float)atof(strnormal[0]), (float)atof(strnormal[1]), (float)atof(strnormal[2]));
         m_normals.push_back(normal);
      }

   }
   else if (lineLength > 3 && line[0] == 'v' && line[1] == 't' && line[2] == ' ')
   {
      line += 3;
      char *strtexcoord[3] = { NULL, NULL, NULL };

      for (int i = 0; i < 3; i++)
      {
         // Consume whitespace at the start of the definition.
         while (*line == ' ' || *line == '\t')
            line++;

         // Store beginning of the texcoord value.
         strtexcoord[i] = line;

         if (strlen(line) > 0)
         {
            // Consume characters until we reach whitespace (or the end of the line).
            while (*line != ' ' && *line != '\t' && *line != '\0')
               line++;

            // Convert the whitespace to a null character, hence giving us our
            // texcoord value string.
            *line = '\0';
            line++;
         }
         else
         {
            return;
         }
      }

      if (strtexcoord[0] != NULL && strtexcoord[1] != NULL && strtexcoord[2] != NULL)
      {
         m_texCoords.push_back(vector3((float)atof(strtexcoord[0]), (float)atof(strtexcoord[1]), (float)atof(strtexcoord[2])));
      }
   }
   else if (lineLength > 2 && line[0] == 'f' && line[1] == ' ')
   {
      line += 2;
      char *strface[3] = { NULL, NULL, NULL };

      for (int i = 0; i < 3; i++)
      {
         // Consume whitespace at the start of the definition.
         while (*line == ' ' || *line == '\t')
            line++;

         // Store beginning of the face definition.
         strface[i] = line;

         if (strlen(line) > 0)
         {
            // Consume characters until we reach whitespace (or the end of the line).
            while (*line != ' ' && *line != '\t' && *line != '\0')
               line++;

            // Convert the whitespace to a null character, hence giving us our
            // face string.
            *line = '\0';
            line++;
         }
         else
         {
            return;
         }
      }

      if (strface[0] != NULL && strface[1] != NULL && strface[2] != NULL)
      {
         objFaceTriangle face;
         for (int i = 0; i < 3; i++)
         {
            // Find the number of '/' to determine whether there are normals, textures, both, or neither defined.

            char *slashPositions[2] = { NULL, NULL };
            char *iter = strface[i];
            int numSlashes = 0;
            while (*iter != '\0')
            {
               if (*iter == '/')
               {
                  if (numSlashes >= 2)
                  {
                     // Invalid; can't have more than 2 slashes in face definition.
                     return;
                  }

                  slashPositions[numSlashes++] = iter;
               }

               iter++;
            }

            unsigned int vertexOffset;
            unsigned int normalOffset;
            unsigned int texCoordOffset;
            if (numSlashes == 0)
            {
               sscanf(strface[i], "%d", &vertexOffset);
               face.vertex[i] = m_vertices[vertexOffset - 1];
               face.hasNormals = false;
               face.hasTexCoords = false;
            }
            else if (numSlashes == 2)
            {
               if (slashPositions[0] == slashPositions[1] - 1)
               {
                  // Vertex and normal defined, since the two slashes have nothing in between.
                  sscanf(strface[i], "%d//%d", &vertexOffset, &normalOffset);
                  face.vertex[i] = m_vertices[vertexOffset - 1];
                  face.normal[i] = m_normals[normalOffset - 1];
                  face.hasNormals = true;
                  face.hasTexCoords = false;
               }
               else
               {
                  // Vertex, normal and texture coords were defined.
                  sscanf(strface[i], "%d/%d/%d", &vertexOffset, &texCoordOffset, &normalOffset);
                  face.vertex[i] = m_vertices[vertexOffset - 1];
                  face.normal[i] = m_normals[normalOffset - 1];
                  face.texcoord[i] = m_texCoords[texCoordOffset - 1];
                  face.hasNormals = true;
                  face.hasTexCoords = true;
               }
            }
            else
            {
               // Any other number of slashes is invalid.
               return;
            }

         }

         addFaceTriangle(face, activeGroup);
      }

   }

}

void ObjModel::addFaceTriangle(const objFaceTriangle& face, objGroupIter activeGroup)
{
   activeGroup->second.faces->push_back(face);
}

void ObjModel::onContextReset()
{
   // Re-create the window list, if it hasn't already been created.
   
   if (m_useWindowList)
      glDeleteLists(m_windowListIndex, 1);

   m_windowListIndex = glGenLists(1);
   glNewList(m_windowListIndex, GL_COMPILE);

   m_useWindowList = false;
   
   draw();
   glEndList();

   m_useWindowList = true;
}

void ObjModel::draw()
{
   glPushAttrib(GL_ENABLE_BIT);
   glDisable(GL_TEXTURE_2D);
   glEnable(GL_COLOR_MATERIAL);
   glColor3f(1.0f, 0.0f, 1.0f);

   if (m_useWindowList)
   {
      glCallList(m_windowListIndex);
   }
   else
   {
      // Render all the groups that have at least one face.
      for (objGroupIter i = m_groups.begin(); i != m_groups.end(); i++)
      {
         std::vector<objFaceTriangle>* faces = i->second.faces;

         glBegin(GL_TRIANGLES);
      
         for (unsigned int j = 0; j < faces->size(); j++)
         {
            objFaceTriangle* face = &(*faces)[j];

            for (unsigned int k = 0; k < 3; k++)
            {
               if (face->hasNormals)
                  glNormal3fv((const GLfloat*)&face->normal[k]);

               if (face->hasTexCoords)
                  glTexCoord3fv((const GLfloat*)&face->texcoord[k]);

               glVertex3fv((const GLfloat*)&face->vertex[k]);
            }
         
         }

         glEnd();
      }
   }

   glPopAttrib();
}

