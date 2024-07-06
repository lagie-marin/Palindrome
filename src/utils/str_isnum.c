/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** str_isnum.c
*/
#include "palindrome.h"

int str_isnum(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}
