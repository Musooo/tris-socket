#ifndef ROOM_H
#define ROOM_H

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define MAX_PLAYER 2

typedef struct {
    struct sockaddr_in players[MAX_PLAYER];
    int full;
    int room_number; //idk maybe will see
}room;

void add_player(room *r, struct sockaddr_in p);
void empty_room(room *r);

#endif