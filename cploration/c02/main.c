#define MAX_LIMIT 100
#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
  /** WARMUP **/
// declare a string with value
char hello[] = "Hello";
// declare an empty string
char name[MAX_LIMIT];
char welcome[MAX_LIMIT];
strcpy(welcome,hello);
strcat(welcome, " ");
strcat(name, welcome);
printf("%s\n",welcome );

// prompt user
printf("What is your name? ");

// read in a string from user and save in variable
// [^\n] means to discard the newline character
scanf("%[^\n]s", name);

// print out "hello <name>"
printf("%s %s!\n\n", hello, name);
/** Exercise 2 **/
int len ;
len = strlen(name);
printf("your name is %d\n", len, "characters long" );

/** Exercise 3 **/
char prof[8] = {'P','a','t','r','i','c','k','\0'};

  return 0;
}
