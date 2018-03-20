#include <stdio.h>
#include "../levels/levels.h"
#include "../utils/utils.h"
#include "../structures/character.h"

int main()
{
 	//Configuración personaje

	struct Character player;

	player.sprite = 'o';
	//Posición en el sprite donde aparecerá el personaje
	player.sprite_pos_row = 2;
	player.sprite_pos_col = 2;
	//Posición en la consola donde aparecerá el personaje (debe coincidir con el equivalente a la posición en el sprite)	
	//(Posición de dibujado del mapa + dimesión de bloque + posición del jugador equivalente)
	player.console_pos_x = (position_map_draw_x + 1 + 2);
	player.console_pos_y = (position_map_draw_y + 1 + 2);
	
	strcpy(player.name, "Lucas");

	//Inicio de dibujo (borrar pantalla y setear cursor)
	system("cls");
	gotoxy(0, 1);
	
	printf("-------------------------------<< Nivel de prueba >>-------------------------");

	//Dibujar mapa
	gotoxy(position_map_draw_x, position_map_draw_y);
	int initial_value_draw_x = position_map_draw_x;

	for(int i = 0; i < MAX_ROWS_MAP; ++i)
	{
		++position_map_draw_y;
		for(int j = 0; j < MAX_COLUMNS_MAP; ++j)
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

	for(int i = 0; i < MAX_ROWS_INVENTORY; ++i)
	{
		++inventory_map_draw_y;
		for(int j = 0; j < MAX_COLUMNS_INVENTORY; ++j)
		{
			++inventory_map_draw_x;
			gotoxy(inventory_map_draw_x, inventory_map_draw_y);
			printf("%c", inventory_menu[i][j]);
		}
		//printf("\n");
		inventory_map_draw_x = initial_value_draw_x;
	}

	//Dibujar área de mensajes
	gotoxy(talk_box_map_draw_x, talk_box_map_draw_y);
	initial_value_draw_x = talk_box_map_draw_x;

	for(int i = 0; i < MAX_ROWS_TALK_BOX; ++i)
	{
		++talk_box_map_draw_y;
		for(int j = 0; j < MAX_COLUMNS_TALK_BOX; ++j)
		{
			++talk_box_map_draw_x;
			gotoxy(talk_box_map_draw_x, talk_box_map_draw_y);
			printf("%c", talk_box[i][j]);
		}
		//printf("\n");
		talk_box_map_draw_x = initial_value_draw_x;
	}

	//Dibujar personaje	
	gotoxy(player.console_pos_x, player.console_pos_y);
	printf("%c", player.sprite);

	hideCursor();

	//Loop del juego
	int key_pressed;

	do
	{
		key_pressed = getch();

		if(key_pressed == UP && test_level[player.sprite_pos_row - 1][player.sprite_pos_col] == 32)
		{
			drawCharacterMovement(player.console_pos_x, player.console_pos_y, player.console_pos_x, (player.console_pos_y - 1), player.sprite);
			--player.console_pos_y;
			--player.sprite_pos_row;
		}

		else if(key_pressed == LEFT && test_level[player.sprite_pos_row][player.sprite_pos_col - 1] == 32)
		{
			drawCharacterMovement(player.console_pos_x, player.console_pos_y, (player.console_pos_x - 1), player.console_pos_y, player.sprite);
			--player.console_pos_x;
			--player.sprite_pos_col;
		}

		else if(key_pressed == RIGHT && test_level[player.sprite_pos_row][player.sprite_pos_col + 1] == 32)
		{
			drawCharacterMovement(player.console_pos_x, player.console_pos_y, (player.console_pos_x + 1), player.console_pos_y, player.sprite);
			++player.console_pos_x;
			++player.sprite_pos_col;
		}

		else if(key_pressed == DOWN && test_level[player.sprite_pos_row + 1][player.sprite_pos_col] == 32)
		{
			drawCharacterMovement(player.console_pos_x, player.console_pos_y,player.console_pos_x, (player.console_pos_y + 1), player.sprite);
			++player.console_pos_y;
			++player.sprite_pos_row;
		}

		hideCursor();
	}	
	while(key_pressed != 27);	
	
	//Fin aplicación
	printf("\n\n\n");

	return 0;
}

//Esta función deberá aceptar una matriz dinámica}
/*void drawSprite(int maxRows, int maxColumns, char[][] sprite)
{

}*/



