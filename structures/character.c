#include "character.h"
#include "../utils/utils.h"

void drawCharacterMovement(int actual_y, int actual_x, int new_x, int new_y, char sprite)
{
	gotoxy(actual_y, actual_x);
	printf(" ");
	gotoxy(new_x, new_y);
	printf("%c", sprite);
}

void drawCharacter(int console_x, int console_y, char sprite)
{
	gotoxy(console_x, console_y);
	printf("%c", sprite);
}

//Para probar posición de jugador
/*	gotoxy(0, 20);
	printf("console: x = %d, y = %d",character_console_pos_x,character_console_pos_y);
	gotoxy(0, 23);
	printf("sprite: row = %d, col = %d",character_sprite_pos_row,character_sprite_pos_col);
*/