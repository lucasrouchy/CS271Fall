#include "symtable.h"

// Exercice 3: Writing the hash function
int hash(char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % SYMBOL_TABLE_SIZE;
}
//Exercice 4
void insert(char* key, hack_addr addr) {
    Symbol* item = (Symbol*) malloc(sizeof(Symbol));
    item->address = addr;
    item->name = key;

    int hashIndex = hash(key);


    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {

        ++hashIndex;
        hashIndex %= SYMBOL_TABLE_SIZE;
   }

   hashArray[hashIndex] = item;
}
//Exercice 5
Symbol* find(char* key) {
    int hashIndex = hash(key);

    while(hashArray[hashIndex] != NULL) {
      if(hashArray[hashIndex]->name == key)
          return hashArray[hashIndex];

      ++hashIndex;

      hashIndex %= SYMBOL_TABLE_SIZE;
    }

    return NULL;
}
