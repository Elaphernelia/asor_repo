#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>


int main(int argc, char *argv[]){

    struct addrinfo* ain;
    struct addrinfo* res;
    struct sockaddr* sar;
    socklen_t len;
    int check;
    char buffer_1[1000];
    char buffer_2[100];

    check = getaddrinfo(argv[1], NULL, NULL, &res);

    if (check == 0){
        for (ain = res; ain != NULL; ain = ain->ai_next){

            sar = ain->ai_addr;
            len = ain->ai_addrlen;
            if (getnameinfo(sar, len, buffer_1, 1000, buffer_2, 100, NI_NUMERICHOST)==0){
                printf("%s    ", buffer_1); 
                printf("%d    ", ain->ai_family);
                printf("%d\n", ain->ai_socktype);
            }
            else{
                perror("ERROR\n");
            }
        }
    }


    return 0;
}