#include "parser.h"
#include "error.h"
#include "symtable.h"

// exercice 4
void parse(FILE* file) {
    char line[MAX_LINE_LENGTH] = {0};
    int line_num = 0;
    int instr_num = 0;
    a_instruction instr;

    add_predefined_symbols();
    symtable_display_table();

    while(fgets(line, sizeof(line), file)) {
        line_num++;
        if(instr_num > MAX_INSTRUCTIONS){
          exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
        }
        strip(line);

        if(!*line)
            continue;
        char inst_type = {0};
        if (is_Atype(line)) {

          if (!parse_A_instruction(line, &instr)){
            exit_program(EXIT_INVALID_A_INSTR, line_num, line);
          }
          inst_type = 'A';
        }
        else if (is_label(line)){
          inst_type= 'L';
          char new_label[sizeof(line)] = {0};
          extract_label(line,new_label);
          if(isalpha(line[0])){
            exit_program(EXIT_INVALID_LABEL, line_num, line);
          }
          if(symtable_find(new_label) != NULL) {
            exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
          }
          symtable_insert(new_label, instr_num);
          continue;
          printf("%c  %s\n",inst_type, new_label );
          continue;
        }
        else if(is_Ctype(line)){
          inst_type = 'C';
        }
        printf("%c  %s\n",inst_type ,   line);
        instr_num++;

    }
}


char* strip(char* s) {
    char s_new[MAX_LINE_LENGTH + 1] = {0};
    int i = 0;

    for(char* s2 = s; *s2; s2++) {
        // ignore comments
        if(*s2 == '/' && *(s2+1) == '/') {
            break;
        }
        // ignore whitespace
        else if(!isspace(*s2)) {
            s_new[i++] = *s2;
        }
    }
    s_new[i]= '\0';
    strcpy(s, s_new);

    return s;
}
bool is_Atype(const char* line) {
  if (*line== '@' ){
    return true;
  }
  else  {
    return false;
  }
}
bool is_label(const char* line){
  if (line[0]== '(' &&  line[strlen(line)-1]==')')
    return true;
  else
    return false;
}
bool is_Ctype(const char* line){
  if (!is_Atype(line) && !is_label(line))
    return true;
  else
    return false;
}
char* extract_label(const char* line, char* label){
  strncpy(label, line+1, strlen(line)-2);
  return label;
}


void add_predefined_symbols(void){
  for(int i = 0; i < NUM_PREDEFINED_SYMBOLS; i++) {
    predefined_symbol myvar = predefined_symbols[i];
    symtable_insert(myvar.name, myvar.address);
  }
}


bool parse_A_instruction(const char *line, a_instruction *instr){
  char* s = malloc(strlen(line));
  strcpy(s, line+1);
  char* s_end = NULL;
  long result = strtol(s, &s_end, 10);
  if (strcmp(s, s_end) == 0){
    instr->hack_addr.label = malloc(strlen(line));
    strcpy(instr->hack_addr.label, s);
    instr->is_addr = false;
  }
  else if (*s_end != 0) {
    return false;
  }
  else {
    instr->hack_addr.address = result;
    instr->is_addr = true;
  }

  return true;
}
void parse_C_instruction(char *line, c_instruction *instr){
  
}
