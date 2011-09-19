#include <stdio.h>
#include <stdlib.h>
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
    char *ptr = params;
    printf("defining a new polynome with params : %s\n",params);
    while (isspace(*ptr)) ptr++;

    polynomes_table.first = malloc(sizeof *polynomes_table.first);
    polynomes_table.first->name = *ptr++;

    printf("polynome %c defined\n",polynomes_table.first->name);
}
