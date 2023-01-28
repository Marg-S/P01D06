#include <math.h>
#include <stdio.h>

void ShowTable(int Racketka_1,int Racketka_2,int ball_x,int ball_y);
int main() {
    int Racketka_1 = 12;
    int Racketka_2 = 12;

    int ball_x = 39;
    int ball_y = 12;

    int vector_x = -1;
    int vector_y = 1;
    while (1) {
        while(ball_x != 0 || ball_x != 80) {
            ShowTable(Racketka_1, Racketka_2, ball_x, ball_y);
            char a;
            switch (a = getchar()) {
                case ('a') : if ((Racketka_1 + 2) != 24) {Racketka_1+=1;} break;
                case ('z') : if ((Racketka_1 - 2) != 0) {Racketka_1-=1;} break;

                case ('k') : if ((Racketka_2 + 2) != 24) {Racketka_2+=1;} break;
                case ('m') : if ((Racketka_2 - 2) != 0) {Racketka_2-=1;} break;
            }
        
            if (ball_y == 1 || ball_y == 24) {
                vector_y *=(-1);
            }
            if (ball_x == 5 && (ball_y == Racketka_1 || ball_y == Racketka_1+1 || ball_y == Racketka_1-1)) {
                vector_x *=(-1);
            }
            if (ball_x == 75 && (ball_y == Racketka_2 || ball_y == (Racketka_2+1) || ball_y == (Racketka_2-1))) {
                vector_x *=(-1);
            }
            ball_y += vector_y;
            ball_x += vector_x;
            printf("\e[1;1H\e[2J");
        }

    }
    return 0;
}
void ShowTable(int Racketka_1,int Racketka_2,int ball_x,int ball_y) {
    int i;
    int x = 79, y = 24, sc1, sc2;
    sc1 = 0;
    sc2 = 0;
    do {
        for (int i = 0; x >= i; i++) {
            if ((y == 24) || (y == 0)) {
                printf("#");
            } else {
                if ((y == 23) && (i == 38)) {
                    printf("%d||%d", sc1, sc2);
                    i = i + 3;
                } else {
                    if (((i == 0) || (i == 79)) && (y != 0) && (y != 24)) {
                        printf("#");
                        i = i + 2;
                    }                   
                    if ((i == 4) && ((y == Racketka_1) || (y == Racketka_1 + 1) || (y == Racketka_1 - 1))) {
                        printf("@");
                        i++;
                    }
                    if ((i == 76) && ((y == Racketka_2) || (y == Racketka_2 + 1) || (y == Racketka_2 - 1))) {
                        printf("@");
                        i++;
                    }
                    if (i == ball_x && y == ball_y) {
                       printf("o");
                       i++;
                    }
                    printf(" ");
                }
                
            }
        
        }
        y--;
        printf("\n");
    } while (y >= 0);
}
