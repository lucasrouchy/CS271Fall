#ifndef __HACK_H__
#define __HACK_H__
#define NUM_PREDEFINED_SYMBOLS 23

// Exercice 1: Enum for predefined symbols
enum symbol_id {
  SYM_R0 = 0,
  SYM_R1 = 1,
  SYM_R2 = 2,
  SYM_R3 = 3,
  SYM_R4 = 4,
  SYM_R5 = 5,
  SYM_R6 = 6,
  SYM_R7 = 7,
  SYM_R8 = 8,
  SYM_R9 = 9,
  SYM_R10 = 10,
  SYM_R11 = 11,
  SYM_R12 = 12,
  SYM_R13 = 13,
  SYM_R14 = 14,
  SYM_R15 = 15,
  SYM_SCREEN = 16384,
  SYM_KBD = 24576,
  SYM_SP = 0,
  SYM_LCL = 1,
  SYM_ARG = 2,
  SYM_THIS = 3,
  SYM_THAT = 4,
};

// Exercice 2: Struct for a predefined symbol
typedef struct predefined_symbol {
  char name[10];
  int16_t address;
} predefined_symbol;

// Exercice 3: Array for predefined symbols
static const predefined_symbol predefined_symbols[NUM_PREDEFINED_SYMBOLS] = {
    {"R0", SYM_R0},
    {"R1", SYM_R1},
    {"R2", SYM_R2},
    {"R3", SYM_R3},
    {"R4", SYM_R4},
    {"R5", SYM_R5},
    {"R6", SYM_R6},
    {"R7", SYM_R7},
    {"R8", SYM_R8},
    {"R9", SYM_R9},
    {"R10", SYM_R10},
    {"R11", SYM_R11},
    {"R12", SYM_R12},
    {"R13", SYM_R13},
    {"R14", SYM_R14},
    {"R15", SYM_R15},
    {"SCREEN", SYM_SCREEN},
    {"KBD", SYM_KBD},
    {"SP", SYM_SP},
    {"LCL", SYM_LCL},
    {"ARG", SYM_ARG},
    {"THIS", SYM_THIS},
    {"THAT", SYM_THAT},
};
//Exercise 1 JumpId enum
enum jump_id {
  JMP_INVALID = -1,
  JMP_NULL = 0,
  JMP_JGT = 1,
  JMP_JEQ = 2,
  JMP_JGE = 3,
  JMP_JLT = 4,
  JMP_JNE = 5,
  JMP_JLE = 6,
  JMP_JMP = 7,

};
//Exercice 2 DestID
enum dest_id {
  DEST_INVALID = -1,
  DEST_NULL = 0,
  DEST_M = 1,
  DEST_D = 2,
  DEST_MD = 3,
  DEST_A = 4,
  DEST_AM = 5,
  DEST_AD = 6,
  DEST_AMD = 7,
};
//Exercise 3 CompID
enum comp_id {
  COMP_INVALID = -1,
  COMP_0 = 42,
  COMP_1 = 63,
  COMP_-1 = 58,
  COMP_D = 12,
  COMP_A = 48,
  COMP_!D = 13,
  COMP_!A = 49,
  COMP_-D = 15,
  COMP_-A = 51,
  COMP_D+1 = 31,
  COMP_A+1 = 55,
  COMP_D-1 = 14,
  COMP_A-1 = 50,
  COMP_D+A = 2,
  COMP_D-A = 19,
  COMP_A-D = 7,
  COMP_D&A = 0,
  COMP D|A = 21,
  COMP_M = 48,
  COMP_!M = 49,
  COMP_-M = 51,
  COMP_M+1 = 55,
  COMP_M-1 = 50,
  COMP_D+M = 2,
  COMP_D-M = 19,
  COMP_M-D = 7,
  COMP_D&M = 0,
  COMP_D|M = 21,

};
//Exercise 4 function
static inline jump_id str_to_jumpid(const char *s)

#endif
