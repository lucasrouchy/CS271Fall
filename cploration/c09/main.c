#include "parser.h"
#include "error.h"

int main(int argc, char* argv[]) {
    // check that one argument has been passed
    if (argc != 2) {
      // incorrect number of arguments
      exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);
    }
    // open the argument passed as a file
    FILE* fin = fopen(argv[1], "r");
    // check if your point is NULL
    if (fin == NULL) {
      exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);

    }
    // call our function parse
    parse(fin);
    // close your file pointer
    fclose(fin);

    return 0;
}
