//========================================================================
//
// Copyright (c) 2010 David Forrest
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include "log.h"

Logger::Logger(char* filename)
{
	logfile = fopen(filename, "a");
}

Logger::~Logger()
{
	fclose(logfile);
	delete logfile;
}

void Logger::log(char* message)
{
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(timebuffer,20,"%y/%m/%d %H:%M:%S",timeinfo);
	
	fputs(timebuffer, logfile);
	fputs(message, logfile);
	fputs("\n", logfile);
}

