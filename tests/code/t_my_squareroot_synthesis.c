/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** my_squareroot_synthesis.c
*/
#include <criterion/criterion.h>
#include "palindrome.h"

Test ( my_squareroot_synthesis , check_nb_neg )
{
    cr_assert(my_squareroot_synthesis(-99) == -1);
}

Test ( my_squareroot_synthesis , check_nb_null )
{
    cr_assert(my_squareroot_synthesis(0) == 0);
}

Test ( my_squareroot_synthesis , check_nb_1 )
{
    cr_assert(my_squareroot_synthesis(1) == 1);
}

Test ( my_squareroot_synthesis , check_nb_2 )
{
    cr_assert(my_squareroot_synthesis(2) == -1);
}

Test ( my_squareroot_synthesis , check_nb_3 )
{
    cr_assert(my_squareroot_synthesis(3) == -1);
}

Test ( my_squareroot_synthesis , check_nb_16 )
{
    cr_assert(my_squareroot_synthesis(16) == 4);
}

Test ( my_squareroot_synthesis , check_nb_156 )
{
    cr_assert(my_squareroot_synthesis(156) == -1);
}
