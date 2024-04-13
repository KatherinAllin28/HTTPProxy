#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <threads.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stddef.h>

int createSocket(char* ip, char* port, int queue);

int acceptConnection(int sockfd);

int connectSocket(char *ip, char *port);

void format_http_request(const char *input, char *output);

void selectServer(int clientfd, char* httpRequest);

int handleServer(void *args);

int close_server();