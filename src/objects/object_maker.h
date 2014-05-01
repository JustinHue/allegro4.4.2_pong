/*
 * object_maker.h
 *
 *  Created on: Apr 27, 2014
 *      Author: Justin Hellsten
 */

#ifndef __OBJECT_MAKER_H__
#define __OBJECT_MAKER_H__

#include "object.h"

#include "paddle.h"
#include "player_paddle.h"
#include "cpu_paddle.h"

#include "ball.h"

class ObjectMaker {

public:

	// Default Constants
	static int PADDLE_WIDTH;
	static int PADDLE_HEIGHT;
	static int BALL_RADIUS;

	// Object Make Methods
	static Paddle *create_paddle(int x, int y);
	static Paddle *create_paddle(int x, int y, int width, int height);
	static Paddle *create_paddle(int x, int y, int width, int height, double dx, double dy);

	static PlayerPaddle *create_player_paddle(int x, int y);
	static PlayerPaddle *create_player_paddle(int x, int y, int width, int height);
	static PlayerPaddle *create_player_paddle(int x, int y, int width, int height, double dx, double dy);

	static Object *create_object(int x, int y);
	static Object *create_object(int x, int y, int width, int height);
	static Object *create_object(int x, int y, int width, int height, double dx, double dy);

	static Ball *create_ball(int cx, int cy);
	static Ball *create_ball(int cx, int cy, int radius);

};

#endif /* OBJECT_MAKER_H_ */
