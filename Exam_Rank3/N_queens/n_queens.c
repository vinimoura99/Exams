/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:40:32 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/19 17:07:52 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <stdio.h>

int is_safe(int *board, int col, int row) {
    int prev_col = 0;

    while (prev_col < col) {
        if (board[prev_col] == row) {
            return (0);
        }
        
        if (abs(board[prev_col] - row) == col - prev_col) {
            return (0);
        }
        prev_col++;
    }
    return (1);
}

void print_solution(int *board, int n) {
    int i = 0;

    while (i < n) {
        fprintf(stdout, "%d", board[i]); 
        
        if (i < n - 1) {
            fprintf(stdout, " ");
        }
        i++;
    }
    fprintf(stdout, "\n");
}

void solve(int *board, int col, int n) {
    int row = 0;

    if (col == n) {
        print_solution(board, n);
        return;
    }
    
    while (row < n) {
        if (is_safe(board, col, row)) {
            board[col] = row; 
            solve(board, col + 1, n); 
        }
        row++;
    }
}

int main(int ac, char **av) {
    int n;
    int *board;

    if (ac != 2)
        return (1);
        
    n = atoi(av[1]);
    
    if (n <= 0)
        return (0); 
        
    board = malloc(sizeof(int) * n);
    if (!board)
        return (1);
        
    solve(board, 0, n); 
    
    free(board);
    return (0);
}