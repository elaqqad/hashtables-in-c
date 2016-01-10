#include "hashtable.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_KEYS 5
#define SIZE 6
#define KEYS "key1","key2","key3","key4","key5"
#define VALUES "12","15","20","18","16"


int main( int argc, char **argv ) {
    int i;
    int N=NUMBER_KEYS;  // The number of keys to insert in the hash_table
    char* keys[NUMBER_KEYS]={KEYS};
    char*  values[NUMBER_KEYS]={VALUES};
	hashtable *hash_table = create_hashtable(SIZE); //The size of the hash_table
	srand(time(NULL));
	
	
	// here we start by genarting a random keys and values
	printf("############ Initialisation of keys #########################\n\n");
    for(i=0;i<N;i++) {
                     printf("keys[%d]==\"%s\" with hash %d\n",i,keys[i],hash(keys[i])%SIZE);
                     }              
    printf("\n############ Initialisation of values #####################\n\n");
    for(i=0;i<N;i++) {
                     printf("values[%d]==\"%s\"\n",i,values[i]);
                     }
                     
                    
                    
                     
    // insertion of key-value pairs in the hash_table
    printf("\n############ Insertion of (key,value) pairs ###############\n\n");
	for(i=0;i<N;i++) {
                     insert_pair( hash_table, keys[i], values[i] );
                     printf("Insertion of (\"%s\",\"%s\") succed \n",keys [i],values[i]);
                     }
    printf("Our hash table =   ");
    print_hashtable(hash_table); 
    
    
    
     // reinsertion of some pairs in the hash_table
    printf("\n############   Reinsertion of some pairs  #################\n\n");
    insert_pair( hash_table, keys[1], "19" );
    printf("Reinsertion of (\"%s\",\"%s\") succed \n",keys [1],"19");
    insert_pair( hash_table, keys[2], "13" );
    printf("Reinsertion of (\"%s\",\"%s\") succed \n",keys [2],"13");
    printf("the hash table =   ");
    print_hashtable(hash_table);
    
    
                    
    // getting the values of a given key  
    printf("\n############ Getting the value for a given key ############\n\n");                  
	for(i=0;i<N;i++) printf("hash_table of \"%s\" gives \"%s\"\n",keys[i], get_value( hash_table, keys[i]));
	
	
	// removing the some keys from the hash table
    printf("\n############ Removing some keys from hash table ###########\n\n");
    printf("Initialy we have\n");
    print_hashtable(hash_table);                 
	for(i=0;2*i<N;i++) {
                     delate_key( hash_table, keys[2*i]);
                     printf("we delate the key \"%s\"\n",keys[2*i]);
                     print_hashtable(hash_table);
                     }
                     
    printf("\n#### After free we  print the hash_table  to verify  #####\n\n");
    free_hashtable(hash_table); 
    print_hashtable(hash_table);
	return 0;
}
