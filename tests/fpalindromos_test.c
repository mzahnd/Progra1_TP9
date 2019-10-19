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
 * File:    fpalindromos_test.c
 * 
 * Author:  Martín E. Zahnd <mzahnd at itba.edu.ar>
 *          Joaquín Artola  <joartola at itba.edu.ar>
 *          Camila Jazmin Terrazas Socaño <cterrazas at itba.edu.ar>
 *          Francisco Carricart <fcarricart at itba.edu.ar>
 *
 * Team:    Grupo 5
 * 
 * Created: October 17, 2019, 9:58 PM
 * 
 * General code description:
 *          Tests del módulo --Function Name--
 * ============================================================================
 */

// ====== Librerías ======
#include <stdio.h>
#include <stdlib.h>

// ====== Constantes y Macros ======

// ====== Globales ======
int test_total, test_pass, test_fail;

// ====== Prototipos ======
void
check_ans(int esperado, int *recibido, char* testname);

// Tests
void
test1(void);
void
test2(void);
void
test3(void);
void
test4(void);
void
test5(void);
void
test6(void);
void
test7(void);
void
test8(void);
void
test9(void);
void
test10(void);
// ====== Funciones ======

/*
 * Simple C Test Suite
 */

void
test1(void)
{
    printf("Test 1 (--Function Name--)\n");

    int ans = -2, fargc = 2;
    char *fargv[] = {"./ejecutable", "hola"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 1");
}

void
test2(void)
{
    printf("Test 2 (--Function Name--)\n");

    int ans = -2, fargc = 2;
    char *fargv[] = {"./ejecutable", "abcba"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 2");
}

void
test3(void)
{
    printf("Test 3 (--Function Name--)\n");

    int ans = -2, fargc = 2;
    char *fargv[] = {"./ejecutable", "ab-ba"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 3");
}

void
test4(void)
{
    printf("Test 4 (--Function Name--)\n");

    int ans = -2, fargc = 2;
    char *fargv[] = {"./ejecutable", "-"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 4");
}

void
test5(void)
{
    printf("Test 5 (--Function Name--)\n");

    int ans = -2, fargc = 3;
    char *fargv[] = {"./ejecutable", "abc", "cbc"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 5");
}

void
test6(void)
{
    printf("Test 6 (--Function Name--)\n");

    int ans = -2, fargc = 3;
    char *fargv[] = {"./ejecutable", "abc", "."};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 6");
}

void
test7(void)
{
    printf("Test 7 (--Function Name--)\n");

    int ans = -2, fargc = 3;
    char *fargv[] = {"./ejecutable", "ITBAabti", "CBC"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 7");
}

void
test8(void)
{
    printf("Test 8 (--Function Name--)\n");

    int ans = -2, fargc = 5;
    char *fargv[] = {"./ejecutable", "ITBAabti", "CBC", "Anana",
                     "Anita lava la tina"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 8");
}

void
test9(void)
{
    printf("Test 9 (--Function Name--)\n");

    int ans = -2, fargc = 2;
    char *fargv[] = {"./ejecutable", "A man, a plan, a canal, Panama"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 9");
}

void
test10(void)
{
    printf("Test 10 (--Function Name--)\n");

    int ans = -2, fargc = 2;
    char *fargv[] = {"./ejecutable", "A man. a plan; a canal, Panama"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    //ans = funcion(fargc, fargv);

    check_ans(0, &ans, "Test 10");
}

void
check_ans(int esperado, int *recibido, char* testname)
{
    test_total++;
    if(esperado != *recibido)
    {
        test_fail++;

        printf("%%TEST_FAILED%% testname=%s message=Error, se esperaba %d ",
               testname, esperado);
        printf(" pero se recibió %d\n", *recibido);
    }
    else
    {
        test_pass++;
    }
}

int
main(int argc, char** argv)
{
    printf("%%SUITE_STARTING%% fpalindromos_test\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% \n");
    test1();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test2();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test3();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test4();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test5();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test6();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test7();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test8();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test9();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TEST_STARTED%% \n");
    test10();
    printf("%%TEST_FINISHED%% \n");

    printf("%%TESTS_PASSED%% %d \n", test_pass);
    printf("%%TESTS_FAILED%% %d \n", test_fail);
    printf("%%TESTS_TOTAL%% %d \n", test_total);
    printf("%%SUITE_FINISHED%%\n");

    return (EXIT_SUCCESS);
}
