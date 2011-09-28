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
    char *ptr,*eat;
    double *cparams;
    int pcount;
    struct polynomes_table_node_t *new_poly;

    cparams = malloc( sizeof(*cparams) * (strlen(params)) );
    eat = malloc( sizeof(*eat) * (strlen(params) + 1) );
    strcpy (eat ,params);
    ptr = strtok (eat , " ");
    if (isalpha(*ptr)) {

        new_poly = malloc(sizeof *new_poly);
        new_poly->next = polynomes_table.first;
        new_poly->name = toupper(*ptr);
        polynomes_table.first = new_poly;

        pcount = 0;
        while ( (ptr = strtok (NULL , " ")) ) {
            cparams[pcount++] = strtod (ptr,NULL);
        }
        new_poly->polynome = create_polynome ();
        set_polynome (new_poly->polynome, cparams , pcount);
    }
    else
        printf("Syntax error!");
}

int value (char *params)
{
    char *ptr,*eat;
    double val,res;
    struct polynomes_table_node_t *bal;

    eat = malloc( sizeof(*eat) * (strlen(params) + 1) );
    strcpy (eat ,params);
    ptr = strtok (eat , " ");
    if (isalpha(*ptr)) {
        *ptr = toupper(*ptr);
        bal = polynomes_table.first;
        while ( bal ){
            if (bal->name == *ptr) {
                val = strtod (strtok(NULL," "),NULL);
                polynome_value ( bal->polynome , val, &res);
                printf("%c(%lf) = %lf",bal->name , val, res);
                return 0;
            }
        }
        printf("Polynome %c not defined",*ptr);
        return 1;
    }
    printf("Syntax error!");
    return 2;
}
