/*
 * Copyright (C) 2019 Martín E. Zahnd <mzahnd at itba.edu.ar>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * ============================================================================
 * File:    checkPalindromo.c
 * 
 * Author:  Martín E. Zahnd <mzahnd at itba.edu.ar>
 *          Joaquín Artola  <joartola at itba.edu.ar>
 *          Camila Jazmin Terrazas Socaño <cterrazas at itba.edu.ar>
 *          Francisco Carricart <fcarricart at itba.edu.ar>
 *
 * Team:    Grupo 5
 * 
 * Created: October 18, 2019, 9:20 PM
 * 
 * General code description:
 *          Verifica si un dado string es un palíndromo.
 * ============================================================================
 */

// ====== Librerías ======
#include <stdio.h>
#include <stdlib.h>

#include "checkPalindromo.h"

// ====== Constantes y Macros ======
#define TOUPPER(c) (((c)>='a' && (c)<='z')?((c)+'A'-'a'):(c))

// ====== Prototipos ======

// Get string size
static void
getstr_size(char **string, char **strend, int position);

// Compare characters in string
static int
compare_chars(char *strstart, char *strend);
// ====== Funciones ======

int
chkpal(int cant, char **string, int position)
{
    int ans = -1;
    char *strend;


    if(position < cant - 1)
    {
        strend = string[position + 1] - 2;
    }

    else
    {
        // Get string size manually
        getstr_size(string, &strend, position);
    }

    // Compare characters in string
    ans = compare_chars(&string[position][0], strend);

    return ans;
}

// Get string size

static void
getstr_size(char **string, char **strend, int position)
{
    int i = 0;

    while(string[position][i] != '\0')
    {
        *strend = string[position] + i++;
    }
}

// Compare characters in string

static int
compare_chars(char *strstart, char *strend)
{
    int ans = -1;

    if(strstart >= strend)

    {
        ans = 1;
    }

    else if(TOUPPER(*(strstart + 1)) == TOUPPER(*(strend - 1)))
    {
        ans = compare_chars(strstart + 1, strend - 1);
    }

    else
    {
        ans = 0;
    }


    return ans;
}
