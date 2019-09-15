#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int cli_args_length, char *cli_args[]) {
    int client_socket, port, response;

    struct sockaddr_in serv_addr;
    struct hostent *host;
    char buffer[1024];

    if (cli_args_length < 3) {
        fprintf(stderr, "provide a hostname and a port\n");
        exit(0);
    }

    port = atoi(cli_args[2]);
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0)
        error("ERROR: couldn't open the socket\n");

    host = gethostbyname(cli_args[1]);

    if (host == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(0);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)host->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          host->h_length);

    serv_addr.sin_port = htons(port);

    if (connect(client_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR: couldn't establish a connection with the provided address\n");

    bzero(buffer, 1024);

    response = write(client_socket, "GET / HTTP/1.1\r\n\r\n", strlen("GET / HTTP/1.1\r\n\r\n"));

    if (response < 0)
        error("ERROR writing to socket");

    response = read(client_socket, buffer, 1023);

    printf("%s\n", buffer);
    return 0;
}