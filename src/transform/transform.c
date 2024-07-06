/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** transform.c
*/
#include "palindrome.h"

static int test_p(config_t *config, char *base_conf, int *it)
{
    int p;

    if (*it < config->imin)
        return 1;
    p = atoi(config->p);
    if (basex_to_base10(base_conf, config->b) > p) {
        (*it) = -1;
        return 0;
    } else
        return basex_to_base10(base_conf, config->b) != p;
}

static int test_n(config_t *config, char *base_conf, int *it)
{
    int imin = config->imin;
    int imax = config->imax;

    if (!is_palindrome(base_conf) && *it >= imax)
        (*it) = -1;
    else if (is_palindrome(base_conf) && *it >= imin && *it <= imax)
        return 0;
    else
        return (PAL_OR_NOT(base_conf) && *it <= imax);
    return 0;
}

static int ok_pal(config_t *config, char *base_conf, int *it)
{
    if (*it > config->imax) {
        (*it) = -1;
        return 0;
    }
    if (config->n != NULL)
        return test_n(config, base_conf, it);
    else
        return test_p(config, base_conf, it);
    return 0;
}

int getpalindrome(config_t *config, char **base_conf)
{
    int it = 0;

    for (int i = config->imin; ok_pal(config, (*base_conf), &it); i++) {
        it++;
        (*base_conf) = int_conv((*base_conf), config->b);
    }
    return it;
}

void transform(config_t *config, char *base_conf)
{
    char *n = config->n;
    int b = config->b;
    int iterations = getpalindrome(config, &base_conf);

    if (is_palindrome(base_conf) && iterations != -1)
        printf(MSG_N, n, basex_to_base10(base_conf, b), iterations, b);
    else
        printf("no solution\n");
    free(base_conf);
}

static int check_it(config_t *config, int iterations)
{
    if (iterations >= config->imin && iterations <= config->imax)
        return 1;
    return 0;
}

static void check_first_pal(config_t *config, int *v)
{
    if (atoi(config->p) == 0) {
        if (config->imin == 0)
            printf(MSG_P, 0, config->p, v[0], config->b);
        exit(0);
    }
}

void palindrome(config_t *config)
{
    int imin = config->imin;
    int max = atoi(config->p);
    int v[2] = {0, 0};
    char *base_conf;

    check_first_pal(config, v);
    if (imin == 0)
        imin = 1;
    for (int i = 1; i <= max; i++) {
        base_conf = my_getnbr_base(i, config->b);
        v[0] = getpalindrome(config, &base_conf);
        if (v[0] != -1 && is_palindrome(base_conf) && check_it(config, v[0])) {
            printf(MSG_P, i, config->p, v[0], config->b);
            v[1]++;
        }
    }
    if (v[1] == 0)
        printf("no solution\n");
}
