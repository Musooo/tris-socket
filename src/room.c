#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


typedef struct {
    struct sockaddr_in players[2];
    int full;
    int room_number; //idk maybe will see
}room;