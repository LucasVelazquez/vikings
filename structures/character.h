struct Character
{
	char sprite;
	int sprite_pos_row;
	int sprite_pos_col;
	int console_pos_x;
	int console_pos_y;
};


void drawCharacterMovement(int actual_y, int actual_x, int new_x, int new_y, char sprite);