#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    int p_h[2];
    int h_p[2];
    int cont = 0;
    //write-> [1] read-> [0]

    pipe(p_h);//padre-hijo
    pipe(h_p);//hijo-padre

    pid_t pid = fork(); 

    if (pid < 0){
    printf("Error fork\n");
    exit(1);
    }

    else if(pid == 0){
        //close(p_h[1]);
        close(h_p[0]);
        char leido[20];
        int cantidad = 0;
        while(cont < 10){
            cantidad = read(p_h[0], &leido, 20);
            if (cantidad > 0){
                printf("Leido mensaje %s \n", leido);
                wait(1);
                if (cont == 9){
                    write(h_p[1], "q", 1);
                }
                else{
                    write(h_p[1], "l", 1);
                }
                
                cont = cont + 1;
            }

        }
    }

    else{
        close(p_h[0]);
        close(h_p[1]);
        char letra[1];
        int cantidad = 0;
        char mensaje[20];
        while(1 < 2){
            printf("Escribe mensaje: ");
            scanf("%s", &mensaje); 
            write(p_h[1], mensaje, 20);

            cantidad = read(h_p[0], letra, 1);
            if (cantidad > 0){
                if (letra[0] == 'q'){
                    break;
                }
                else if (letra[0] == 'l'){
                    //printf("l recibidia \n");
                }
                else{
                    perror("error!");
                    break;
                }
            }
        }
        

    }

    return 0;
}