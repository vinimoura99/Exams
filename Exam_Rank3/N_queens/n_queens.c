/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:40:32 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/26 11:01:57 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <stdio.h>

int abs(int nbr)
{
    if(nbr < 0)
    {
        return(-nbr);
    }
    return(nbr);
}

void print_solution(int *array, int size)
{
    int idx = 0;
    while(idx < size)
    {
        fprintf(stdout, "%d", array[idx]);
        if(idx < size - 1)
        {
            fprintf(stdout," ");
        }
        idx++;
    }
    fprintf(stdout,"\n");
}
int is_safe(int *array, int col, int row)
{
    int prev_col = 0;

    while(prev_col < col)
    {
        if(array[prev_col] == row)
            return(0);
        if(abs(array[prev_col] - row) == col - prev_col)
            return(0);
        prev_col++;
    }
    return(1);
}


void solve_queens(int *array, int col, int size)
{
    if(col == size)
    {
        print_solution(array,size);
        return;
    }
    
    int row = 0;

    while(row < size)
    {
        if(is_safe(array,col,row))
        {
            array[col] = row;
            solve_queens(array, col + 1, size);
        }
        row++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int size = atoi(av[1]);
        int *array = malloc(sizeof(int) * size);

        if(size < 0)
            return(0);
        if(!array)
            return(1);
        solve_queens(array,0,size);
        free(array);
        return(0);
    }
    else
        return(1);
}