#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../src/polynomes.h"
#include "builtins.h"

struct polynomes_table_node_t {
    polynome_t *polynome;
    char name;
    struct polynomes_table_node_t *next;
};

struct {
    struct polynomes_table_node_t *first;
} polynomes_table;

void define_polynome (char *params)
{
    char *ptr;
    double *cparams;
    int pcount;
    struct polynomes_table_node_t *new_poly;
    printf("defining a new polynome with params : %s\n",params);

    ptr = strtok (ptr , " ,;");
    if (isalpha(*ptr)) {

        new_poly = malloc(sizeof *new_poly);
        new_poly->next = polynomes_table.first;
        new_poly->name = toupper(*ptr);
        polynomes_table.first = new_poly;

        printf("parameters : ");
        pcount = 0;
        ptr++;
        while ( ptr = strtok (ptr , " ,;"))
            cparams[pcount++] = strtod(ptr);
            ptr += strlen (ptr); 
            printf("%ld ",cparams[pcount - 1]);
        }
    }
    printf ("\n");

    printf("polynome %c defined\n",polynomes_table.first->name);
}
