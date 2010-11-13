/* 
   Copyright (c) 2010 Daniel Collins

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

#include "object.h"

using namespace incarnadine;

Object::Object()
{
   position = velocity =  acceleration = angularVelocity = angularAcceleration = Vector3(0.0, 0.0, 0.0);
   quaternion_rotation_euler(orientation, 0.0f, 0.0f, 0.0f, euler_order_xyz);
}

Vector3 Object::getPosition()
{
   return position;
}

void Object::setPosition(Vector3 v)
{
   position = v;
}

Vector3 Object::getVelocity()
{
   return velocity;
}

void Object::setVelocity(Vector3 v)
{
   velocity = v;
}

Vector3 Object::getAcceleration()
{
   return acceleration;
}

void Object::setAcceleration(Vector3 v)
{
   acceleration = v;
}

iquaternion Object::getOrientation()
{
   return orientation;
}

void Object::setOrientation(iquaternion q)
{
   orientation = q;
}

void Object::setOrientation(Vector3 v)
{
   quaternion_rotation_euler(orientation, v[0], v[1], v[2], euler_order_xyz);
}

Vector3 Object::getAngularVelocity()
{
   return angularVelocity;
}

void Object::setAngularVelocity(Vector3 v)
{
   angularVelocity = v;
}

Vector3 Object::getAngularAcceleration()
{
   return angularAcceleration;
}

void Object::setAngularAcceleration(Vector3 v)
{
   angularAcceleration = v;
}

void Object::rotateX(float angle)
{
   quaternion_rotate_about_local_x(orientation, angle);
   orientation.normalize();
}

void Object::rotateY(float angle)
{
   quaternion_rotate_about_local_y(orientation, angle);
   orientation.normalize();
}

void Object::rotateZ(float angle)
{
   quaternion_rotate_about_local_z(orientation, angle);
   orientation.normalize();
}

void Object::rotate(Vector3 eulerRotation)
{
   rotateX(eulerRotation[0]);
   rotateY(eulerRotation[1]);
   rotateZ(eulerRotation[2]);
}

void Object::rotate(iquaternion q)
{
   orientation = orientation * q;
   orientation.normalize();
}

void Object::translate(Vector3 displacement)
{
   Matrix44 transform;
   matrix_rotation_quaternion(transform, orientation);
   position += transform_vector(transform, displacement);
}

void Object::update(unsigned int deltaTicks)
{
   translate(deltaTicks * (velocity + acceleration * deltaTicks) / 2);
   velocity += acceleration * deltaTicks;
   Vector3 ra = deltaTicks * (angularVelocity + angularAcceleration * deltaTicks) / 2.0;
   rotate(ra);
   angularVelocity += angularAcceleration * deltaTicks;
}

