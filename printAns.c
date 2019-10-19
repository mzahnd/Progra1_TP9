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
 * File:    printAns.c
 * 
 * Author:  Martín E. Zahnd                         <mzahnd at itba.edu.ar>
 *          Joaquín Artola                          <joartola at itba.edu.ar>
 *          Camila Jazmin Terrazas Socaño           <cterrazas at itba.edu.ar>
 *          Francisco Carricart                     <fcarricart at itba.edu.ar>
 *
 * Team:    Grupo 5
 * 
 * Created: October 19, 2019, 9:45 AM
 * 
 * General code description:
 *          Imprime en pantalla si el string es o no un palíndromo.
 * ============================================================================
 */

// ====== Librerías ======
#include <stdio.h>
#include <stdlib.h>

// Verify if a given string is a palindrome or not
#include "checkPalindromo.h"

// This file
#include "printAns.h"

// ====== Funciones ======

// Print chkpal answer

/*
 * Input: 
 *      *string: Checked string
 *      answer: Answer given by chkpal
 * 
 * Output: 
 *      stdout
 */
void
printAns(char *string, int answer)
{
    switch(answer)
    {
        case ERROR:
            printf("\"%s\" contiene un caracter invalido.\n", string);
            break;
        case NOTPAL:
            printf("\"%s\" no es un palíndromo.\n", string);
            break;
        case YESPAL:
            printf("\"%s\" es un palíndromo.\n", string);
            break;
        default:
            printf("Si llegaste hasta acá, rompiste todo.");
            break;
    }
}
