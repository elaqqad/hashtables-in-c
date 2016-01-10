#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_str(char *dest, int length)  {
   char charset[] = "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    while (length-- > 0) {
        size_t index = (double) rand() /RAND_MAX *(sizeof charset -1 );
        *dest++ = charset[index];
    }
    *dest = '\0';
}

void number_collision_update(int h,int *collisions){
    collisions[h]++;
}

int max_collisions (int *collisions,int len){
    int i;
    int max=0;
    for (i=0;i<len;i++){
        if (collisions[i]>=max) max=collisions[i];
    }
   return max;     
}
int* get_time()
{ int*p;
  p= malloc(sizeof(int)*2);
  struct timespec ts = { 0 };
  clock_gettime(CLOCK_REALTIME, &ts);
  p[0]=ts.tv_sec;
  p[1]=ts.tv_sec;
  return p;
}
