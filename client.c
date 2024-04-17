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

int main(int argc, char const* argv[])
{
    int status, valread , client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from clientSide";
    char buffer[1024] = { 0 };

    if((client_fd = socket(AF_INET , SOCK_STREAM , 0)) < 0)
        {
            printf("\n Socket creation error \n");
            return -1;
        }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    //Convert IPv4 and IPv6 addresses to their binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        {
            printf("\nInvalid address or Address not supported \n");
            return -1;
        }

    if ((status = connect(client_fd , (struct sockaddr*)&serv_addr, sizeof(serv_addr))))
        {
            printf("\nConnection Failed \n");
            return -1;
        }

    //Subtracting 1 for null terminator
    send(client_fd , hello , strlen(hello), 0);
    printf("Hello message sent\n");
    valread = read(client_fd , buffer , 1024 - 1);


}