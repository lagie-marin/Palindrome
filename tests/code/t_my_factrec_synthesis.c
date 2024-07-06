/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** my_factrec_synthesis.c
*/
#include "palindrome.h"
#include <criterion/criterion.h>

Test ( my_factrec_synthesis , check_fac_neg )
{
    cr_assert(my_factrec_synthesis(-1) == 0);
}

Test ( my_factrec_synthesis , check_fac_0 )
{
    cr_assert(my_factrec_synthesis(0) == 1);
}

Test ( my_factrec_synthesis , check_fac_1 )
{
    cr_assert(my_factrec_synthesis(1) == 1);
}

Test ( my_factrec_synthesis , check_fac_2 )
{
    cr_assert(my_factrec_synthesis(2) == 2);
}

Test ( my_factrec_synthesis , check_fac_3 )
{
    cr_assert(my_factrec_synthesis(3) == 6);
}

Test ( my_factrec_synthesis , check_fac_16 )
{
    cr_assert(my_factrec_synthesis(16) == 0);
}
