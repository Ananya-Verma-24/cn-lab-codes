#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#define SERV_TCP_PORT 6880
#define SERV_HOST_ADDR "127.0.0.1"

int main(){
    int sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char filename[100], buf[1000];
    int n;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    if((sockfd = socket(AF_INET, SOCK_STREAM,0)) <0)
        printf("Client: cant open stream socket\n");
    else
        printf("Client: stream socket opened successfully\n");

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        printf("Client: cant connect to server\n");
    else
        printf("Client: connected to server successfully\n");

        printf("\n Enter the filename to be displayed : ");
        scanf("%s", filename);
        write(sockfd, filename, strlen(filename));
        printf("\n filename transferred to server\n");
        n = read(sockfd, buf, 1000);

        if(n<0)
        printf("\n error reading from socket\n");

        printf("\n Client: Displaying file content of %s\n", filename);
        fputs(buf, stdout);
        close(sockfd);
        exit(0);
        return(0);
}