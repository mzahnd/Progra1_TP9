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
 * Author:  Martín E. Zahnd                         <mzahnd at itba.edu.ar>
 *          Joaquín Artola                          <joartola at itba.edu.ar>
 *          Camila Jazmin Terrazas Socaño           <cterrazas at itba.edu.ar>
 *          Francisco Carricart                     <fcarricart at itba.edu.ar>
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

// This file
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
chr2omit(char **start, char **end);

// ====== Funciones ======

// Verify if a given string is a palindrome or not

/*
 * Input: 
 *      cant: How many strings there are (i.e. argc)
 *      **string: Pointer to array of pointers to char; array of strings, in 
 *              other words. (i.e. argv)
 *      position: Which string in the array must be checked.
 * 
 * Output: 
 *      NOTINIT (should never happen), ERROR, NOTPAL, YESPAL.
 */
int
chkpal(int cant, char **string, int position)
{
    int ans = NOINIT;
    char *strend;

    // If there is another string in the array, we can use it to get the last
    // character (omiting '\0') of the string we want
    if(position < cant - 1)
    {
        strend = string[position + 1] - 2;
    }

        // If not, we get it "by hand"
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

/*
 * Input:
 *      **string: Pointer to array of pointers to char; array of strings, in 
 *              other words. (i.e. argv)
 *      **strend: Pointer to the last character of the desired string
 *      position: Which string in the array must be checked
 * 
 * Output:
 *      void
 *      
 */
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

/*
 * Input:
 *      *strstart: Pointer to begining of string
 *      *strend: Pointer to end of string (one character before '\0')
 * 
 * Output:
 *      NOTINIT (should never happen), ERROR, NOTPAL, YESPAL.
 */
static int
compare_chars(char *strstart, char *strend)
{
    int ans = NOINIT;

    // Just in case the function is called wrongly.
    if(*strend == '\0')
    {
        strend = strend - 1;
    }

    /*
     *  The given array could be basically anything, so this procedure will be
     * followed:
     *  Given the array "ana pana", for example, it will be readed letter by
     * letter and compared if they are all equal. ('a' and 'a', 'n' and 'n', 
     * and so on)
     *  Whenever a space, comma, colon, semicolon, period, question or 
     * exclamation mark, or a quotation mark (both single of double) is found,
     * this will be omited using chr2omit function.
     *  In the case that everything went right and the strstart and strend 
     * pointers switch positions, that will mean that the string it is a
     * palindrome.
     *  If the string has an odd amount of characters, both strstart and strend
     * could end up pointing to the same character. In that case, it will be 
     * checked if it's a letter, an accepted punctuation character or anything
     * else.
     */

    // Positions have been switched without problem, then everything it's ok.
    if(strstart > strend)
    {
        ans = YESPAL;
    }

        // String with an odd amount of characters
    else if(strstart == strend)
    {
        // It's a letter
        if(VERIFLETTER(*strstart))
        {
            ans = YESPAL;
        }

            // It's a punctuation character
        else if(*(strend + 1) != '\0')
        {
            ans = chr2omit(&strstart, &strend);
        }

            // It's some other character (i.e. '~') or the only character in
            // the string (and it's not a letter)
        else
        {
            ans = ERROR;
        }
    }

        // strstart < strend
    else
    {
        // In case a punctuation charecter is found in either *strstart or
        // *strend, it must be omited.
        // If an invalid character is found, the ERROR flag it's activated and
        // game is over for this string.
        while(ans != ERROR &&
              (VERIFLETTER(*strstart) == 0 || VERIFLETTER(*strend) == 0))
        {
            ans = chr2omit(&strstart, &strend);
        }

        // Both are the same letter
        if(ans != ERROR &&
           (TOUPPER(*strstart) == TOUPPER(*strend)))
        {
            ans = compare_chars(strstart + 1, strend - 1);
        }

            // They're different letters
        else if(ans != ERROR)
        {
            ans = NOTPAL;
        }
    }

    // That's all folks
    return ans;
}

// Ommit special characters

/*
 * Input:
 *      **start: Pointer to first character of string to check
 *      **end: Pointer to last character of string to check
 * 
 * Output:
 *      ERROR, YESPAL.
 */
static int
chr2omit(char **start, char **end)
{
    int i, ans = ERROR;
    char ***strchar = NULL;

    // Both, the first and last character are checked in the same function.
    // i = 0 means **start ; i = 1 means **end
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
                // Accepted non-letter characters
            case ' ':
            case ',':
            case ';':
            case ':':
            case '.':
            case '?':
            case '!':
            case '\x27':
            case '\x22':
                /*
                 * If we have some string like "ab cdeba" and **start = ' ' 
                 * **end = 'e', then *start + 1 = 'c'.
                 */
                if(i == 0)
                {
                    **strchar = **strchar + 1;
                }

                else
                {
                    **strchar = **strchar - 1;
                }

                ans = YESPAL;

                break;

            default:
                // Either the character is a letter or an invalid character
                /* 
                 *  As this function it's only called if at least one of the
                 * characters it's not a letter, if **start it's a letter, then 
                 * when **end it's analized the final value for ans will be 
                 * set. Being ERROR if **end it's some invalid or YESPAL if not
                 */
                ans != YESPAL ? ans = ERROR : ans;

                break;
        }
    }

    return ans;
}
