#include <allegro.h>

#include "src/objects/objects.h"
#include "src/constants.h"

volatile int CLOSE_BUTTON_PRESS = FALSE;
volatile int UT;

BITMAP *buffer;

// Game Objects
PlayerPaddle *player_paddle;
CPUPaddle *cpu_paddle;
Ball *ball;

void __close_button_handler__(void) {
	CLOSE_BUTTON_PRESS = TRUE;
}
END_OF_FUNCTION(__close_button_handler__)

void __update_ticker__() {
	UT++;
}
END_OF_FUNCTION(__update_ticker__)

void init() {
	// Create screen buffer
	buffer = create_bitmap(SCREEN_W, SCREEN_H);

	// Create Objects
	player_paddle = new PlayerPaddle();
	ball = new Ball();

	cpu_paddle = new CPUPaddle();
	cpu_paddle->player_paddle = player_paddle;
	cpu_paddle->ball = ball;



			/*
	player_paddle = ObjectMaker::create_paddle(ObjectMaker::PADDLE_WIDTH * 2,
			SCREEN_H / 2 - ObjectMaker::PADDLE_HEIGHT / 2);
	cpu_paddle = ObjectMaker::create_paddle(SCREEN_W - ObjectMaker::PADDLE_WIDTH * 3,
			SCREEN_H / 2 - ObjectMaker::PADDLE_HEIGHT / 2);
			*/
}

void update() {

	ball->__AI__();
	player_paddle->__AI__();
	cpu_paddle->__AI__();

	// Check if ball hits paddle
	if (ball->x - ball->radius < player_paddle->x + player_paddle->width &&
		ball->x + ball->radius > player_paddle->x &&
		ball->y - ball->radius < player_paddle->y + player_paddle->height &&
		ball->y + ball->radius > player_paddle->y) {

		ball->dx *= -1;
		ball->x = player_paddle->x + player_paddle->width + ball->radius;

	}

	if (ball->x - ball->radius < cpu_paddle->x + cpu_paddle->width &&
		ball->x + ball->radius > cpu_paddle->x &&
		ball->y - ball->radius < cpu_paddle->y + cpu_paddle->height &&
		ball->y + ball->radius > cpu_paddle->y) {

		ball->dx *= -1;
		ball->x = cpu_paddle->x - ball->radius;

	}
}

void render() {


	// Render Paddles
	rectfill(buffer, player_paddle->x, player_paddle->y,
			player_paddle->x + player_paddle->width,
			player_paddle->y + player_paddle->height, makecol(0, 100, 243));

	rect(buffer, player_paddle->x, player_paddle->y,
			player_paddle->x + player_paddle->width,
			player_paddle->y + player_paddle->height, makecol(0, 0, 255));

	rectfill(buffer, cpu_paddle->x, cpu_paddle->y,
			cpu_paddle->x + cpu_paddle->width,
			cpu_paddle->y + cpu_paddle->height, makecol(243, 100, 0));

	rect(buffer, cpu_paddle->x, cpu_paddle->y,
			cpu_paddle->x + cpu_paddle->width,
			cpu_paddle->y + cpu_paddle->height, makecol(255, 0, 0));

	// Render Ball
	circlefill(buffer, ball->x, ball->y, ball->radius, makecol(25, 0, 255));

	textprintf_centre_ex(buffer, font, SCREEN_W / 2, 120,
	                           makecol(0, 100, 243), -1,
	                           "dy %f",
	                           player_paddle->dy);

	textprintf_centre_ex(buffer, font, SCREEN_W / 2, 200,
	                           makecol(0, 100, 243), -1,
	                           "ball dx %f",
	                           ball->dx);

	// Render Buffer
	acquire_screen();
	draw_sprite(screen, buffer, 0, 0);
	rectfill(buffer, 0, 0, buffer->w, buffer->h, makecol(0, 0, 0));
	release_screen();
}


void execute_game() {
	do {
		// Yield CPU
		while (UT == 0)
			rest(1);
		// Update Game
		while (UT > 0) {
			int last_tick = UT;
			update();
			--UT;
			// If update took too long, force render
			if (last_tick <= UT) break;
		}
		render();
	} while (!key[KEY_ESC] && !CLOSE_BUTTON_PRESS);
}

void abort_on_error(const char *message) {

    if (screen != NULL)
       set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);

    allegro_message("%s.\nLast Allegro error `%s'\n",
                    message, allegro_error);

	exit(-1);
}

int main() {

	// Initialize allegro
	allegro_init();
	install_timer();
	install_keyboard();

    LOCK_FUNCTION(__close_button_handler__);
    set_close_button_callback(__close_button_handler__);

    install_int(__update_ticker__, 33);

    LOCK_VARIABLE(UT);
    LOCK_FUNCTION(__update_ticker__);

	// Set up window
	set_window_title("Pong");
    request_refresh_rate(60);
    set_color_depth(32);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0)
       abort_on_error("Couldn't set graphic mode!");

    init();

    // Execute Game Loop
    execute_game();

	return 0;
}
END_OF_MAIN();
