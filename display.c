#include "display.h"

void display_color_init() {
	init_pair(FOOD_COLOR, COLOR_BLACK, COLOR_RED);
	init_pair(BG_COLOR, COLOR_BLACK, COLOR_BLACK);
	init_pair(BORDER_COLOR, COLOR_BLACK, COLOR_WHITE);
	init_pair(BAR_COLOR, COLOR_BLACK, COLOR_CYAN);
	init_pair(SNAKE_COLOR, COLOR_WHITE, COLOR_GREEN);
}

int display_init() {
	initscr();
	noecho();
	cbreak();

	curs_set(0);
	start_color();
	display_color_init();
	srand(time(NULL));

	return 0;
}

void *display_getch(void *c) {
	char tmp;

	do {
		read(0, &tmp, 1);
		*((char*)c) = tmp;
	} while (tmp != 'q' && tmp != 'Q');

	pthread_exit(0);
}

void display_finalize() {
	endwin();
}
