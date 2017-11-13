#include <stdio.h>
#include <windows.h>
#include <conio.h>

const int UP 	= 119;
const int DOWN  = 115;
const int LEFT  = 97;
const int RIGHT = 100;

void gotoxy(int x, int y);
void hideCursor();
void drawCharacterMovement(int actualY, int actualX, int newX, int newY, char sprite);

/*
Referencias

a = 97
d = 100
w = 119
s = 115

escape = 27
' '    = 32


La pantalla de console empieza a contar de 0


*/


int main()
{
	//mapa [arreglos][cantidad_de_elementos]

	//Para navegar en el sprite se usa [filas][columnas]
	//Para navegar en la pantalla se usa [x][y]

	int max_rows_map = 15;
	int max_columns_map = 55;

	//Sprites
	char testLevel[15][55] = 
	{
		{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
	};

	//Configuración de mapas
	int position_map_draw_x = 3;
	int position_map_draw_y = 2;

 	//Configuración personaje

	char character_sprite = 'o';

	//Posición en el sprite donde aparecerá el personaje
	int character_sprite_pos_row = 2;
	int character_sprite_pos_col = 2;

	//Posición en la consola donde aparecerá el personaje (debe coincidir con el equivalente a la posición en el sprite)
	
	//(Posición de dibujado del mapa + dimesión de bloque + posición del jugador equivalente)
	int character_console_pos_x = (position_map_draw_x + 1 + 2);
	int character_console_pos_y = (position_map_draw_y + 1 + 2);

	//Inicio de dibujo (borrar pantalla y setear cursor)

	system("cls");

	gotoxy(0, 1);
	printf("-------------------------------<< Nivel de prueba >>--------------------------------");

	gotoxy(position_map_draw_x, position_map_draw_y);

	int initial_value_draw_x = position_map_draw_x;

	//Pintar mapa
	for(int i = 0; i < max_rows_map; ++i)
	{
		++position_map_draw_y;
		for(int j = 0; j < max_columns_map; ++j)
		{
			++position_map_draw_x;
			gotoxy(position_map_draw_x, position_map_draw_y);
			printf("%c", testLevel[i][j]);
		}
		//printf("\n");
		position_map_draw_x = initial_value_draw_x;
	}

	//Dibujar personaje	
	
	gotoxy(character_console_pos_x, character_console_pos_y);
	printf("%c", character_sprite);

	hideCursor();

	//Loop del juego
	int keyPressed;

	do
	{
		keyPressed = getch();

		if(keyPressed == UP && testLevel[character_sprite_pos_row - 1][character_sprite_pos_col] == 32)
		{
			drawCharacterMovement(character_console_pos_x, character_console_pos_y, character_console_pos_x, (character_console_pos_y - 1), character_sprite);
			--character_console_pos_y;
			--character_sprite_pos_row;
		}

		else if(keyPressed == LEFT && testLevel[character_sprite_pos_row][character_sprite_pos_col - 1] == 32)
		{
			drawCharacterMovement(character_console_pos_x, character_console_pos_y, (character_console_pos_x - 1), character_console_pos_y, character_sprite);
			--character_console_pos_x;
			--character_sprite_pos_col;
		}

		else if(keyPressed == RIGHT && testLevel[character_sprite_pos_row][character_sprite_pos_col + 1] == 32)
		{
			drawCharacterMovement(character_console_pos_x, character_console_pos_y, (character_console_pos_x + 1), character_console_pos_y, character_sprite);
			++character_console_pos_x;
			++character_sprite_pos_col;
		}

		else if(keyPressed == DOWN && testLevel[character_sprite_pos_row + 1][character_sprite_pos_col] == 32)
		{
			drawCharacterMovement(character_console_pos_x, character_console_pos_y,character_console_pos_x, (character_console_pos_y + 1), character_sprite);
			++character_console_pos_y;
			++character_sprite_pos_row;
		}

		hideCursor();

		//Para probar posición de jugador
	/*	gotoxy(0, 20);
		printf("console: x = %d, y = %d",character_console_pos_x,character_console_pos_y);
		gotoxy(0, 23);
		printf("sprite: row = %d, col = %d",character_sprite_pos_row,character_sprite_pos_col);
	*/
	}	
	while(keyPressed != 27);	
	


	//Fin aplicación
	printf("\n\n\n");

	return 0;
}

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
 
void drawCharacterMovement(int actualY, int actualX, int newX, int newY, char sprite)
{
	gotoxy(actualY, actualX);
	printf(" ");
	gotoxy(newX, newY);
	printf("%c", sprite);
}



