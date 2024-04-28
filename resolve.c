#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    char hostname[256];

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    struct hostent *hen = gethostbyname(hostname); 

    if (hen != NULL) {
        printf("Hostname is %s\n", hen->h_name); 
        printf("IP address is %s\n", inet_ntoa(*((struct in_addr*)hen->h_addr))); 
    } else {
        fprintf(stderr, "Host not found\n"); 
        exit(1);
    }

    return 0;
}
