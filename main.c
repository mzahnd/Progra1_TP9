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
 * File:    main.c
 * 
 * Author:  Martín E. Zahnd                         <mzahnd at itba.edu.ar>
 *          Joaquín Artola                          <joartola at itba.edu.ar>
 *          Camila Jazmin Terrazas Socaño           <cterrazas at itba.edu.ar>
 *          Francisco Carricart                     <fcarricart at itba.edu.ar>
 *
 * Team:    Grupo 5
 * 
 * Created: October 17, 2019, 8:20 PM
 * 
 * General code description:
 *          Dado uno o varios strings ingresados como argumentos al ejecutar el
 *      programa, se verifica si cada uno de ellos es un palíndromo.
 * ============================================================================
 */

// ====== Librerías ======
#include <stdio.h>
#include <stdlib.h>

// Verify if a given string is a palindrome or not
#include "checkPalindromo.h"

// Print chkpal answer
#include "printAns.h"

// ====== Funciones ======

int
main(int argc, char** argv)
{
    int answer = -1;

    if(argc <= 1)
    {
        printf("Debe introducir un texto como argumento al ejecutar el "
               "programa.\n");
    }

    else
    {
        int i;
        for(i = 1; i < argc; i++)
        {
            // Verify if a given string is a palindrome or not
            answer = chkpal(argc, argv, i);

#ifdef DEBUG
            printf("i: %d ; answer: %d\n", i, answer);
#else
            // Print chkpal answer
            printAns(argv[i], answer);
#endif

        }

    }

    return (EXIT_SUCCESS);
}

