#include "proxy.h"

int main(int c, char** v)
{
    // creo el socket del proxy
    int proxyfd = createSocket(v[1], v[2], 1000); //When it is executed, you must enter in the console after ./proxy the server IP and the port (8080)

    thrd_t server;
    int res;

    thrd_create(&server, handleServer, 0);

    while (close_server()) {

        // Accepts a connection from the client
        int clientfd = acceptConnection(proxyfd);

        // Receives the client's info
        char buff[10000];
        recv(clientfd, buff, 10000, 0);

        // Translation of the buff
        char httpRequest[10000];
        format_http_request(buff, httpRequest);

        // Proxy
        selectServer(clientfd, httpRequest);
    }

    thrd_join(server, &res);

    close(proxyfd);
    
    return 0;
}