
struct Character
{
	char sprite;
	//Posición en el sprite donde aparecerá el personaje
	int sprite_pos_row;
	int sprite_pos_col;
	//Posición en la consola donde aparecerá el personaje (debe coincidir con el equivalente a la posición en el sprite)	
	//(Posición de dibujado del mapa + dimesión de bloque + posición del jugador equivalente)
	int console_pos_x;
	int console_pos_y;
};


void drawCharacter(int actual_y, int actual_x, int new_x, int new_y, char sprite);
