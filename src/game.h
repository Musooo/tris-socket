#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int pow_mine(int n,int b);
int stringtoint(char *arr,int pos,int index);

#define EMPTY ' '
#define QUIT "quit"
#define ROW 5
#define COLUMN 5
#define ATOI_SINGLE(c) (stringtoint((char*) &c,1,0))
#define SELECT_BOX(f, row, column) (f->field[row][column])
#define SELECT_BOX_WITH_CHAR(f, c) (f->field[ATOI_SINGLE(c[1])][ATOI_SINGLE(c[2])])
#define TURN_CHANGE(turn) turn = (turn + 1)%2

typedef struct {
    char field[5][6];
}field;

void init_field(field* f);
void print_field(field* f);
void insert_choice(field *f, char *choice);
int is_available(field* f, char *choice);
int game_winning(field* f);

#endif