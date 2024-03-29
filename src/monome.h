/***************************************************************************
 *            
  * monome.h
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
 monome.h
 *
 *  Thu September 15 16:56:23 2011
 *  Copyright  2011  Nowres RAFID
 *  <nowres.rafed@gmail.com>
 ****************************************************************************/
#ifndef _MONOME_H_LIBPOLYNOMES_INCLUDED
#define _MONOME_H_LIBPOLYNOMES_INCLUDED

struct _lp_monome_t {
	double factor;
	struct _lp_monome_t *next;
};

typedef struct _lp_monome_t _lp_monome_t;

#endif
