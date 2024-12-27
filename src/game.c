#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define EMPTY ' '
#define ROW 5
#define COLUMN 5
/*
0|0|0
-----
0|0|0
-----
0|0|0
*/

typedef struct {
    char field[5][6];
}field;


void init_field(field* f){
    for (int i = 0; i < 5; i++){
        if (i%2==0){
            f->field[i][0] = EMPTY;
            f->field[i][1] = '|';
            f->field[i][2] = EMPTY;
            f->field[i][3] = '|';
            f->field[i][4] = EMPTY;
            f->field[i][5] = '\0';
        }else{
            f->field[i][0] = '-';
            f->field[i][1] = '-';
            f->field[i][2] = '-';
            f->field[i][3] = '-';
            f->field[i][4] = '-';
            f->field[i][5] = '\0';
        }
    }//i don't know man, i'm to stubborn tu use 2 for loops
}

void print_field(field* f){
    printf("\033[32m\033[H\033[2J");
    for (int i = 0; i < 5; i++){
        printf("\033[3%dm\%s\n", i+1,f->field[i]);
    }
}

void insert_choice(field* f, char *choice){
    switch (choice[0])
    {
    case 'A':
        break;
    case 'B':
        break;
    default:
        printf("who is this???");
        break;
    }
}

int is_available(field* f, char *choice){
    if (f->field[atoi(&choice[0])][atoi(&choice[1])] != EMPTY){
        printf("not empty");
        return 1;
    }
    return 0;
}

int main(){
    field *ptrf = (field *)malloc(sizeof(field));
    init_field(ptrf);
    // for (int i = 0; i< 4; i++){
    //     print_field(ptrf);
    //     printf("\n%d", i);
    //     fflush(stdout);
    //     sleep(3);
    // }

    printf("%d\n", is_available(ptrf, "00"));

    return 0;
}