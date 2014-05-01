/*
 * ball.h
 *
 *  Created on: Apr 28, 2014
 *      Author: Justin Hellsten
 */

#ifndef __BALL_H__
#define __BALL_H__

#include <allegro.h>
#include <stdlib.h>
#include <time.h>
#include "object.h"

class Ball : public Object {

public:
	static int BALL_RADIUS;
	static int INIT_DX_RANGE, INIT_DY_RANGE, MIN_INIT_RANGE;

	Ball();
	void __AI__();

	int radius;

protected:

private:
	void reset();

};

#endif /* BALL_H_ */
