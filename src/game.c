#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int pow(int n,int b){
    if (b==0){
        return 1;
    }
    return n*pow(n,b-1);
}

int stringtoint(char *arr,int pos,int index){
    if (pos==0){
        return 0;
    }

    return (arr[index]-48)*pow(10,pos-1)+stringtoint(arr,pos-1,index+1);
}

#define EMPTY ' '
#define ROW 5
#define COLUMN 5
#define ATOI_SINGLE(c) (stringtoint((char*) &c,1,0))
#define SELECT_BOX(f, row, column) (f->field[row][column])
#define SELECT_BOX_WITH_CHAR(f, c) (f->field[ATOI_SINGLE(c[1])][ATOI_SINGLE(c[2])])
#define TURNCHANGE(turn) turn = (turn + 1)%2
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
    for (int i = 0; i < ROW; i++){
        if (i%2==0){
            SELECT_BOX(f,i,0) = EMPTY;
            SELECT_BOX(f,i,1) = '|';
            SELECT_BOX(f,i,2) = EMPTY;
            SELECT_BOX(f,i,3) = '|';
            SELECT_BOX(f,i,4) = EMPTY;
            SELECT_BOX(f,i,5) = '\0';
        }else{
            SELECT_BOX(f,i,0) = '-';
            SELECT_BOX(f,i,1) = '-';
            SELECT_BOX(f,i,2) = '-';
            SELECT_BOX(f,i,3) = '-';
            SELECT_BOX(f,i,4) = '-';
            SELECT_BOX(f,i,5) = '\0';
        }
    }//i don't know man, i'm to stubborn tu use 2 for loops
}

void print_field(field* f){
    printf("\033[32m\033[H\033[2J");
    for (int i = 0; i < ROW; i++){
        printf("\033[3%dm\%s\n", i+1,f->field[i]);
    }
}

void insert_choice(field *f, char *choice){
    switch (choice[0])
    {
    case 'A':
        SELECT_BOX_WITH_CHAR(f, choice) = 'X';
        break;
    case 'B':
        SELECT_BOX_WITH_CHAR(f, choice) = 'O';
        break;
    default:
        printf("who is this???");
        break;
    }
}

int is_available(field* f, char *choice){
    if (SELECT_BOX_WITH_CHAR(f, choice) != EMPTY){
        printf("not empty\n");
        return 1;
    }
    return 0;
}

//choice 'PLAYERID(A or B)ROWCOLUMN[0,2,4][0,2,4])'
// int main(){
//     char *c = "B02";
//     field *ptrf = (field *)malloc(sizeof(field));
//     init_field(ptrf);
//     SELECT_BOX(ptrf,ATOI_SINGLE(c[1]),ATOI_SINGLE(c[2])) = 'X';
//     insert_choice(ptrf, c);
//     //SELECT_BOX_WITH_CHAR(ptrf, c) = 'O';
//     print_field(ptrf);
//     printf("%d\n%d\n", ATOI_SINGLE(c[1]), ATOI_SINGLE(c[2]));
//     return 0;
// }
