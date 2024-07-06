/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-marin.lagie
** File description:
** redirect_all_stdout.c
*/
#include "crit.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
