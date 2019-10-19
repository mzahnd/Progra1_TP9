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
 * File:    checkPalindromo.h
 * 
 * Author:  Martín E. Zahnd                         <mzahnd at itba.edu.ar>
 *          Joaquín Artola                          <joartola at itba.edu.ar>
 *          Camila Jazmin Terrazas Socaño           <cterrazas at itba.edu.ar>
 *          Francisco Carricart                     <fcarricart at itba.edu.ar>
 *
 * Team:    Grupo 5
 * 
 * Created: October 18, 2019, 11:16 PM
 * 
 * General code description:
 *          Verifica si un dado string es un palíndromo.
 * ============================================================================
 */

#ifndef CHECKPALINDROMO_H
#    define CHECKPALINDROMO_H
// ====== Constantes y Macros ======

enum ans_status
{
    NOINIT = -2, 
    ERROR, 
    NOTPAL, 
    YESPAL
};

// ====== Prototipos ======
// Verify if a given string is a palindrome or not
/*
 * Input: 
 *      cant: How many strings there are (i.e. argc)
 *      **string: Pointer to array of pointers to char, array of strings, in 
 *              other words. (i.e. argv)
 *      position: Which string in the array must be checked.
 * Output: 
 *      NOTINIT (should not happen, ever), ERROR, NOTPAL, YESPAL.
 */
int
chkpal(int cant, char **string, int position);

#endif /* CHECKPALINDROMO_H */

