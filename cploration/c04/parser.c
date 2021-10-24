#include "parser.h"
// exercice 4
void parse(FILE* file) {
    char line[MAX_LINE_LENGTH] = {0};
    while(fgets(line, sizeof(line), file)) {
        strip(line);
        if(!*line)
            continue;
        printf("%s\n",  line);
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
    strcpy(s, s_new);

    return s;
}
