/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** palindrome.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PALINDROME_H
    #define PALINDROME_H
    #define MSG_N "%s leads to %i in %i iteration(s) in base %i\n"
    #define MSG_P "%i leads to %s in %i iteration(s) in base %i\n"
    #define PAL_OR_NOT(str) (!is_palindrome(str) || is_palindrome(str))
    #define MAX(s1, s2) ((s1) > (s2) ? (s1) : (s2))
typedef char **array_t;
typedef struct config_s config_t;
typedef void (*cond_t)();

struct config_s {
    char *n;
    char *p;
    int b;
    int imin;
    int imax;
    array_t args;
};
void invalid_args(void);
void init_config(config_t *config);
char *my_getnbr_base(int nbr, int base);
char *my_revstr(char *str);
void transform(config_t *config, char *base_conf);
void process(config_t config);
char *int_conv(char *base_conf, int base);
int is_palindrome(char *str);
int my_pow(int x, int y);
int basex_to_base10(char *basex, int base);
int str_isnum(char *str);
void palindrome(config_t *config);
int my_squareroot_synthesis(int nb);
int my_factrec_synthesis(int nb);
#endif
