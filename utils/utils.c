#include "utils.h"

const int UP 	= 119;
const int DOWN  = 115;
const int LEFT  = 97;
const int RIGHT = 100;

void gotoxy(int x, int y)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(handle, coord);
}

void hideCursor() {gotoxy(0, 20);}
