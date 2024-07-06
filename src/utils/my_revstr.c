/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** my_revstr.c
*/
#include "palindrome.h"

char *my_revstr(char *str)
{
    int length_src = strlen(str);
    char tmp;

    for (int i = 0; i < length_src / 2; i++) {
        tmp = str[length_src - i - 1];
        str[length_src - i - 1] = str[i];
        str[i] = tmp;
    }
    return str;
}
