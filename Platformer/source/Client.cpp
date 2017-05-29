#include "Client.h"

#define error(msg) { \
    perror(msg); \
    return 1; \
}

int saveOnServer(const char * name, int portno, const char * data) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    server = gethostbyname(name);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return 1;
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    bzero(buffer,256);
    strcpy(buffer, data);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) {
         error("ERROR writing to socket");
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
         error("ERROR reading from socket");
    }
    printf("%s\n",buffer);
    close(sockfd);
    return 0;
}
