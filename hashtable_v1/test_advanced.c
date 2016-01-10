#include "test.h"
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_LINES 30
#define SIZES   20,100,1000
#define N_KEYS  100,500,5000

int main( int argc, char **argv ) {
    int N[]={N_KEYS};
    int S[]={SIZES}; // The number of keys to insert in the hash_table
	srand(time(NULL));
	int hash_temp,i,j;
	for (j=0;j<(int)(sizeof(N)/sizeof(int));j++){
        char  keys[N[j]][6];
        char  values[N[j]][11];
        int*   collisions=(int*) calloc(S[j],sizeof(int));
        hashtable *hash_table = create_hashtable(S[j]);
	    // here we start by genarting a random keys and values
        for(i=0;i<N[j];i++) rand_str(keys[i],5);
        for(i=0;i<N[j];i++) rand_str(values[i],10);       
        // insertion of key-value pairs in the hash_table
        printf("\n\n############################# The insertion test SIZE= %d ######################################\n\n",S[j]);
        printf ("N. of insertions\t  N. of hash used\t max N. of collisions\t  Memory used\t  SIZE of hash_table \n");
	    for(i=0;i<N[j];i++) {
                     hash_temp=hash(keys[i])%S[j];
                     insert_pair( hash_table, keys[i], values[i] );
                     number_collision_update(hash_temp,collisions);
                     if (N[j]<=N_LINES||i%(N[j]/N_LINES)==0) printf("\t%d\t\t\t %d \t\t\t %d \t\t\t %d%% \t\t %d\n",i,cases_full(hash_table),\
                      max_collisions(collisions,S[j])-1,(int)100*cases_full(hash_table)/S[j],hash_table->size);             
        }                              
        free_hashtable(hash_table); 
    }
	return 0;
}
