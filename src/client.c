#include "game.h"
#include "room.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_MAX 1024
#define PORT 1313
#define CHUNK (1024 * 1024)

int turn = 0;

int main() {
    int sockfd;
    char msg[BUFFER_MAX];
    struct sockaddr_in servaddr;
    char buffer[BUFFER_MAX];
    Arena game_arena = arena_alloc(CHUNK);
    //struct sockaddr_in *game_server = arena_push(&game_arena, sizeof(servaddr));
    //int *player_turn = arena_push(&game_arena, sizeof(int));
    // create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // send a message to the server
    snprintf(buffer, BUFFER_MAX, "Hello, server!");
    sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
    int len = sizeof(servaddr);
    while (1){
        struct sockaddr_in game_server;
        int n = recvfrom(sockfd, buffer, BUFFER_MAX, 0, (struct sockaddr *) &game_server, &len);
        buffer[n] = '\0';
        int player_turn = atoi(buffer);
        printf("player number: %d", player_turn);
        printf("\n");
        while (1){
            if (turn == player_turn){
                printf("insert move:");
                fgets(msg, BUFFER_MAX, stdin);
                sendto(sockfd, msg, BUFFER_MAX, 0, (struct sockaddr *) &game_server, sizeof(servaddr));
                TURN_CHANGE(turn);
                if (msg[0] == '-'){
                    break;
                }
            }else{
                recv(sockfd, buffer, BUFFER_MAX, 0);
                TURN_CHANGE(turn);
                printf("%s", buffer);
            }
        }
        break;
    }
    close(sockfd);

    return 0;
}