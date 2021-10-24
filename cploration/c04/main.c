#include "parser.h"

int main(int argc, char* argv[]) {
    // check that one argument has been passed
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // open the argument passed as a file
    FILE* fin = fopen(argv[1], "r");
    // check if your point is NULL
    if (fin == NULL) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }
    // call our function parse
    parse(fin);
    // close your file pointer
    fclose(fin);

    return 0;
}
