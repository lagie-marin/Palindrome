/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** main.c
*/

#include "palindrome.h"

static void help(void)
{
    printf("USAGE\n\t./palindrome -n number -p palindrome [-b base] [-imin i");
    printf("] [-imax i]\n\nDESCRIPTION\n\t-n n\tinteger to be transformed (>");
    printf("=0)\n\t-p pal\tpalindromic number to be obtained (incompatible ");
    printf("with the -n option) (>=0)\n\t\tif defined, all fitting values ");
    printf("of n will be output\n\t-b base\tbase in which the procedure will");
    printf(" be executed (1<b<=10) [def: 10]\n\t-imin i minimum number of ");
    printf("iterations, included (>=0) [def: 0]\n\t-imax i maximum number of");
    printf(" iterations, inculded (>=0) [def: 100]\n");
    exit(0);
}

int main(int ac, array_t av)
{
    config_t config;

    if (ac < 2)
        return 84;
    if (!strcmp(av[1], "-h"))
        help();
    if ((ac - 1) % 2 == 1)
        invalid_args();
    config.args = av;
    init_config(&config);
    process(config);
    return 0;
}
