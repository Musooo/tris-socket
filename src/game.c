#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define EMPTY ' '
#define ROW 5
#define COLUMN 5
#define SELECT_BOX(f, row, column) (f->field[row][column])
#define SELECT_BOX_WITH_CHAR(f, choice) (f->field[atoi(&choice[1])][atoi(&choice[2])])
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
        SELECT_BOX_WITH_CHAR(f, choice);
        break;
    case 'B':
        break;
    default:
        printf("who is this???");
        break;
    }
}

int is_available(field* f, char *choice){
    if (SELECT_BOX_WITH_CHAR(f, choice) != EMPTY){
        printf("not empty");
        return 1;
    }
    return 0;
}

//choice 'PLAYERID(A or B)ROWCOLUMN[1,3,5][1,3,5])'
int main(){
    field *ptrf = (field *)malloc(sizeof(field));
    init_field(ptrf);

    printf("%d\n", is_available(ptrf, "00"));

    return 0;
}