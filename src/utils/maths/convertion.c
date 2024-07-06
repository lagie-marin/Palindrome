/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-palindrome-marin.lagie
** File description:
** convertion.c
*/
#include "palindrome.h"

int get_length_base(int nbr, int base_len)
{
    int length = 0;

    while (nbr != 0) {
        nbr /= base_len;
        length++;
    }
    return length;
}

char *my_getnbr_base(int nbr, int base)
{
    char bases[10] = "0123456789";
    int length = 0;
    char *result;

    length = get_length_base(nbr, base);
    result = malloc(length + 1);
    result[length] = '\0';
    while (nbr != 0) {
        length--;
        result[length] = bases[nbr % base];
        nbr /= base;
    }
    return result;
}

static char *basique(int len, char *result)
{
    char *t_result = (char *)calloc(len + 1, sizeof(char));

    strcpy(t_result, result + 1);
    free(result);
    return t_result;
}

char *int_conv(char *base_conf, int base)
{
    int len = strlen(base_conf);
    char *s_bin = my_revstr(strdup(base_conf));
    char *result = (char *)calloc(len + 2, sizeof(char));
    int sum = 0;
    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        sum = (base_conf[i] - '0') + (s_bin[i] - '0') + carry;
        result[i + 1] = (sum % base) + '0';
        carry = sum / base;
    }
    free(s_bin);
    free(base_conf);
    result[0] = carry + '0';
    if (result[0] == '0')
        return basique(len, result);
    return result;
}

int basex_to_base10(char *basex, int base)
{
    int len = strlen(basex);
    int result = 0;
    int nbr = 0;

    for (int i = 0; i < len; i++) {
        nbr = basex[len - i - 1] - '0';
        result += nbr * my_pow(base, i);
    }
    return result;
}
