#define MAX_ROWS_MAP 	15
#define MAX_COLUMNS_MAP 45

struct Level
{
	char sprite[MAX_ROWS_MAP][MAX_COLUMNS_MAP];
	//char * sprite;
	//int position_map_draw_x,
	int console_pos_x;
	//int position_map_draw_y,
	int console_pos_y;
};

void drawLevel(int position_map_x , int position_map_y, char sprite[][MAX_COLUMNS_MAP]);


