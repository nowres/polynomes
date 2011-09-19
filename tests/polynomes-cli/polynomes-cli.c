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
#include <ctype.h>
#include <string.h>
#include "polynomes-cli.h"
#include "builtins.h"
#include "../../src/polynomes.h"

#define BUFFER_LENGTH 256
#define MAX_KEYWORD 20

int current_char;
char read_buffer_space[BUFFER_LENGTH];
char* read_buffer = read_buffer_space;

struct keyword_t {
    int code;
    char val [MAX_KEYWORD];
};

typedef struct keyword_t keyword_t;

keyword_t keywords[] = {
{DEF,"def"}
};

int number_of_keywords = sizeof keywords/sizeof(keyword_t);

void read_next_char()
{
    current_char = *read_buffer;
    read_buffer++;
}

keyword_t get_keyword ()
{
    keyword_t key;
    int i;
    i = 0;
    while (isalpha (current_char) && i < MAX_KEYWORD) {
        key.val[i++] = current_char;
        read_next_char ();
    }

    if (i == MAX_KEYWORD) {
        i = 0;
    }

    key.val[i] = '\0';

    if (! key.val ) {
        key.code = INVALID;
        return key;
    }

    for (i = 0 ; i < number_of_keywords; i++) {
        if ( ! strcmp(key.val,keywords[i].val) ) {
            key.code = keywords[i].code;
            return key;
        }
    }

    key.code = INVALID;
    return key;
}

void prompt ()
{
    printf("==> ");
}

void read_and_parse_shell ()
{
    keyword_t key;
    prompt();
    fgets(read_buffer,BUFFER_LENGTH,stdin);

    read_next_char ();
    key = get_keyword ();

    switch (key.code) {
        case DEF:define_polynome(read_buffer);break;
        case INVALID:
        default:fprintf(stderr,"invalid keyword\n");
    }
}

int main()
{
    read_and_parse_shell();
    return 0;
}
