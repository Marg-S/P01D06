#include<stdio.h>

int width = 80;
int height = 25;

int rocket_r = 6;
int rocket_l = 17;

int vector_x = 1;
int vector_y = 1;

void pole(int, int);
void clearScreen(void);

int coordinate_x(int, int);
int coordinate_y(int);

int main() {
	char c = 0;
	int ball_y = 12;
	int ball_x = 40;

	while ( c != 27 ) {
		pole(ball_x, ball_y);

		ball_x = coordinate_x(ball_x, ball_y);
		//if (ball_x == 2) win right
		//if (ball_x == 78) win left

		ball_y = coordinate_y(ball_y);


		c = getchar();
            switch (c) {
                case ('a') : if ((rocket_r + 2) != 24) {rocket_r+=1;} break;
                case ('z') : if ((rocket_r - 2) != 0) {rocket_r-=1;} break;

                case ('k') : if ((rocket_l + 2) != 24) {rocket_l+=1;} break;
                case ('m') : if ((rocket_l - 2) != 0) {rocket_l-=1;} break;
            }
        

	}
}

int coordinate_x(int ball_x, int ball_y) {

	if (ball_x == 75 && (rocket_r == ball_y - 1 || rocket_r == ball_y || rocket_r == ball_y + 1)) vector_x = -1;
	if (ball_x == 3 && (rocket_r == ball_y - 1 || rocket_l == ball_y || rocket_l == ball_y + 1)) vector_x = 1;

	ball_x = ball_x + vector_x;	
	return ball_x;
}

int coordinate_y(int ball_y) {
	if (ball_y == 23) vector_y = -1;
	if (ball_y == 1) vector_y = 1;
	ball_y = ball_y + vector_y;
	return ball_y;
}

void pole(int ball_x, int ball_y) {
	clearScreen();
    for (int y = 0; y != height; y++) {
        for (int x = 0; x != width; x++) {
	    	if (y == ball_y && x == ball_x)
		    	printf("o");
			else {
			if ((x == 76) && (y == rocket_r - 1 || y == rocket_r || y == rocket_r + 1) ||
			(x == 3 ) && (y == rocket_l - 1 || y == rocket_l  || y == rocket_l + 1)) {
				printf("|");
			}
			else {
                if ((y <= 0) || (y >= height-1))
					printf ("x");
				else {
					if ((x >= width-1) || (x <= 0)) 
                    	printf("x");
                    else
                        printf(" ");
				}
            }
		}
		}

		printf("\n");
    }
}

void clearScreen(void) {
    printf("\33[0d\33[2J");
}


