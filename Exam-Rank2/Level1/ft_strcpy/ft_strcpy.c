/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:33:28 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 11:29:33 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/*int main(int ac, char **av)
{
    if(ac == 3)
    {
        printf("Argumentos iniciais: \n Argumento 1 -> %s \n Argumento 2 -> %s \n",av[1],av[2]);
        ft_strcpy(av[1],av[2]);
        printf("Argumentos finais: \n Argumento 1 -> %s \n Argumento 2 -> %s",av[1],av[2]);

    }
}*/