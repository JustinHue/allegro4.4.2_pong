/*
 * player_paddle.h
 *
 *  Created on: Apr 28, 2014
 *      Author: root
 */

#ifndef __PLAYER_PADDLE_H__
#define __PLAYER_PADDLE_H__

#include <allegro.h>
#include "paddle.h"

class PlayerPaddle : public Paddle {

public:
	PlayerPaddle();
	void __AI__();

protected:

private:

};

#endif /* PLAYER_PADDLE_H_ */
