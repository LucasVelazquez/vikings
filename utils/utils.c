#include "utils.h"


void gotoxy(int x, int y)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(handle, coord);
}

void hideCursor() {gotoxy(0, 0);}
