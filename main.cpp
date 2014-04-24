#include <allegro.h>

void execute_game() {

}

void abort_on_error(const char *message) {

    if (screen != NULL)
       set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);

    allegro_message("%s.\nLast Allegro error `%s'\n",
                    message, allegro_error);

	exit(-1);
}

int main() {

	// Initialize allegro, and set up window
	allegro_init();
    request_refresh_rate(60);
    set_color_depth(32);
    if (set_gfx_mode(GFX_AUTODETECT, 800, 600, 0, 0) != 0)
       abort_on_error("Couldn't set graphic mode!");

    // Start Game
    execute_game();

	return 0;
}
END_OF_MAIN();
