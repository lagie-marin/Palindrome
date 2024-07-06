/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** my_pow.c
*/
#include "palindrome.h"

int my_pow(int x, int y)
{
    int result = x;

    if (y == 0)
        return 1;
    for (int i = 1; i < y; i++)
        result *= x;
    return result;
}
