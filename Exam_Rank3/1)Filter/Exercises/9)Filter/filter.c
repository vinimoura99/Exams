/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:52:33 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/01 20:03:46 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    if (ac == 2)
{
    char linha[1024];
    int contador = 0, i = 0, palavra_len = strlen(av[1]);

    // Lê a entrada padrão e armazena na linha
    while (read(0, &linha[contador], 1) > 0)
        contador++;
    linha[contador] = '\0';

    // Percorre a linha para encontrar a palavra-chave
    while (linha[i])
    {
        int j = 0;
        while (linha[i + j] == av[1][j] && av[1][j])
            j++;

        if (j == palavra_len) // Palavra-chave encontrada
        {
            for (int k = 0; k < palavra_len; k++)
                write(1, "*", 1);
            i += palavra_len;
        }
        else
            write(1, &linha[i++], 1); // Imprime o caractere atual
    }
}
    else
    {
        write(1, "Usage: ./filter <palavra_chave>\n", 32);
        return 1;
    }
    return 0;
}