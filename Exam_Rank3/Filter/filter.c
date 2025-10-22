/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:34:49 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/16 14:43:24 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Para o filter temos alguns pontos a se pensar:
Primeiro : Vamos receber uma string que vai ser a que vamos fazer o filtro
Segundo: Vamos tratat dela na funcao filter como se tivessemos a fazer um strcmp */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filter(char *str, char *cmp)
{
    int i = 0;
    int j;
    int len = strlen(cmp);

    while(str[i])
    {
        j = 0;

        while(cmp[j] && str[i + j] == cmp[j])
            j++;

        if(j == len)
        {
            while(j > 0)
            {
                write(1, "*", 1);
                j--;
            }
            i += len;
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
    }
}


int main(int ac, char **av)
{
    if(ac == 2)
    {
        char buffer[10000]; // Usado para armazenar a string
        int bytes_read; //Usado para efetuar a leitura do que e lido -> tamanho
        int len = 0;

        while((bytes_read = read(0, buffer + len, sizeof(buffer) - len - 1)) > 0)
            len += bytes_read;

        if(len < 0)
        {
            perror("Error");
            return(1);
        }

        filter(buffer, av[1]);
    }
    else 
        return(1);
}