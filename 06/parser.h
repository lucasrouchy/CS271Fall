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
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);
typedef int16_t hack_addr;
typedef int16_t opcode;
char *extract_label(const char *line, char* label);

typedef enum instr_type {
  INST_I = -1,
  INST_A,
  INST_C,
} instr_type;

typedef struct {
  opcode a: 1;
  opcode comp: 7;
  opcode dest: 4;
  opcode jump: 4;
} c_instruction;

typedef struct {
  union hack_addr {
      hack_addr address;
      char * label;
  } hack_addr;
  bool is_addr;
} a_instruction;

typedef struct instruction {
  union {
    a_instruction a;
    c_instruction c;
  } instr;
  instr_type itype;
} instruction;

bool parse_A_instruction(const char *line, a_instruction *instr);
void parse_C_instruction(char *line, c_instruction *instr);
int parse(FILE* file, instruction* instructions);
void assemble(const char * file_name, instruction* instructions, int num_instructions);
#endif
