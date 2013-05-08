#ifndef H_SNAKE_H
#define H_SNAKE_H

#include "global.h"
#include "board.h"

#define SNAKE_SIZE	100

#define NORTH		0
#define EAST		1
#define SOUTH		2
#define WEST		3

#define RIGHT		1
#define LEFT		-1

#define ALIVE		1
#define DEAD		0

typedef struct {
	int x[SNAKE_SIZE];
	int y[SNAKE_SIZE];
	int steps;
	int size;
	int grow;
	int turn;
	int alive;
	char dir;
} Snake;

//inicjuje węża
void snake_init(Snake *s);

//sprawdza czy nastąpiły warunki do zakończenia programu
int snake_crash(Snake *s, char c);

//porusza wężem
int snake_move(Snake *s, Board *b);

//rysuje węża
void snake_draw(Snake *s, Board *b);

//wylicza kierunek podążania węża
void snake_decide(Snake *s, Board *b);

//startuje węża
void snake_start();

#endif
