#include <termios.h>
#include <unistd.h>
#include <stdio.h>


const int MAX_MAP_X = 10;
const int MAX_MAP_Y = 10;
const int BEGIN_CANVAS_Y = 4;

const int UP 	= 119;
const int DOWN  = 115;
const int LEFT  = 97;
const int RIGHT = 100;

void gotoxy(int x, int y);
int transform_position(int position);
int getch(void);

/*
Referencias

a = 97
d = 100
w = 119
s = 115

escape = 27
' '    = 32
*/


int main()
{

	char map[11][11] = 
{{'o','o','o','o','o','o','o','o','o','o'},
 {'o',' ',' ',' ',' ',' ',' ',' ',' ','o'},
 {'o',' ',' ',' ',' ',' ',' ',' ',' ','o'},
 {'o',' ',' ',' ',' ',' ',' ',' ',' ','o'},
 {'o',' ',' ',' ',' ',' ',' ',' ',' ','o'},
 {'o',' ',' ',' ',' ',' ',' ',' ',' ','o'},
 {'o',' ',' ',' ',' ',' ',' ',' ',' ','o'},
 {'o',' ',' ',' ',' ',' ',' ',' ',' ','o'},
 {'o',' ',' ',' ',' ',' ',' ',' ',' ','o'},
 {'o','o','o','o','o','o','o','o','o','o'}};

	printf("\n\n\n");

	//Pintar mapa
	for(int i = 0; i < MAX_MAP_X; i++)
	{
		for(int j = 0; j < MAX_MAP_Y; j++)
		{
			printf("%c", map[i][j]);
		}
		
		printf("\n");
	}

	//Dibujar personaje
	
	int character_pos_x = 5;
	int character_pos_y = 5;	
	
	gotoxy(transform_position(character_pos_x),character_pos_y);
	printf("%c", 'x');
	

	//Loop del juego
	int keyPressed;

	do
	{
	 keyPressed = getch();
	 
	 if(keyPressed == UP && map[character_pos_x][character_pos_y - 1] != ' ')
	 {
	 	map[character_pos_x][character_pos_y - 1] = map[character_pos_x][character_pos_y];
	 	map[character_pos_x][character_pos_y] = ' '; 
	 }
	 //Seguir con los demás casos
	 
	}	
	while(keyPressed != 27);	
	




	//Fin aplicación
	gotoxy(0, transform_position(20));
	printf("\n\n\n");
	return 0;
}

void gotoxy(int x, int y)
{
	printf("\033[%d;%df", x, y); 
	fflush(stdout);
}

int transform_position(int position)
{
	return position+BEGIN_CANVAS_Y;
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

