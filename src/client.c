#include "game.h"
#include "room.h"
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

int main() {
    int sockfd;
    char msg[BUFFER_MAX];
    struct sockaddr_in servaddr;
    char buffer[BUFFER_MAX];

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

    while (1){
        int n = recvfrom(sockfd, buffer, BUFFER_MAX, 0, NULL, NULL);
        buffer[n] = '\0';
        printf("Server: %s\n", buffer);
        fgets(msg, BUFFER_MAX, stdin);
        if (msg[0] == '-'){
            break;
        }
    }


    close(sockfd);

    return 0;
}