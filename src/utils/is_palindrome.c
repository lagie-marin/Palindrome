/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** is_palindrome.c
*/
#include "palindrome.h"

int is_palindrome(char *str)
{
    int len = strlen(str);
    int pos = len - 1;

    for (int i = 0; i <= len / 2 && pos > 0; i++) {
        if (str[i] != str[pos])
            return 0;
        pos--;
    }
    return 1;
}
