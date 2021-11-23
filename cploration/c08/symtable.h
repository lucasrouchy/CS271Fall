#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>


// All code in file



#define SYMBOL_TABLE_SIZE   100

typedef int16_t hack_addr;
//Exercise 2
typedef struct {
    hack_addr address;
    char* name;
} Symbol;

Symbol* hashArray[SYMBOL_TABLE_SIZE];
int hash(char* str);
Symbol* symtable_find(char* key);
void symtable_insert(char* key, hack_addr addr);
void symtable_display_table(void);
#endif
