#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "client.h"

// Fuente: https://www.geeksforgeeks.org/socket-programming-cc/

int main(int argc, char const *argv[])
{
    int socketFd = 0, client_fd;
    struct sockaddr_in serv_addr;

    char buffer[BUFFER_SIZE] = {0};
    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error\n");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "0.0.0.0", &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    if ((client_fd = connect(socketFd, (struct sockaddr *)&serv_addr,
                             sizeof(serv_addr))) < 0)
    {
        perror("Connection Failed \n");
        exit(EXIT_FAILURE);
    }
    int n;
    setvbuf(stdout, NULL, _IONBF, 0);
    do
    {
        printf("%s", "Ingrese la respuesta: ");
        n = read(0, buffer, BUFFER_SIZE);
        buffer[n] = '\0';
        if (send(socketFd, buffer, strlen(buffer), 0) == -1)
        {
            close(socketFd);
            return -1;
        }

    } while (n > 0);

    close(socketFd);
    return 0;
}