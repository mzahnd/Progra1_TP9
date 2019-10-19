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
#define TOUPPER(c) (((c)>='a' && (c)<='z') ? ((c)+'A'-'a') : (c))
#define VERIFLETTER(c) ( ((TOUPPER(c)) >= 'A' && (TOUPPER(c)) <= 'Z') ? 1 : 0 )

// ====== Prototipos ======

// Get string size
static void
getstr_size(char **string, char **strend, int position);

// Compare characters in string
static int
compare_chars(char *strstart, char *strend);

// Ommit special characters

static int
chr2ommit(char **start, char **end);

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
    int ans = -2;

    if(strstart > strend)
    {
        ans = 1;
    }

    else if(strstart == strend)
    {
        if(VERIFLETTER(*strstart))
        {
            ans = 1;
        }

        else if(*(strend + 1) != '\0')
        {
            ans = chr2ommit(&strstart, &strend);
        }

        else
        {
            ans = -1;
        }
    }

    else
    {
        while(ans != -1 &&
              (VERIFLETTER(*strstart) == 0 || VERIFLETTER(*strend) == 0))
        {
            ans = chr2ommit(&strstart, &strend);
        }

        if(ans != -1 &&
           (TOUPPER(*strstart) == TOUPPER(*strend)))
        {
            ans = compare_chars(strstart + 1, strend - 1);
        }

        else if(ans != -1)
        {
            ans = 0;
        }
    }

    /*while((VERIFLETTER(*strstart) == 0 ||
           VERIFLETTER(*strend) == 0)
          && ans == -2)
    {
        ans = chr2ommit(&strstart, &strend);
    }

    if(ans != -1 && strstart == strend)
    {
        if(callnumber == 0 && VERIFLETTER(*strstart))
        {
            ans = 1;
        }

        else if(callnumber == 0)
        {
            ans = -1;
        }

        else if(VERIFLETTER(*strstart))
        {
            ans = 1;
        }

        else
        {
            ans = -1;
        }
    }

    else if(ans != -1 && strstart > strend)
    {

        if(callnumber == 0)
        {
            ans = -1;
        }

        else
        {
            ans = 1;
        }
    }

    else if(ans != -1)
    {
        if(TOUPPER(*(strstart)) == TOUPPER(*(strend)))
        {
            callnumber++;

            ans = compare_chars(strstart + 1, strend - 1);
        }

        else
        {
            ans = 0;
        }

        if(strstart <= strend &&
   TOUPPER(*(strstart)) == TOUPPER(*(strend)))
{
    callnumber++;

    ans = compare_chars(strstart + 1, strend - 1);
}

else if(strstart <= strend)
{
    ans = -1;
}

else if(strstart > strend)
{
    ans = 0;
}
    }*/

    return ans;
}

// Ommit special characters

static int
chr2ommit(char **start, char **end)
{
    int i, ans = -1;
    char ***strchar = NULL;

    for(i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            strchar = &start;
        }
        else
        {
            strchar = &end;
        }

        switch(***strchar)
        {
            case ' ':
            case ',':
            case ';':
            case ':':
            case '.':
            case '?':
            case '!':
            case '\x27':
            case '\x22':
                if(i == 0)
                {
                    **strchar = **strchar + 1;
                }

                else
                {
                    **strchar = **strchar - 1;
                }

                ans = 1;

                break;

            default:
                ans != 1 ? ans = -1 : ans;

                break;
        }
    }

    return ans;
}
