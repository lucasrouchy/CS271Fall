#include "symtable.h"

// Exercice 3: Writing the hash function
int hash(char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % SYMBOL_TABLE_SIZE;
}
