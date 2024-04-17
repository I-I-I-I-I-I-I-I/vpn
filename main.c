#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__linux__)
#include <netdb.h>
#include <netinet/in.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#elif defined(_WIN32)
#include <winsock2.h>
#include <ws2tcpip.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8080

int main(int argc, char *argv[]){

    int server_fd , new_socket;
    ssize_t valread;
    struct sockaddr_in address;
    int opt = 1;

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    int setsockopt(int sockfd, int level, int optname, const void *optval , socklen_t optlen);

    int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

    int listen(int sockfd , int backlog);

    int new_socket = accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

    char buffer[BUFFER_SIZE];
    struct icmp_header *icmp = (struct icmp_header *)buffer;
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->id = getpid();
    icmp->sequence = 1;

    sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));

    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &from, &fromlen);

    close(sockfd);
}