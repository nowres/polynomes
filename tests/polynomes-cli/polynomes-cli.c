/***************************************************************************
 *            
  * polynomes-cli.c
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
 polynomes-cli.c
 *
 *  Sun September 18 00:41:38 2011
 *  Copyright  2011  Nowres RAFID ABDULSATTAR
 *  <nowres.rafed@gmail.com>
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../../src/polynomes.h"

int main()
{
    double poly_vals [] = {2,5,1}; /** P(x) = 2x^2 + 5x + 1 **/
    double val;
    polynome_t *poly;
    poly = create_polynome ();
    set_polynome (poly , poly_vals , 2 );
    polynome_value (poly , 1 , &val); /** calculating P(1) / val = P(1) **/

    printf("P(1) = %lf",val);
    return 0;
}
