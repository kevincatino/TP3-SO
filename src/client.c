#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

// Fuente: https://www.geeksforgeeks.org/socket-programming-cc/
 
int main(int argc, char const* argv[])
{
    int socketFd = 0, length, client_fd;
    struct sockaddr_in serv_addr;

    char buffer[1024] = { 0 };
    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 

    if (inet_pton(AF_INET, "0.0.0.0", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
 
    if ((client_fd
         = connect(socketFd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(socketFd, "entendido\n",10 , 0);
    printf("Hello message sent\n");
    length = read(socketFd, buffer, 1024);
    printf("%s\n", buffer);
 

    close(client_fd);
    return 0;
}