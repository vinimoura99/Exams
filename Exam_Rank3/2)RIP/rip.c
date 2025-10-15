/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:22:20 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/15 13:22:27 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Função que conta se a string está balanceada
int is_balanced(char *s)
{
    int count = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(')
            count++;
        else if (s[i] == ')')
            count--;
        if (count < 0)
            return 0; // desbalanceada
    }
    return count == 0;
}

// Função simples que gera todas as combinações
void rip(char *s, int index)
{
    if (index == strlen(s))
    {
        if (is_balanced(s))
            write(1, s, strlen(s)), write(1, "\n", 1);
        return;
    }

    if (s[index] == '(' || s[index] == ')')
    {
        // Opção 1: remover parêntese (substituir por espaço)
        char temp = s[index];
        s[index] = ' ';
        rip(s, index + 1);
        s[index] = temp; // volta ao original
    }

    // Opção 2: manter parêntese
    rip(s, index + 1);
}

int main(int ac, char **av)
{
    if (ac != 2) 
        return 0;
    rip(av[1], 0);
}
