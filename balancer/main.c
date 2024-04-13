#include "proxy.h"

int main(int c, char** v)
{
    // creo el socket del proxy
    int proxyfd = createSocket(v[1], v[2], 1000); //cuando se ejecute, hay que poner en consola despues del ./proxy el ip del servidor y el puerto (8080)

    thrd_t server;
    int res;

    thrd_create(&server, handleServer, 0);

    while (close_server()) {

        // acepto una coneccion del cliente
        int clientfd = acceptConnection(proxyfd);

        // recivo la info del cliente
        char buff[10000];
        recv(clientfd, buff, 10000, 0);

        // traduccion del buff
        char httpRequest[10000];
        format_http_request(buff, httpRequest);

        // proxy
        selectServer(clientfd, httpRequest);
    }

    thrd_join(server, &res);

    close(proxyfd);
    
    return 0;
}