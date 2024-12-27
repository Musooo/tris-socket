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

//choice 'PLAYERID(A or B)ROWCOLUMN[0,2,4][0,2,4])'
int main(){
    char *c = "A02";
    field *ptrf = (field *)malloc(sizeof(field));
    init_field(ptrf);
    SELECT_BOX(ptrf,atoi(&c[1]),atoi(&c[2])) = 'X';
    //SELECT_BOX_WITH_CHAR(ptrf, c) = 'O';
    print_field(ptrf);
    printf("%c\n%c\n", c[1], c[2]);
    printf("%d\n%d\n", stringtoint((char*) &c[1],1,0),stringtoint((char*) &c[2],1,0));
    return 0;
}