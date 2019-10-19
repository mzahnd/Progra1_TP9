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
 * File:    printAns.h
 * 
 * Author:  Martín E. Zahnd                         <mzahnd at itba.edu.ar>
 *          Joaquín Artola                          <joartola at itba.edu.ar>
 *          Camila Jazmin Terrazas Socaño           <cterrazas at itba.edu.ar>
 *          Francisco Carricart                     <fcarricart at itba.edu.ar>
 *
 * Team:    Grupo 5
 * 
 * Created: October 19, 2019, 9:47 AM
 * 
 * General code description:
 *          Imprime en pantalla si el string es o no un palíndromo.
 * ============================================================================
 */

#ifndef PRINTANS_H
#    define PRINTANS_H

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
printAns(char *string, int answer);

#endif /* PRINTANS_H */

