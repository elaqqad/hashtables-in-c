#include "test.h"
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_LINES 30
#define SIZES   20,100,1000
#define N_KEYS  1000,10000,100000

int main( int argc, char **argv ) {
    int N[]={N_KEYS};
    int S[]={SIZES}; // The number of keys to insert in the hash_table
	srand(time(NULL));
	int i,j;
	clock_t start,stop;

	
	for (j=0;j<(int) (sizeof(N)/sizeof(int));j++){
        char  keys[N[j]][6];
        char  values[N[j]][11];
        hashtable *hash_table = create_hashtable(S[j]);
	    // here we start by genarting a random keys and values
        for(i=0;i<N[j];i++) rand_str(keys[i],5);
        for(i=0;i<N[j];i++) rand_str(values[i],10);       
        // insertion of key-value pairs in the hash_table
        printf("\n\n############################# The time test SIZE= %d #################################\n\n",S[j]);
        printf ("The opertion for the element number i :  Insertion \n");
         start=clock();
	    for(i=0;i<N[j];i++) {
                     insert_pair( hash_table, keys[i], values[i] );
                     stop=clock();
                     if (N[j]<=N_LINES||i%(N[j]/N_LINES)==0) printf("\tfor i=%d\t\t the insertion takes %f CPU clocks\n",i,(double) (stop-start)/(i+1));                       
        }  
        printf ("\nThe opertion for the element number i:  Looking up \n");
        start=clock();
   	    for(i=0;i<N[j];i++) {
                     get_value(hash_table, keys[i]);
                     stop=clock();
                     if (N[j]<=N_LINES||i%(N[j]/N_LINES)==0) printf("\tfor i=%d\t\t the looking up takes %f CPU clocks\n",i,(double) (stop-start)/(i+1));                      
        }                              
        free_hashtable(hash_table); 
    }
	return 0;
}
