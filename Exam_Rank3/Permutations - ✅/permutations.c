/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:05:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/29 15:51:13 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int size = 0;
    for(int i = 0;str[i]; i++)
        size++;
    return(size);
}

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(char *str)
{
    int size = ft_strlen(str);

    for(int i = 0;i < size;i++)
    {
        for(int j = i + 1; j < size;j++)
        {
            if(str[i] > str[j])
                swap(&str[i],&str[j]);
        }
    }
}

void permutation(char *str, int pos , int final_pos)
{
    if(pos == final_pos)
    {
        write(1, str, final_pos + 1);
        write(1, "\n", 1);
        return;
    }

    int i = pos;

    while(str[i])
    {
        swap(&str[pos], &str[i]);
        bubble_sort(str + pos + 1);
        permutation(str, pos + 1, final_pos);
        bubble_sort(str + pos);
        i++;
    }

}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *str = av[1];
        int len = ft_strlen(str);

        //Sort the string
        bubble_sort(str);

        //Backtracking permutation
        permutation(str,0,len - 1);
    }
    else
        return(1);
}