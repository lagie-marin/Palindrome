/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** init_config.c
*/
#include "palindrome.h"

static void valid_n(char *n_value, config_t *config)
{
    if (!str_isnum(n_value) || atoi(n_value) < 0)
        invalid_args();
    config->n = n_value;
}

static void valid_p(char *p_value, config_t *config)
{
    if (!str_isnum(p_value) || atoi(p_value) < 0)
        invalid_args();
    config->p = p_value;
}

static void valid_b(char *b_value, config_t *config)
{
    int b_int;

    if (!str_isnum(b_value))
        invalid_args();
    b_int = atoi(b_value);
    if (b_int <= 1 || b_int > 10)
        invalid_args();
    config->b = b_int;
}

static void valid_imin(char *imin_value, config_t *congif)
{
    int imin_int;

    if (!str_isnum(imin_value))
        invalid_args();
    imin_int = atoi(imin_value);
    if (imin_int < 0 || imin_int > congif->imax)
        invalid_args();
    congif->imin = imin_int;
}

static void valid_imax(char *imax_value, config_t *config)
{
    int imax_int = atoi(imax_value);

    if (imax_int < 0 || imax_int < config->imin)
        invalid_args();
    config->imax = imax_int;
}

static int check_args(config_t *config, int i, char *flag, cond_t cond)
{
    array_t av = config->args;

    if (!strcmp(av[i], flag)) {
        if (!str_isnum(av[i + 1]))
            invalid_args();
        cond(av[i + 1], config);
        return 1;
    }
    return 0;
}

static void check_config(config_t *config)
{
    char *str;

    if (config->n == NULL && config->p == NULL)
        invalid_args();
    if (config->p != NULL) {
        str = my_getnbr_base(atoi(config->p), config->b);
        if (!is_palindrome(str)) {
            free(str);
            invalid_args();
        }
        free(str);
    }
}

void init_config(config_t *config)
{
    array_t av = config->args;
    int exist = 0;

    config->n = NULL;
    config->p = NULL;
    config->b = 10;
    config->imin = 0;
    config->imax = 100;
    for (int i = 1; av[i]; i += 2) {
        exist += check_args(config, i, "-n", &valid_n);
        exist += check_args(config, i, "-p", &valid_p);
        exist += check_args(config, i, "-b", &valid_b);
        exist += check_args(config, i, "-imin", &valid_imin);
        exist += check_args(config, i, "-imax", &valid_imax);
        if (!exist)
            invalid_args();
        exist = 0;
    }
    check_config(config);
}
