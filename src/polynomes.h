/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * lib.h
 * Copyright (C) Nowres RAFID 2011 <nowres.rafed@gmail.com>
 * 
 * libpolynomes is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libpolynomes is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MONOME_H_LIBPOLYNOMES_INCLUDED
#define _MONOME_H_LIBPOLYNOMES_INCLUDED

struct _lp_monome_t {
	double factor;
	struct _lp_monome_t *next;
};

typedef struct _lp_monome_t _lp_monome_t;

#endif

struct polynome_t {
	_lp_monome_t *first;
	unsigned int order;
};

typedef struct polynome_t polynome_t;

polynome_t* create_polynome ( void );
void init_polynome ( polynome_t *poly );
void reset_polynome ( polynome_t *poly );
int push_monome ( polynome_t *poly, double factor );
int pop_monome ( polynome_t *poly , double *factor);
double* get_polynome_factors (polynome_t *poly);
int polynome_value ( polynome_t *poly, double x , double *result);
int set_polynome ( polynome_t *poly , double *factors, unsigned int order);
polynome_t* add_2polynomes ( polynome_t *poly1, polynome_t *poly2 );
int copy_polynome ( polynome_t *poly1, polynome_t *poly2 );
