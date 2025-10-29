/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:49:44 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/29 10:56:31 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void print_list(int *array, int len)
{
    int i = 0;

    while (i < len)
    {
        if (i > 0)
            printf(" ");
        printf("%i", array[i]);
        i++;
    }
    printf("\n");
}

void powerset(int *array, int len, int target, int index, int sum, int *path, int path_size)
{
    if (index == len)
    {
        if (sum == target)
            print_list(path, path_size);
        return ;
    }
    powerset(array, len, target, index + 1, sum, path, path_size);
    path[path_size] = array[index];
    powerset(array, len, target, index + 1, sum + array[index], path, path_size + 1);
}

int main(int argc, char **argv)
{
    int target; //alvo a ser atingido com a soma
    target = atoi(argv[1]);
    
    int len;
    len = argc - 2;
    
    int *array;
    array = malloc(len * sizeof(int));
    
    int *path;
    path = malloc(len * sizeof(int));

    int i = 0;

    if(argc < 2)
        return(1);   

    
    
    if (len == 0)
        return(0); 

    
    
    if(!array || !path)
        return(1);
        
    while (i < len) //popular array
    {
        array[i] = atoi(argv[i + 2]);
        i++;
    }

    powerset(array, len, target, 0, 0, path, 0);
    
    free(array);
    free(path);
}