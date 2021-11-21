#include "parser.h"
// exercice 4
void parse(FILE* file) {
    char line[MAX_LINE_LENGTH] = {0};

    while(fgets(line, sizeof(line), file)) {
        strip(line);

        if(!*line)
            continue;
        char inst_type = {0};
        if (is_Atype(line)) {
          inst_type = 'A';
        }

        else if (is_label(line)){
          inst_type= 'L';
          char new_label[sizeof(line)];
          extract_label(line,new_label);
          printf("%c  %s\n",inst_type, new_label );
          continue;
        }
        else if(is_Ctype(line)){
          inst_type = 'C';
        }
        printf("%c  %s\n",inst_type ,   line);
    }
}

// exercice 5
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
