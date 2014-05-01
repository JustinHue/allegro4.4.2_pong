/*
 * object.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Justin Hellsten
 */

#include "object.h"

Object::Object() : x(0), y(0), width(0), height(0), dx(0), dy(0) { }

void Object::__AI__() {
	this->x += this->dx;
	this->y += this->dy;
}
