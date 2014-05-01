/*
 * object_maker.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Justin Hellsten
 */

#include "object_maker.h"

// Default Constants
int ObjectMaker::PADDLE_WIDTH = 20;
int ObjectMaker::PADDLE_HEIGHT = 100;
int ObjectMaker::BALL_RADIUS = 5;

Paddle *ObjectMaker::create_paddle(int x, int y) {
	Paddle *paddle = new Paddle();
	paddle->x = x;
	paddle->y = y;
	paddle->width = ObjectMaker::PADDLE_WIDTH;
	paddle->height = ObjectMaker::PADDLE_HEIGHT;
	return paddle;
}

Paddle *ObjectMaker::create_paddle(int x, int y, int width, int height) {
	Paddle *paddle = new Paddle();
	paddle->x = x;
	paddle->y = y;
	paddle->width = width;
	paddle->height = height;
	return paddle;
}

Paddle *ObjectMaker::create_paddle(int x, int y, int width, int height, double dx, double dy) {
	Paddle *paddle = new Paddle();
	paddle->x = x;
	paddle->y = y;
	paddle->width = width;
	paddle->height = height;
	paddle->dx = dx;
	paddle->dy = dy;
	return paddle;
}

Object *ObjectMaker::create_object(int x, int y) {
	Object *object = new Object();
	object->x = x;
	object->y = y;
	return object;
}

Object *ObjectMaker::create_object(int x, int y, int width, int height) {
	Object *object = new Object();
	object->x = x;
	object->y = y;
	object->width = width;
	object->height = height;
	return object;
}

Object *ObjectMaker::create_object(int x, int y, int width, int height, double dx, double dy) {
	Object *object = ObjectMaker::create_object(x, y, width, height);
	object->dx = dx;
	object->dy = dy;
	return object;
}

Ball *ObjectMaker::create_ball(int cx, int cy) {
	Ball *ball = new Ball();
	ball->radius = ObjectMaker::BALL_RADIUS;
	ball->x = cx - ball->radius;
	ball->y = cx - ball->radius;
	return ball;
}

Ball *ObjectMaker::create_ball(int cx, int cy, int radius) {
	Ball *ball = new Ball();
	ball->radius = radius;
	ball->x = cx - radius;
	ball->y = cy - radius;
	return ball;
}
