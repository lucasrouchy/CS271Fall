#include "parser.h"
#include "error.h"

#define MAX_INSTRUCTION_COUNT   30000

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
     //Exercise 10

    instruction* instructions = malloc(MAX_INSTRUCTION_COUNT * sizeof(instruction));
    // call our function parse
    int ninstr = parse(fin, instructions);
    printf("main: ninstr=%d\n", ninstr);

    // close your file pointer
    fclose(fin);

    assemble(argv[1], instructions, num_instructions);

    free(instructions);

    return 0;
}
