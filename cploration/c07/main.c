#include "symtable.h"

int main(int argc, char* argv[]) {
    // create empty item
    Symbol* item = (Symbol*) malloc(sizeof(Symbol));
    item->name = NULL;
    item->address = -1;

    // labels from Max.asm
    insert("OUTPUT_FIRST", 11);
    printf("Inserting OUTPUT_FIRST at address 11\n");
    insert("OUTPUT_D", 13);
    printf("Inserting OUTPUT_D at address 13\n");
    insert("INFINITE_LOOP", 15);
    printf("Inserting INFINITE_LOOP at address 15\n");
    printf("\n");

    // display table
    printf("Displaying table:\n");
    display_table();
    printf("\n");

    // search label (FOUND)
    char* label = "OUTPUT_FIRST";
    printf("Looking up %s\n", label);
    item = find(label);

    if(item != NULL) {
        printf("Element %s found: %d\n", item->name, item->address);
    } else {
        printf("Element %s not found\n", label);
    }
    printf("\n");

    // search label (NOT FOUND)
    label = "MY_LABEL";
    printf("Looking up %s\n", label);
    item = find(label);

    if(item != NULL) {
        printf("Element %s found: %d\n", item->name, item->address);
    } else {
        printf("Element %s not found\n", label);
    }
    printf("\n");

    // display table again
    printf("Displaying table:\n");
    display_table();
    printf("\n");

    // free memory
    free(item);

    return 0;
}
