/*
 * ball.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Justin Hellsten
 */

#include "ball.h"

int Ball::BALL_RADIUS = 5;
int Ball::INIT_DX_RANGE = 10;
int Ball::INIT_DY_RANGE = 5;
int Ball::MIN_INIT_RANGE = 3;

Ball::Ball() : Object() {

	this->radius = Ball::BALL_RADIUS;
	this->x = SCREEN_W / 2 - this->radius;
	this->y = SCREEN_H / 2 - this->radius;

	srand(time(NULL));
	this->dx = rand() % (Ball::INIT_DX_RANGE) + Ball::MIN_INIT_RANGE;
	this->dx = (rand() % 2 == 1) ? -this->dx : this->dx;

	this->dy = rand() % (Ball::INIT_DY_RANGE) + Ball::MIN_INIT_RANGE;
	this->dy = (rand() % 2 == 1) ? -this->dy : this->dy;

}

void Ball::__AI__() {
	Object::__AI__();

	if (this->y - this->radius < 1) {
		this->y = 1 + this->radius;
		this->dy *= -1;
	}
	if (this->y > SCREEN_H - this->radius -1) {
		this->y = SCREEN_H - this->radius - 1;
		this->dy *= -1;
	}

	if (this->x < -100 || this->x > SCREEN_W + 100) {
		this->reset();
	}

}

void Ball::reset() {
	this->x = SCREEN_W / 2 - this->radius;
	this->y = SCREEN_H / 2 - this->radius;

	this->dx = rand() % (Ball::INIT_DX_RANGE) + Ball::MIN_INIT_RANGE;
	this->dx = (rand() % 2 == 1) ? -this->dx : this->dx;

	this->dy = rand() % (Ball::INIT_DY_RANGE) + Ball::MIN_INIT_RANGE;
	this->dy = (rand() % 2 == 1) ? -this->dy : this->dy;

}
