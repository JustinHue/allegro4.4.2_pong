/*
 * paddle.h
 *
 *  Created on: Apr 27, 2014
 *      Author: Justin Hellsten
 */

#ifndef __PADDLE_H__
#define __PADDLE_H__

#include <allegro.h>
#include "object.h"

class Paddle : public Object {

public:
	static double PADDLE_FRICTION;
	static double MOVE_RATE;
	static int PADDLE_WIDTH, PADDLE_HEIGHT;

	Paddle();
	void __AI__();

protected:

private:

};
#endif /* PADDLE_H_ */
