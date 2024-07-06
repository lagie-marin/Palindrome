/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** process.c
*/
#include "palindrome.h"

void process(config_t config)
{
    if (config.n)
        transform(&config, my_getnbr_base(atoi(config.n), config.b));
    else
        palindrome(&config);
}
