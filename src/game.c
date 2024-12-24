#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
            f->field[i][0] = '0';
            f->field[i][1] = '|';
            f->field[i][2] = '0';
            f->field[i][3] = '|';
            f->field[i][4] = '0';
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
        printf("%s\n", f->field[i]);
    }
}

int main(){
    field *ptrf = (field *)malloc(sizeof(field));
    init_field(ptrf);
    for (int i = 0; i< 4; i++){
        printfield(ptrf);
        printf("\n%d", i);
        fflush(stdout);
        sleep(3);
    }
    return 0;
}