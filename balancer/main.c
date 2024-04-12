#include "proxy.h"

int main()
{
    // creo el socket del proxy
    int proxyfd = createSocket("54.89.247.175", "80", 1000);

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
    
    return 0;
}