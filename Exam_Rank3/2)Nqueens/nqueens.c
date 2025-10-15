/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:29:55 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/15 13:30:14 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Checa se a rainha na coluna 'col' não ataca nenhuma anterior
int is_safe(int *board, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[i] == board[col] ||                     // mesma linha
            board[i] - i == board[col] - col ||           // mesma diagonal 
            board[i] + i == board[col] + col)             // mesma diagonal 
            return 0;
    }
    return 1;
}

// Função recursiva que coloca rainhas
void solve(int n, int *board, int col)
{
    if (col == n) // todas as rainhas colocadas
    {
        for (int i = 0; i < n; i++)
        {
            if (i > 0) write(1, " ", 1);
            char c = board[i] + '0';
            write(1, &c, 1);
        }
        write(1, "\n", 1);
        return;
    }

    // Tenta colocar a rainha em cada linha
    for (int row = 0; row < n; row++)
    {
        board[col] = row;
        if (is_safe(board, col))
            solve(n, board, col + 1);
    }
}

int main(int ac, char **av)
{
    if (ac != 2) return 0;

    int n = atoi(av[1]);
    if (n <= 0) return 0;

    int *board = malloc(n * sizeof(int));
    if (!board) return 1;

    solve(n, board, 0);

    free(board);
}
