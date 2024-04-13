# Documentación del Proyecto: Proxy y Balanceador de Carga

Este documento proporciona una descripción detallada del proyecto de desarrollo de un Proxy y Balanceador de Carga utilizando sockets en el lenguaje de programación C, así como un cliente en Python para interactuar con el servidor proxy.

## Objetivo del Proyecto

El objetivo principal de este proyecto es desarrollar un sistema de proxy inverso para HTTP y un balanceador de carga utilizando sockets en el lenguaje de programación C. El proyecto tiene como finalidad principal proporcionar competencias en el diseño y desarrollo de aplicaciones concurrentes en red.

[Diagrama](https://github.com/LauZar12/HTTPProxy/assets/100243743/37489060-8a33-4a38-93a1-3835db8a5cc7)

## Recursos

Para llevar a cabo estas tareas, se realizarán acciones manuales que requerirán el uso de una máquina con cualquier sistema operativo, aunque se recomienda preferiblemente Linux, y una conexión a Internet. A continuación, detallamos los recursos específicos que se utilizarán:

- **Amazon EC2**: Este servicio de cómputo en la nube de Amazon Web Services (AWS) nos permitirá crear y gestionar instancias virtuales de servidores en la nube. Utilizaremos EC2 para desplegar y configurar nuestras aplicaciones y servicios en un entorno de nube flexible y escalable.

- **Linux - Ubuntu 20.04**: Se utilizará el sistema operativo Linux, específicamente la distribución Ubuntu 20.04, debido a su amplia compatibilidad y soporte comunitario. Ubuntu es una opción popular para entornos de servidor debido a su estabilidad, seguridad y facilidad de uso.

- **Apache**: Este será el servidor web que utilizaremos para alojar nuestras aplicaciones y servicios. Apache HTTP Server es uno de los servidores web más populares y ampliamente utilizados en el mundo. Proporciona una plataforma robusta y flexible para servir contenido web estático y dinámico.

## Estructura del Proyecto

El proyecto está organizado en varias funciones y componentes principales, cada uno cumpliendo un propósito específico en el funcionamiento del proxy y el balanceador de carga. A continuación, se describen los componentes principales del proyecto:

### Funciones del Servidor Proxy y Balanceador de Carga (`proxy.c`)

1. **createSocket**: Esta función inicializa el socket para el proxy utilizando la dirección IP y el puerto proporcionados en la línea de comandos. Utiliza IPv4 y TCP para la comunicación.
2. **acceptConnection**: Acepta conexiones entrantes de clientes utilizando la función `accept`. Gestiona posibles errores de conexión.
3. **connectSocket**: Similar a `createSocket`, pero utilizado para establecer conexiones salientes a otros servidores. Se utiliza para enrutar solicitudes a servidores internos.
4. **format_http_request**: Esta función formatea los datos recibidos en una solicitud HTTP apropiada para ser enviada a otro servidor. Incluye el manejo del encabezado 'Host'.
5. **selectServer**: Decide a qué servidor se debe enviar la solicitud, implementando la lógica del balanceo de carga.
6. **handleServer**: Un hilo de servidor que permite terminar el proxy mediante la entrada de la palabra 'quit'. Controla el ciclo principal del proxy.
7. **close_server**: Proporciona un mecanismo para verificar si se debe detener el servidor.

### Funciones del Cliente (`client.py`)

El cliente proporciona una interfaz simple para interactuar con el servidor proxy. La función principal `connect_and_send` crea un objeto socket, establece una conexión con el servidor utilizando la dirección IP y el puerto proporcionados, envía un mensaje al servidor y maneja posibles errores de conexión.

## Librerías Utilizadas

El proyecto hace uso de varias librerías estándar de C y algunas específicas para manejo de hilos, tipos de datos, sockets y estructuras de red, incluyendo:

- `<stdio.h>` para funciones de entrada/salida.
- `<stdint.h>` y `<string.h>` para tipos de datos y manipulación de strings.
- `<threads.h>` para manejo de hilos.
- `<sys/types.h>`, `<sys/socket.h>` y `<netdb.h>` para definiciones relacionadas con sockets y redes.

## Archivos Relevantes

- `serverskey.pem`: Este archivo contiene una clave privada utilizada para la autenticación o cifrado en las conexiones de red. Es comúnmente utilizado en configuraciones SSL/TLS para asegurar las comunicaciones entre el cliente y el servidor o entre balanceadores de carga y servidores.

## Conclusiones

En el transcurso de este proyecto, se han abordado diversos aspectos relacionados con los servicios y aplicaciones de Internet, centrándonos en el despliegue de una infraestructura web utilizando Amazon EC2, el sistema operativo Ubuntu 20.04 y el servidor web Apache. A continuación, se presentan las conclusiones principales obtenidas durante este proceso:

1. **Flexibilidad y escalabilidad**: El uso de Amazon EC2 ha demostrado ser una elección acertada debido a su capacidad para escalar vertical y horizontalmente según las necesidades de la aplicación. Esto nos ha permitido adaptar fácilmente nuestros recursos de cómputo a medida que crece la demanda de nuestros servicios.
2. **Estabilidad y confiabilidad**: La elección de Ubuntu 20.04 como sistema operativo ha proporcionado un entorno estable y confiable para el despliegue de nuestras aplicaciones. La amplia compatibilidad y el sólido soporte comunitario de Ubuntu han facilitado el proceso de configuración y mantenimiento de nuestros servidores.
3. **Robustez y rendimiento**: Apache ha demostrado ser un servidor web robusto y eficiente para alojar nuestras aplicaciones. Su amplia gama de características y su capacidad para manejar cargas de trabajo intensivas nos han permitido ofrecer un servicio de alta calidad a nuestros usuarios.

En resumen, la combinación de Amazon EC2, Ubuntu 20.04 y Apache ha resultado ser una solución efectiva y poderosa para el despliegue de aplicaciones web en un entorno de nube. Estas tecnologías nos han proporcionado las herramientas necesarias para crear una infraestructura web flexible, estable y de alto rendimiento, capaz de satisfacer las demandas de lo que requería nuestro proyecto.

## Referencias

- RFC 7230 - Hypertext Transfer Protocol (HTTP/1.1): Message Syntax and Routing
- GeeksforGeeks - TCP Server-Client Implementation in C
- Beej's Guide to C Programming
- Beej's Guide to Network Programming
- YouTube - Computer Networking Tutorial for Beginners
- YouTube - HTTP Tutorial for Beginners

Estos recursos han sido útiles para comprender y aplicar conceptos relacionados con la implementación de servicios y aplicaciones de Internet, así como para profundizar en el funcionamiento de protocolos como HTTP y TCP/IP para efectos de nuestro


## Integrantes
- Nicolas Moreno Lopez
- Katherin Nathalia Allin Murillo
- Laura Danniela Zárate Guerrero
