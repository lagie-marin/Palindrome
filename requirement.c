/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** requirement.c
*/

#include <stdio.h>

static int my_sqrt(int start, int nb)
{
    if (nb == 0 || nb == 1)
        return nb;
    if ((start * start) < nb)
        return my_sqrt(start + 1, nb);
    if ((start * start) == nb)
        return start;
    return -1;
}

int my_squareroot_synthesis(int nb)
{
    if (nb < 0)
        return -1;
    return my_sqrt(1, nb);
}

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb >= 13)
        return 0;
    if (nb == 0)
        return 1;
    return nb * my_factrec_synthesis(nb - 1);
}
