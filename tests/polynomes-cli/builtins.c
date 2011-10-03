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

static void _helper_end_get_params ()
{
    if (pbuf){
        free (pbuf);
        pbuf = NULL;
    }
}

static char* _helper_get_first_param (const char *params_l)
{
    _helper_end_get_params ();
    pbuf = malloc( sizeof(*params_l) * (strlen(params_l) + 1) );
    strcpy (pbuf , params_l);
    return strtok (pbuf, " ");
}

static char* _helper_get_next_param ()
{
    return strtok (NULL, " ");
}

static void _helper_insert_polynome_table_node ( char name, double* factors , int order )
{
    struct polynomes_table_node_t *new_poly;
    new_poly = malloc(sizeof *new_poly);
    new_poly->next = polynomes_table.first;
    new_poly->name = toupper(name);
    polynomes_table.first = new_poly;
    new_poly->polynome = create_polynome ();
    set_polynome (new_poly->polynome, factors , order);
}

static struct polynomes_table_node_t* _helper_search_polynome_table_node ( char name )
{
    struct polynomes_table_node_t *bal;
    bal = polynomes_table.first;
    while ( bal ){
        if (bal->name == name ) {
            return bal;
        }
        bal = bal->next;
    }
    return NULL;
}

/** END parameters manipulation helpers **/


/** 
    void define_polynome (char * params)    
    description : extract and build parameters to call set_polynome library function
**/
void define_polynome (const char *params)
{
    char *ptr,name;
    double *cparams;
    int pcount;

    ptr = _helper_get_first_param (params);
    if (isalpha((name = *ptr))) {

        pcount = 0;
        cparams = malloc( sizeof(*cparams) * (strlen(params)) );
        while ( (ptr = _helper_get_next_param ()) ) {
            cparams[pcount++] = strtod (ptr,NULL);
        }
        _helper_insert_polynome_table_node ( name, cparams , pcount - 1 );
    }
    else
        printf("Syntax error!");
    _helper_end_get_params ();
}

int value (const char *params)
{
    char *ptr;
    double val,res;
    struct polynomes_table_node_t *poly;

    ptr = _helper_get_first_param (params);
    if (isalpha(*ptr)) {
        if ( (poly = _helper_search_polynome_table_node ( toupper (*ptr) ))) {
            val = strtod (_helper_get_next_param (),NULL);
            polynome_value ( poly->polynome , val, &res);
            printf("%c(%lf) = %lf",poly->name , val, res);
            _helper_end_get_params ();
            return 0;
        } else {
            printf("Polynome %c not defined",*ptr);
            _helper_end_get_params ();
            return 1;
        }
    }
    printf("Syntax error!");
    _helper_end_get_params ();
    return 2;
}

int print (const char* params)
{
    char *ptr,sym;
    double *factors;
    int fcount;
    struct polynomes_table_node_t *poly;

    ptr = _helper_get_first_param (params);
    if (isalpha(*ptr)) {
        *ptr = toupper(*ptr);
        if ( (poly = _helper_search_polynome_table_node ( *ptr ))) {
            ptr = _helper_get_next_param ();
            sym = *ptr;
            if ( isalpha(sym) ) {
                fcount = poly->polynome->order + 1;
                factors = get_polynome_factors (poly->polynome);
                printf("%c(%c) = ",poly->name, sym);
                while ( fcount ) {
                    printf("+(%lf) %c^%d ",factors[poly->polynome->order - fcount],sym,--fcount);
                }
                free (factors);
                _helper_end_get_params ();
                return 0;
            }else {
                printf("Syntax error!");
                _helper_end_get_params ();
                return 3;                
            }

        } else {
            printf("Polynome %c not defined",*ptr);
            _helper_end_get_params ();
            return 1;
        }       
    }
    printf("Syntax error!");
    _helper_end_get_params ();
    return 2;
}
