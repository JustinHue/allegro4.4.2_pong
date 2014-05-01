/*
 * cpu_paddle.h
 *
 *  Created on: Apr 28, 2014
 *      Author: Justin Hellsten
 */

#ifndef __CPU_PADDLE_H__
#define __CPU_PADDLE_H__

#include <allegro.h>
#include "paddle.h"
#include "ball.h"
#include "player_paddle.h"

class CPUPaddle : public Paddle {

public:
	static double MAX_DY;

	CPUPaddle();
	void __AI__();

	// References needed for CPU AI
	Ball *ball;
	PlayerPaddle *player_paddle;

protected:

private:

};

#endif /* CPU_PADDLE_H_ */
