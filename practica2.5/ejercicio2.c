#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <netdb.h>
#include <locale.h>
#include <string.h>

#define NI_MAXHOST 1025
#define NI_MAXSERV 32

int main(int argc, char *argv[]){
    struct addrinfo hints;
    struct addrinfo* result;
    char buf[100];
    

    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_flags    = AI_PASSIVE;
    hints.ai_family   = AF_UNSPEC;  
    hints.ai_socktype = SOCK_DGRAM;

    if (getaddrinfo(argv[1], argv[2], &hints, &result) !=0){
        perror("ERROR\n");
    }

    int sd = socket(result->ai_family, result->ai_socktype, 0);

    if (sd == -1){
        perror("ERROR SOCKET\n");
    }

    if (bind(sd, result->ai_addr, result->ai_addrlen)!=0){
        perror("ERROR BIND\n");
    }

    while (1) {
        char host[NI_MAXHOST]; //constantes ya dadas
        char serv[NI_MAXSERV];

        struct sockaddr_storage client_addr;
        socklen_t client_addrlen = sizeof(client_addr);

        int c = recvfrom(sd, buf, 100, 0, (struct sockaddr *) &client_addr, &client_addrlen);
        buf[c] = '\0';
        if (getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST,
            serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV)!=0){
                perror("ERROR GETNAMEINFO\n");
            }

        printf("Mensaje de %s:%s\n", host, serv);


        //sacar la hora
        time_t tim;
        struct tm *localtim;
        size_t bytes;
        setlocale(LC_ALL, "es_ES");
        if(time(&tim) != (time_t)-1){
            localtim = localtime(&tim);
            if (localtim == NULL){
                perror("ERROR TIME\n");
            }
        }
        //
        switch(buf[0]){
            case 't': 
            bytes = strftime(buf, sizeof(buf), "%I:%M:%S %p", localtim);
			sendto(sd, buf, bytes, 0, (struct sockaddr *) &client_addr, client_addrlen);
            break;

            case 'd': 
            bytes = strftime(buf, sizeof(buf), "%Y-%m-%d", localtim);
            sendto(sd, buf, bytes, 0, (struct sockaddr *) &client_addr, client_addrlen);
            break;

            case 'q': 
            printf("Saliendo...\n");
            exit(0);
            break;

            default: printf("Comando no soportado %d \n", buf[0]);
            break;
        }

    }
    if(close(sd) == -1){
        perror("ERROR CLOSE");
    }

    return 0;
}