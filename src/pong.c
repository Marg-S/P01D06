#include <math.h>
#include <stdio.h>

int Racketka_1 = 12;
int Racketka_2 = 12;

int ball_x = 39;
int ball_y = 12;
int sc1 = 0, sc2 = 0;
int vector_x = -1;
int vector_y = -1;

void ShowTable();
void MoveRacket();
void MoveBall();
void Score();
int CheckScore();
int main() {
    while (1) {
        ShowTable();
        MoveRacket();
        MoveBall();
        Score();
        printf("\e[1;1H\e[2J");
        if (CheckScore() == 1)
            break;
    }
    return 0;
}

void MoveRacket() {
    char a;
        switch (a = getchar()) {
            case ('a') : if ((Racketka_1 + 2) != 24) {Racketka_1+=1;} break;
            case ('z') : if ((Racketka_1 - 2) != 0) {Racketka_1-=1;} break;

            case ('k') : if ((Racketka_2 + 2) != 24) {Racketka_2+=1;} break;
            case ('m') : if ((Racketka_2 - 2) != 0) {Racketka_2-=1;} break;
        }
}
void Score() {
    if(ball_x == 1) {
        sc2++;
        ball_x = 39;
        ball_y = 12;
    }
    if(ball_x == 79) {
        sc1++;
        ball_x = 39;
        ball_y = 12;
    }
    
}
int CheckScore () {
    if(sc1 == 3) {
        printf("FIRST PLAYER IS WIN!!!!!! SCORE : %d - %d\n",sc1,sc2);
        return 1;
    }
    if(sc2 == 3) {
        printf("SECOND PLAYER IS WIN!!!!!! SCORE : %d - %d\n",sc2,sc1);
        return 1;
    }
    return 0;
}
void MoveBall() {
    if (ball_y == 1 || ball_y == 23) {
                vector_y *=(-1);
            }
            if (ball_x == 5 && (ball_y == Racketka_1 || ball_y == (Racketka_1 + 1) || ball_y == (Racketka_1 - 1))) {
                vector_x *=(-1);
            }
            if (ball_x == 75 && (ball_y == Racketka_2 || ball_y == (Racketka_2 + 1) || ball_y == (Racketka_2 - 1))) {
                vector_x *=(-1);
            }
            ball_y += vector_y;
            ball_x += vector_x;
}

void ShowTable() {
    int i;
    int x = 79, y = 24;
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
