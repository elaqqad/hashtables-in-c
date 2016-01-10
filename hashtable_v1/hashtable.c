#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
/* function to create a new hashtable. */
hashtable *create_hashtable( int size ) {
 
	hashtable *hash_table= NULL;
	int i;
 
	if( size < 1 ) return NULL;
 
	/* allocate the hash_table itself. */
	hash_table = malloc( sizeof(hashtable) ) ;
	if( hash_table == NULL ) {
        fprintf(stderr,"erreur %d in malloc :allocation of hastable\n",errno);
		return NULL;
	}
 
	/* allocate pointers to the head nodes. */
	hash_table->table = malloc( sizeof( entry * ) * size );
	if( ( hash_table->table ) == NULL ) {
        fprintf(stderr,"erreur %d in malloc :allocation of a table of entries\n",errno);
		return NULL;
	}
	
	for( i = 0; i < size; i++ ) {
		hash_table->table[i] = NULL;
	}
 
	hash_table->size = size;
 
	return hash_table;	
}
 
/* hash a string key using the hash function of Dan Bernstein. */
int hash( char *key ) {
 
    unsigned long hashval = 5381;
    int i,len=strlen(key);

   for(i = 0; i < len; key++, i++)
   {   
      hashval = ((hashval << 5) + hashval) + (*key);
   }

    return hashval;
}
 
/* Create a key-value entry given key and value. */
entry *create_entry( char *key, char *value ) {
	entry *pair;
	
	
    pair = malloc( sizeof( entry ));
	if(  pair == NULL ) {
        fprintf(stderr,"erreur %d in malloc :allocation of an antry\n",errno);
		return NULL;
	}
	
    pair->key = strdup( key );
    
	if( pair->key == NULL ) {
        fprintf(stderr,"erreur %d in strdup:allocation of an string and copying\n",errno);
		return NULL;
	}
    
    pair->value = strdup( value );
	if( pair->value== NULL ) {
        fprintf(stderr,"erreur %d in strdup:allocation of an string and copying\n",errno);
		return NULL;
	}
 
	pair->next = NULL;
 
	return pair;
}
 
/* insert a key-value pair into a hash table. */
void insert_pair( hashtable *hash_table, char *key, char *value ) {
	int bin = 0;
	entry *pair = NULL;
	entry *next = NULL;
	entry *last = NULL;
    
	bin = hash(key )%hash_table->size;
    
 
	next = hash_table->table[ bin ];
  /* in this boucle we serch the place we want to pose the new entry */
	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}
 
	/* if there's already an existing key we replace its value by the newest value. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {
       
		free( next->value );
		next->value = strdup( value );
 
	/* no , could't find it. here we have to insert a pair in the linked list 
     *three cases : in the start,end or the middle of the linked list. */
	} else {
		pair = create_entry( key, value );
 
		/* we're at the start of the linked list in this bin. */
		if( next == hash_table->table[ bin ] ) {
			pair->next = next;
			hash_table->table[ bin ] = pair;
	
		/* we're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = pair;
	
		/* we're in the middle of the list. */
		} else  {
			pair->next = next;
			last->next = pair;
		}
	}
}
 
/* retrieve a key-value pair from a hash table. */
char *get_value( hashtable *hash_table, char *key ) {
	int bin = 0;
	entry *pair;
 
	bin = hash(key)%hash_table->size;
 
	/* step through the bin, looking for our value. */
	pair = hash_table->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) >0 ) {
		pair = pair->next;
	}
 
	/* Did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;
 
	} else {
		return pair->value;
	}	
}

/* delate a key_value pair from a hash table gicen the key*/
int delate_key (hashtable *hash_table,  char *key) {
    int bin = 0;
	entry *pair,*start;
 
	bin = hash(key)%hash_table->size;
	/* step through the bin, looking for the key */
	pair = hash_table->table[ bin ];
	start = pair;
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
        start = pair;
		pair = pair->next;
	}
 
	/* did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return 0;
 
	} else {
           if (start==pair ){
              hash_table->table[bin]=pair->next;
           }
          else{
              start->next = pair->next;
          }
		free(pair->key);
		free(pair->value);
		free(pair);
		return 1;
	}	
}
  
void free_hashtable(hashtable *hash_table)
{
    int i;
    entry *list, *temp;

    if (hash_table==NULL) return;

    /* free the memory for every item in the table, including the 
     * keys and values themselves.*/
    for(i=0; i<hash_table->size; i++) {
        list = hash_table->table[i];
        while(list!=NULL) {
            temp = list;
            list = list->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    /* Free the table itself */
    free(hash_table->table);
    free(hash_table);
}         

void print_hashtable(hashtable *hash_table)
{
    int i;
    entry *list;

    if (hash_table==NULL) return;

    /* we affiche for every item in the table and for every item in the linked list 
     * the value_key .
     */
    printf("{");
    for(i=0; i<hash_table->size; i++) {
        list = hash_table->table[i];
        while(list!=NULL) {
            printf ("\"%s\" : \"%s\"   ",list->key,list->value);
            list = list->next;
        }  
    }
    printf("}\n");

}
