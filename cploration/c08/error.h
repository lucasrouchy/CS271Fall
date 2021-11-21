#include <stdarg.h>

#ifndef __ERROR_H__
#define __ERROR_H__

// All code in file

#endif
enum exitcode {
  /*
 * Error code 1 represents that given file does not exist.
 */
EXIT_INCORRECT_ARGUMENTS = 1,
}

void exit_program(enum exitcode code, ...);
