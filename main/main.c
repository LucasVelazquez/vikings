#include <stdio.h>
#include <windows.h>
#include <conio.h>

const int UP 	= 119;
const int DOWN  = 115;
const int LEFT  = 97;
const int RIGHT = 100;

//Para navegar en el sprite se usa [filas][columnas]
//Para navegar en la pantalla se usa [x][y]
const int max_rows_map = 15;
const int max_columns_map = 35;

const int max_rows_inventory = 15;
const int max_columns_inventory = 20;


void gotoxy(int x, int y);
void hideCursor();
void drawCharacterMovement(int actual_y, int actual_x, int new_x, int new_y, char sprite);

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

	//Sprites
	char test_level[15][35] = 
	{
		{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
	};

	int position_map_draw_x = 3;
	int position_map_draw_y = 2;


	char inventory_menu[15][20] =
	{
		{'-','-','-','-','-','-','-','B','o','l','s','a','-','-','-','-','-','-','-'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}

	};

	int inventory_map_draw_x =40;
	int inventory_map_draw_y =2;


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
	printf("-------------------------------<< Nivel de prueba >>-------------------------");

	//Dibujar mapa
	gotoxy(position_map_draw_x, position_map_draw_y);
	int initial_value_draw_x = position_map_draw_x;

	for(int i = 0; i < max_rows_map; ++i)
	{
		++position_map_draw_y;
		for(int j = 0; j < max_columns_map; ++j)
		{
			++position_map_draw_x;
			gotoxy(position_map_draw_x, position_map_draw_y);
			printf("%c", test_level[i][j]);
		}
		//printf("\n");
		position_map_draw_x = initial_value_draw_x;
	}

	//Dibujar inventario
	gotoxy(inventory_map_draw_x, inventory_map_draw_y);
	initial_value_draw_x = inventory_map_draw_x;

	for(int i = 0; i < max_rows_inventory; ++i)
	{
		++inventory_map_draw_y;
		for(int j = 0; j < max_columns_inventory; ++j)
		{
			++inventory_map_draw_x;
			gotoxy(inventory_map_draw_x, inventory_map_draw_y);
			printf("%c", inventory_menu[i][j]);
		}
		//printf("\n");
		inventory_map_draw_x = initial_value_draw_x;
	}

	//Dibujar personaje	
	
	gotoxy(character_console_pos_x, character_console_pos_y);
	printf("%c", character_sprite);

	hideCursor();

	//Loop del juego
	int key_pressed;

	do
	{
		key_pressed = getch();

		if(key_pressed == UP && test_level[character_sprite_pos_row - 1][character_sprite_pos_col] == 32)
		{
			drawCharacterMovement(character_console_pos_x, character_console_pos_y, character_console_pos_x, (character_console_pos_y - 1), character_sprite);
			--character_console_pos_y;
			--character_sprite_pos_row;
		}

		else if(key_pressed == LEFT && test_level[character_sprite_pos_row][character_sprite_pos_col - 1] == 32)
		{
			drawCharacterMovement(character_console_pos_x, character_console_pos_y, (character_console_pos_x - 1), character_console_pos_y, character_sprite);
			--character_console_pos_x;
			--character_sprite_pos_col;
		}

		else if(key_pressed == RIGHT && test_level[character_sprite_pos_row][character_sprite_pos_col + 1] == 32)
		{
			drawCharacterMovement(character_console_pos_x, character_console_pos_y, (character_console_pos_x + 1), character_console_pos_y, character_sprite);
			++character_console_pos_x;
			++character_sprite_pos_col;
		}

		else if(key_pressed == DOWN && test_level[character_sprite_pos_row + 1][character_sprite_pos_col] == 32)
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
	while(key_pressed != 27);	
	


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

void drawCharacterMovement(int actual_y, int actual_x, int new_x, int new_y, char sprite)
{
	gotoxy(actual_y, actual_x);
	printf(" ");
	gotoxy(new_x, new_y);
	printf("%c", sprite);
}


//Esta función deberá aceptar una matriz dinámica}
/*void drawSprite(int maxRows, int maxColumns, char[][] sprite)
{

}*/



