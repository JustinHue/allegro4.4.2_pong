/*
 * player_paddle.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Justin Hellsten
 */

#include "player_paddle.h"

PlayerPaddle::PlayerPaddle() : Paddle() {
	this->x = 20;
	this->y = SCREEN_H / 2 - 100 / 2;
	this->width = 20;
	this->height = 100;
}

void PlayerPaddle::__AI__() {
	Paddle::__AI__();

	if (key[KEY_UP]) {
		this->dy -= Paddle::MOVE_RATE;
	}

	if (key[KEY_DOWN]) {
		this->dy += Paddle::MOVE_RATE;
	}

}
