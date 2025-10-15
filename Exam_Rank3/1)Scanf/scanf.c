/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:09:07 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/14 14:09:14 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
    int c;

    c = fgetc(f);
    while (isspace(c))
        c = fgetc(f);

    if (c != EOF)
        ungetc(c, f);
    return 0;
}

int match_char(FILE *f, char c)
{
    int d;

    d = fgetc(f);
    if (d == c)
        return 1;
    if (d != EOF)
        ungetc(d, f);
    return 0;
}

int scan_char(FILE *f, va_list ap)
{
    int c;
    char *ptr;

    c = fgetc(f);
    if (c == EOF)
        return 0;
    ptr = va_arg(ap, char *);
    *ptr = (char)c;
    return 1;
}

int scan_int(FILE *f, va_list ap)
{
    int c;
    int neg;
    int val;
    int found;
    int *ptr;

    neg = 0;
    val = 0;
    found = 0;

    c = fgetc(f);
    if (c == '-')
    {
        neg = 1;
        c = fgetc(f);
    }
    else if (c == '+')
        c = fgetc(f);

    while (isdigit(c))
    {
        found = 1;
        val = val * 10 + (c - '0');
        c = fgetc(f);
    }

    if (c != EOF)
        ungetc(c, f);

    if (!found)
        return 0;

    if (neg)
        val = -val;

    ptr = va_arg(ap, int *);
    *ptr = val;
    return 1;
}

int scan_string(FILE *f, va_list ap)
{
    char *str;
    int c;
    int count;

    str = va_arg(ap, char *);
    count = 0;

    match_space(f);
    c = fgetc(f);

    while (c != EOF && !isspace(c))
    {
        str[count] = (char)c;
        count++;
        c = fgetc(f);
    }

    if (c != EOF)
        ungetc(c, f);

    str[count] = '\0';
    if (count == 0)
        return 0;
    return 1;
}

int match_conv(FILE *f, const char **format, va_list ap)
{
    if (**format == 'c')
        return scan_char(f, ap);
    if (**format == 'd')
    {
        match_space(f);
        return scan_int(f, ap);
    }
    if (**format == 's')
    {
        match_space(f);
        return scan_string(f, ap);
    }
    if (**format == EOF)
        return -1;
    return -1;
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
    int nconv;
    int c;

    nconv = 0;
    c = fgetc(f);
    if (c == EOF)
        return EOF;
    ungetc(c, f);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (match_conv(f, &format, ap) != 1)
                break;
            nconv++;
        }
        else if (isspace(*format))
        {
            if (match_space(f) == -1)
                break;
        }
        else if (match_char(f, *format) != 1)
            break;
        format++;
    }

    if (ferror(f))
        return EOF;
    return nconv;
}

int ft_scanf(const char *format, ...)
{
    va_list ap;
    int ret;

    va_start(ap, format);
    ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return ret;
}

int main(void)
{
    char name[50];
    int age;
    char letter;

    printf("Digite nome, idade e letra:\n");
    ft_scanf("%s %d %c", name, &age, &letter);

    printf("Nome: %s\n", name);
    printf("Idade: %d\n", age);
    printf("Letra: %c\n", letter);
    return 0;
}
