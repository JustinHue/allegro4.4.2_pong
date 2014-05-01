/*
 * paddle.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Justin Hellsten
 */

#include "paddle.h"

double Paddle::PADDLE_FRICTION = 0.4;
int Paddle::PADDLE_WIDTH = 20;
int Paddle::PADDLE_HEIGHT = 100;
double Paddle::MOVE_RATE = 1.0;

Paddle::Paddle() : Object() { }

void Paddle::__AI__() {
	Object::__AI__();

	// Apply Friction to paddle dy
	this->dy = (this->dy >= -Paddle::PADDLE_FRICTION && this->dy <= Paddle::PADDLE_FRICTION) ?
			0 : (this->dy < -Paddle::PADDLE_FRICTION) ?
					this->dy + Paddle::PADDLE_FRICTION : this->dy - Paddle::PADDLE_FRICTION;

	// Check Boundaries
	if (this->y < 1) {
		this->y = 1;
		this->dy = 0;
	}
	if (this->y > SCREEN_H - Paddle::PADDLE_HEIGHT - 2) {
		this->y = SCREEN_H - Paddle::PADDLE_HEIGHT - 2;
		this->dy = 0;
	}
}
