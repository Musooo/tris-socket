#include "../src/game.h"

int test_field(field f, char *choice, char *c2, char *c3){
    insert_choice(&f, choice);
    insert_choice(&f, c2);
    insert_choice(&f, c3);

    return game_winning(&f);
}

int main(){

    field *f =(field*) malloc(sizeof(field));
    init_field(f);

    int empty_test = game_winning(f);
    printf("should be 0: %d\n", empty_test);

    printf("first row: %d\n", test_field(*f,"A00","A02","A04"));
    printf("second row: %d\n", test_field(*f,"A20","A22","A24"));
    printf("third row: %d\n", test_field(*f,"A40","A42","A44"));

    printf("first column: %d\n", test_field(*f,"A00","A20","A40"));
    printf("second column: %d\n", test_field(*f,"A02","A22","A42"));
    printf("third column: %d\n", test_field(*f,"A04","A24","A44"));

    printf("first diagonal: %d\n", test_field(*f,"A00","A22","A44"));
    printf("second diagonal: %d\n", test_field(*f,"A04","A22","A40"));

    return 0;
}