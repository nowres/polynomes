/***************************************************************************
 *            
  * polynome.c
  *
  * Copyright (C) 2011 - Nowres
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  *
 polynome.c
 *
 *  Thu September 15 16:56:23 2011
 *  Copyright  2011  Nowres RAFID
 *  <nowres.rafed@gmail.com>
 ****************************************************************************/
#include "polynomes.h"
#include <stdlib.h>
 
polynome_t* create_polynome ( void )
{
	polynome_t *poly;
	if ( (poly = malloc ( sizeof *poly )) ) {
		poly->first = NULL;
		poly->order = -1;
	}
	return poly;
}

void init_polynome ( polynome_t *poly )
{
	poly->first = NULL;
	poly->order = -1;
}


void reset_polynome ( polynome_t *poly )
{
    _lp_monome_t *current;
    current = poly->first;
    while ( current )
    {
        poly->first = current->next;
        free (current);
        current = poly->first;
    }
    
    init_polynome (poly);
}

int push_monome ( polynome_t *poly, double factor )
{
	_lp_monome_t *new_monome;
	if ( (new_monome = malloc ( sizeof *new_monome )) ) {
		new_monome->factor = factor;
		new_monome->next = poly->first;
		poly->first = new_monome;
		return poly->order++;
	} else
		return 0;
}

int pop_monome ( polynome_t *poly , double *factor)
{
	_lp_monome_t *first;
	if ( (first = poly->first) ) {
		*factor = first->factor;
		poly->first = first->next;
		free (first);
		poly->order--;
		return 1;
	} else
		return 0;
}

double* get_polynome_factors (polynome_t *poly)
{
    double *factors, *ptr;
    _lp_monome_t *bal;

    factors = malloc ( (poly->order + 1) * sizeof (*factors) );
    
    ptr = factors + poly->order;
    bal = poly->first;
    while ( bal ) {
        *(ptr--) = bal->factor;
        bal = bal->next;
    }
    return factors;
}

int polynome_value ( polynome_t *poly, double x , double *result)
{
	_lp_monome_t *current;

	current = poly->first;
	if ( current )
		*result = current->factor;
	else
		return 0;
	
	while ( (current = current->next) ) {
		*result = *result * x + current->factor;
	}
	return 1;
}

int set_polynome ( polynome_t *poly , double *factors, unsigned int order)
{
    reset_polynome (poly);
    order++;
    while ( order-- ) {
        push_monome (poly,*(factors + order) );
    }
    
    return poly->order;
}

polynome_t* add_2polynomes ( polynome_t *poly1, polynome_t *poly2 )
{
    polynome_t *res;
    double *factors1, *factors2, *factors;
    int i,max,min;

    res = create_polynome ();
    factors1 = get_polynome_factors (poly1);
    factors2 = get_polynome_factors (poly2);
    
    max = (poly1->order > poly2->order) ? poly1->order + 1 : poly2->order + 1;
    min = (poly1->order < poly2->order) ? poly1->order + 1 : poly2->order + 1;
    factors = malloc (sizeof (*factors) * max );
    for ( i = 0; i < min ; i++ ) {
        factors[i] = factors1[i] + factors2[i];
    }
    
    while ( i <= poly1->order ) {
        factors[i++] = factors1[i];
    }

    while ( i <= poly2->order ) {
        factors[i++] = factors2[i];
    }
    
    set_polynome ( res , factors , max - 1 );
    free (factors1);
    free (factors2);
    return res;
}
