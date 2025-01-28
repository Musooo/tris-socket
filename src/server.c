#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "room.h"
#include "game.h"
#define BUFFER_MAX 1024
#define PORT 1313

int players = 0;
int rooms = 0;

void* game_t(void *ptr){
    int sockfd;
    int turn = 0; 
    struct sockaddr_in servaddr; 
    
    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_family = AF_INET; 
    char buffer[BUFFER_MAX];
    // create datagram socket 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 

    room *r = (room*)ptr;
    for (int i = 0; i < MAX_PLAYER; i++){
        snprintf(buffer, BUFFER_MAX, "%d", i);
        sendto(sockfd, buffer, BUFFER_MAX, 0, (struct sockaddr*)&r->players[i], sizeof(struct sockaddr));
    }

    while (1){
        //receive the msg from the player
        //send it to the other, if the message is a stop message stop
        recv(sockfd, buffer, BUFFER_MAX, 0); //TODO after n time you send a concede msg
        printf("received: %s \n", buffer);
        TURN_CHANGE(turn);
        sendto(sockfd, buffer, BUFFER_MAX, 0, (struct sockaddr*)&r->players[turn], sizeof(struct sockaddr));
        // if (strcmp(buffer, QUIT)){
        //     free(r);
        //     printf("closed room");
        //     close(sockfd);
        //     break;
        // }
    }
    free(r);
}

int main(){
    int sockfd, n;
    pthread_t game_thread_id;
    struct sockaddr_in serveraddr,client;
    char buffer[1024];
    room *tmproom = malloc(sizeof(room));

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    int len = sizeof(client);
    while(1){
        n = recvfrom(sockfd, buffer, sizeof(buffer)-1,0,(struct sockaddr*)&client,&len);
        buffer[n] = '\0'; //i could put 0 and not buffer
        
        add_player(tmproom, client);
        if (tmproom->full == 2){
            room *new_room = tmproom; // Assign the current room to a new variable
            tmproom = malloc(sizeof(room)); // Allocate a new room for the next game
            if (tmproom == NULL) {
                perror("Failed to allocate memory for tmproom");
                exit(EXIT_FAILURE);
            }
            empty_room(tmproom); // Initialize the new room

            pthread_create(&game_thread_id, NULL, game_t, (void *)new_room);
        }
    }

    close(sockfd);
    free(tmproom);
    return 0;
}