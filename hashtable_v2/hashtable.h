#ifndef HASHTABLE_H
#define HASHTABLE_H 1

typedef struct entry {
	char *key;
	char *value;
	struct entry *next;
} entry;


typedef struct hashtable {
	int size;
	struct entry **table;	
} hashtable;

hashtable *create_hashtable (int size);
hashtable *new_hashtable ();
int        hash (char *key );
entry     *create_entry ( char *key, char *value );
void       insert_pair ( hashtable *hash_table, char *key, char *value );
char      *get_value (hashtable *hash_table, char *key);
int        delate_key (hashtable *hash_table,  char *key);
void       free_hashtable(hashtable *hash_table);
void       print_hashtable(hashtable *hash_table);
hashtable *resize_hashtable(hashtable *hash_table);
int        cases_full(hashtable *hash_table); 
void       insert_resize_pair( hashtable **hash_table, char *key, char *value ); 
#endif
