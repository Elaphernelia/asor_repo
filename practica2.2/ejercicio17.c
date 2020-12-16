#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){
    DIR *direct_; 
    struct dirent *puntoentrada;
    struct stat st;
    off_t size = 0;
    direct_ = opendir(argv[1]);
    if (direct_ != NULL){
        while(puntoentrada = readdir(direct_)){
            
            if (puntoentrada->d_type == DT_REG){
                
                if (access(puntoentrada->d_name, F_OK|X_OK) == 0){
                    char nombre[50];
                    strcpy(nombre, puntoentrada->d_name);
                    strcat(nombre, "*");
                    printf("%s \n", nombre);
                }
                else{
                    printf("%s \n", puntoentrada->d_name);
                }
                stat(puntoentrada->d_name, &st);
                size = size + st.st_size;
            }

            else if(puntoentrada->d_type == DT_DIR){
                char nombre[50];
                strcpy(nombre, puntoentrada->d_name);
                strcat(nombre, "/");
                printf("%s \n", nombre);
            }
            else if (puntoentrada->d_type == DT_LNK){
                char nombre[50];
                char nombre_cont[50];
                strcpy(nombre, puntoentrada->d_name);
                strcat(nombre, "->");
                if (readlink(puntoentrada->d_name, nombre_cont, 50) == -1){perror("ERROR.");}
                strcat(nombre, nombre_cont);
                printf("%s \n", nombre);
            }
            
        }
        printf("Byte file size: %d \n", size);
    }
        
    if (closedir(direct_) == -1){ perror("ERROR.");} 
    return 0;
}