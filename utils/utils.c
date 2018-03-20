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

/*Notas*/

//Para navegar en el sprite se usa [filas][columnas]
//Para navegar en la pantalla se usa [x][y]

/*
Referencias

a = 97
d = 100
w = 119
s = 115

escape = 27
' '    = 32


La pantalla de console empieza a contar de 0

//compilar
D:\Lucas\Proyectos\Vikings>
gcc utils/utils.c levels/levels.c structures/character.c  main/main.c -o test


*/