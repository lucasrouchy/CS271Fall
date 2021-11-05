//exercise 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>


#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH -2

char* strip(char* s);
void parse(FILE* file);
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);
typedef int16_t hack_addr;
typedef int16_t opcode;
char *extract_label(const char *line, char* label);
enum inst_type {
  invalid = -1,
  Atype,
  Ctype,
};
