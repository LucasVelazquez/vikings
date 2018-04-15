#include "../utils/utils.h"
#include "../structures/level.h"
#include "../structures/inventory.h"
#include "../structures/talk_box.h"
#include "../structures/character.h"

const int UP 	= 119;
const int DOWN  = 115;
const int LEFT  = 97;
const int RIGHT = 100;

int main()
{
	system("cls");

	//Nivel de prueba
	char sprite[MAX_ROWS_MAP][MAX_COLUMNS_MAP] =
	{
		{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
		{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'}
	};

	struct Level level_0;
	memcpy(level_0.sprite, sprite, sizeof(level_0.sprite));

	level_0.console_pos_x = 3;
	level_0.console_pos_y = 2;

	//DibuJar GUI (borrar pantalla y setear cursor)
	drawLevel(level_0.console_pos_x , level_0.console_pos_y, level_0.sprite);
	drawInventory();
	drawTalkBox();

	//Dibujar personaje	
	struct Character player;

	player.sprite = 'o';
	player.sprite_pos_row = 2;
	player.sprite_pos_col = 2;

	player.console_pos_x = (level_0.console_pos_x  + 1 + player.sprite_pos_col);
	player.console_pos_y = (level_0.console_pos_y  + 1 + player.sprite_pos_row);

	drawCharacter(player.console_pos_x, player.console_pos_y, player.console_pos_x, player.console_pos_y, player.sprite);

	hideCursor();

	//Loop del juego
	int key_pressed;

	do
	{
		key_pressed = getch();

		if(key_pressed == UP && level_0.sprite[player.sprite_pos_row - 1][player.sprite_pos_col] == 32)
		{
			drawCharacter(player.console_pos_x, player.console_pos_y, player.console_pos_x, (player.console_pos_y - 1), player.sprite);
			--player.console_pos_y;
			--player.sprite_pos_row;
		}

		else if(key_pressed == LEFT && level_0.sprite[player.sprite_pos_row][player.sprite_pos_col - 1] == 32)
		{
			drawCharacter(player.console_pos_x, player.console_pos_y, (player.console_pos_x - 1), player.console_pos_y, player.sprite);
			--player.console_pos_x;
			--player.sprite_pos_col;
		}

		else if(key_pressed == RIGHT && level_0.sprite[player.sprite_pos_row][player.sprite_pos_col + 1] == 32)
		{
			drawCharacter(player.console_pos_x, player.console_pos_y, (player.console_pos_x + 1), player.console_pos_y, player.sprite);
			++player.console_pos_x;
			++player.sprite_pos_col;
		}

		else if(key_pressed == DOWN && level_0.sprite[player.sprite_pos_row + 1][player.sprite_pos_col] == 32)
		{
			drawCharacter(player.console_pos_x, player.console_pos_y,player.console_pos_x, (player.console_pos_y + 1), player.sprite);
			++player.console_pos_y;
			++player.sprite_pos_row;
		}

		hideCursor();
	}	
	while(key_pressed != 27);	

	return 0;
}



