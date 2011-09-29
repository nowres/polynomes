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


/** BEGIN parameters manipulation helpers **/
char *pbuf;

static char* _helper_get_first_param (const char *params_l)
{
    if (pbuf)
        free (pbuf);
    pbuf = malloc( sizeof(*params_l) * (strlen(params_l) + 1) );
    strcpy (pbuf , params_l);
    return strtok (pbuf, " ");
}

static char* _helper_get_next_param ()
{
    return strtok (NULL, " ");
}

static void _helper_end_get_params ()
{
    if (pbuf) free (pbuf);
}
/** END parameters manipulation helpers **/


/** 
    void define_polynome (char * params)    
    description : extract and build parameters to call set_polynome library function
**/
void define_polynome (const char *params)
{
    char *ptr;
    double *cparams;
    int pcount;
    struct polynomes_table_node_t *new_poly;

    ptr = _helper_get_first_param (params);
    if (isalpha(*ptr)) {

        new_poly = malloc(sizeof *new_poly);
        new_poly->next = polynomes_table.first;
        new_poly->name = toupper(*ptr);
        polynomes_table.first = new_poly;

        pcount = 0;
        cparams = malloc( sizeof(*cparams) * (strlen(params)) );
        while ( (ptr = _helper_get_next_param ()) ) {
            cparams[pcount++] = strtod (ptr,NULL);
        }
        new_poly->polynome = create_polynome ();
        set_polynome (new_poly->polynome, cparams , pcount - 1);
    }
    else
        printf("Syntax error!");
    _helper_end_get_params ();
}

int value (const char *params)
{
    char *ptr;
    double val,res;
    struct polynomes_table_node_t *bal;

    ptr = _helper_get_first_param (params);
    if (isalpha(*ptr)) {
        *ptr = toupper(*ptr);
        bal = polynomes_table.first;
        while ( bal ){
            if (bal->name == *ptr) {
                val = strtod (_helper_get_next_param (),NULL);
                polynome_value ( bal->polynome , val, &res);
                printf("%c(%lf) = %lf",bal->name , val, res);
                _helper_end_get_params ();
                return 0;
            }
        }
        printf("Polynome %c not defined",*ptr);
        _helper_end_get_params ();
        return 1;
    }
    printf("Syntax error!");
    _helper_end_get_params ();
    return 2;
}
