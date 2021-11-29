#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include "hack.h"

// All code in file
#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH -2
#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS

void add_predefined_symbols(void);
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

typedef struct
c_instruction {
  opcode a: 1;
  opcode comp: 6;
  opcode dest:3;
  opcode jump: 3;
} c_instruction;

typedef struct a_instruction {
  union hack_addr {
      hack_addr address;
      char * label;
  } hack_addr;
  bool is_addr;
} a_instruction;

typedef struct instruction {
  union AorC {
    enum inst_type Atype;
    enum inst_type Ctype;
  } AorC;
} instruction;

bool parse_A_instruction(const char *line, a_instruction *instr);
#endif
