#define MAX_ROWS_MAP 	20
#define MAX_COLUMNS_MAP 45

#define MAX_ROWS_INVENTORY 		20
#define MAX_COLUMNS_INVENTORY 	20

#define MAX_ROWS_TALK_BOX  		9
#define MAX_COLUMNS_TALK_BOX 	70

char test_level[MAX_ROWS_MAP][MAX_COLUMNS_MAP];

int position_map_draw_x;
int position_map_draw_y;

char inventory_menu[MAX_ROWS_INVENTORY][MAX_COLUMNS_INVENTORY];

int inventory_map_draw_x;
int inventory_map_draw_y;

char talk_box[MAX_ROWS_TALK_BOX][MAX_COLUMNS_TALK_BOX];

int talk_box_map_draw_x;
int talk_box_map_draw_y;