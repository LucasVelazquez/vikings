#include "levels.h"
//#include "../utils/utils.h"

void drawLevel(int position_map_x , int position_map_y, char[][MAX_COLUMNS_MAP] sprite)
{
	gotoxy(position_map_x, position_map_y);
	int initial_value_draw_x = position_map_x;

	for(int i = 0; i < MAX_ROWS_MAP; ++i)
	{
		++position_map_y;
		for(int j = 0; j < MAX_COLUMNS_MAP; ++j)
		{
			++position_map_x;
			gotoxy(position_map_x, position_map_y);
			printf("%c", sprite[i][j]);
		}
		position_map_x = initial_value_draw_x;
	}
}