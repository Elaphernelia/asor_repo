 #include <stdio.h>
 #include <unistd.h>
 #include <sys/time.h>

 int main(int argc, char *argv[]){
     struct timeval tv;
     struct timeval tv_;
     struct timezone tz;
     if (gettimeofday(&tv, &tz) == 0){
     int t1 = tv.tv_usec;
     int c = 0;
     int i = 0;
     for (i; i < 1000000; i++){
         c++;
     } 
     if (gettimeofday(&tv_, &tz) == 0){
         int t2 = tv_.tv_usec;
         printf("%d \n", t2 - t1 );
     }
     }
     
     return 1;
 }
