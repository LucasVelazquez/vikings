#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y);
void hideCursor();

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
gcc utils/utils.c structures/level.c structures/inventory.c structures/talk_box.c structures/character.c  main/main.c -o game



*/