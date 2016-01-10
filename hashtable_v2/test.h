#ifndef TEST_H
#define TEST_H
#include "hashtable.h"

void number_collision_update(int h,int *collisions);
int max_collisions (int *collision,int len);
void rand_str(char *dest, int length);
int* get_time();
#endif
