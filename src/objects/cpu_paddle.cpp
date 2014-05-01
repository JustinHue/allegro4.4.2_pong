/*
 * cpu_paddle.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Justin Hellsten
 */

#include "cpu_paddle.h"

double CPUPaddle::MAX_DY = 15.0;

CPUPaddle::CPUPaddle() : Paddle() {
	this->x = SCREEN_W - 20 * 2;
	this->y = SCREEN_H / 2 - 100 / 2;
	this->width = 20;
	this->height = 100;
}

void CPUPaddle::__AI__() {
	Paddle::__AI__();

	// Ball is moving towards cpu paddle
	if (this->ball->x < this->x && this->ball->dx > 0) {

		if (this->ball->y < this->y + this->height / 2) {
			this->dy -= Paddle::MOVE_RATE;
		} else if (this->ball->y > this->y + this->height / 2) {
			this->dy += Paddle::MOVE_RATE;
		}

	} else {

		// Go towards center
		if (this->y + this->height / 2 + Paddle::MOVE_RATE * 2 < SCREEN_H / 2) {
			this->dy += Paddle::MOVE_RATE;
		} else if (this->y + this->height / 2 - Paddle::MOVE_RATE * 2> SCREEN_H / 2) {
			this->dy -= Paddle::MOVE_RATE;
		}

	}

	// CPU Paddle will make sure he doesn't go past the max dy limit
	if (this->dy > CPUPaddle::MAX_DY) this->dy = CPUPaddle::MAX_DY;
	if (this->dy < -CPUPaddle::MAX_DY) this->dy = -CPUPaddle::MAX_DY;


}
