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
 *          Tests del módulo chkpal
 * ============================================================================
 */

// ====== Librerías ======
#include <stdio.h>
#include <stdlib.h>

#include "checkPalindromo.h"

// ====== Constantes y Macros ======
#define MAXSIZE 255
// ====== Globales ======
int test_total, test_pass, test_fail;

// ====== Prototipos ======
// Verify if answer if the expected one.
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
 * Test Suite for chkpal function
 */

void
test1(void)
{
    printf("Test 1 (chkpal)\n");

    int ans = -2, fargc = 2;
    char *fargv[MAXSIZE] = {"./ejecutable", "-"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(-1, &ans, "Test 1");
}

void
test2(void)
{
    printf("Test 2 (chkpal)\n");

    int ans = -2, fargc = 2;
    char *fargv[MAXSIZE] = {"./ejecutable", "hola"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(0, &ans, "Test 2");
}

void
test3(void)
{
    printf("Test 3 (chkpal)\n");

    int ans = -2, fargc = 2;
    char *fargv[MAXSIZE] = {"./ejecutable", "abcba"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(1, &ans, "Test 3");
}

void
test4(void)
{
    printf("Test 4 (chkpal)\n");

    int ans = -2, fargc = 2;
    char *fargv[MAXSIZE] = {"./ejecutable", "ab-ba"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(-1, &ans, "Test 4");
}

void
test5(void)
{
    printf("Test 5 (chkpal)\n");

    int ans = -2, fargc = 3;
    char *fargv[MAXSIZE] = {"./ejecutable", "ab ba", "."};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(1, &ans, "Test 5_1");

    ans = chkpal(fargc, fargv, 2);

    check_ans(-1, &ans, "Test 5_2");
}

void
test6(void)
{
    printf("Test 6 (chkpal)\n");

    int ans = -2, fargc = 3;
    char *fargv[MAXSIZE] = {"./ejecutable", "pollo", "cbc"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(0, &ans, "Test 6_1");

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 2);

    check_ans(1, &ans, "Test 6_2");
}

void
test7(void)
{
    printf("Test 7 (chkpal)\n");

    int ans = -2, fargc = 3;
    char *fargv[MAXSIZE] = {"./ejecutable", "ITBAabti", "CBC"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(1, &ans, "Test 7_1");

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 2);

    check_ans(1, &ans, "Test 7_2");
}

void
test8(void)
{
    printf("Test 8 (chkpal)\n");

    int ans = -2, fargc = 5;
    char *fargv[MAXSIZE] = {"./ejecutable", "ITBA abti", "C  fC", "Anana",
                            "Anita lava la tina"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(1, &ans, "Test 8_1");

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 2);

    check_ans(1, &ans, "Test 8_2");

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 3);

    check_ans(1, &ans, "Test 8_3");

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 4);

    check_ans(1, &ans, "Test 8_4");
}

void
test9(void)
{
    printf("Test 9 (chkpal)\n");

    int ans = -2, fargc = 2;
    char *fargv[MAXSIZE] = {"./ejecutable", "A man, a plan, a canal, Panama"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error
    ans = chkpal(fargc, fargv, 1);

    check_ans(1, &ans, "Test 9");
}

void
test10(void)
{
    printf("Test 10 (chkpal)\n");

    int ans = -2, fargc = 2;
    char *fargv[MAXSIZE] = {"./ejecutable", "A man. a plan; a canal, Panama"};

    // 1 = Palíndromo ; 0 = No Palíndromo ; -1 = Error

    ans = chkpal(fargc, fargv, 1);

    check_ans(1, &ans, "Test 10");
}

// Verify if answer if the expected one.

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
        printf("%%TEST_PASSED%% testname=%s\n", testname);
        test_pass++;
    }
}

int
main(int argc, char** argv)
{
    printf("%%SUITE_STARTING%% int chkpal(int cant, char **string, "
           "int position);\n");
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

    printf("\n\n%%TESTS_PASSED%% %d \n", test_pass);
    printf("%%TESTS_FAILED%% %d \n", test_fail);
    printf("%%TESTS_TOTAL%% %d \n", test_total);
    printf("%%SUITE_FINISHED%%\n");

    return (EXIT_SUCCESS);
}
