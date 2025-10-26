/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:05:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/23 15:32:02 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int size = 0;
    for(int i = 0; str[i]; i++)
        size++;
    return(size);
}

void ft_swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(char *str)
{
    int size = ft_strlen(str);
    for(int i = 0; i < size; i++)
    {
        for(int j =  i + 1; j < size; j++)
        {
            if(str[i] > str[j])
                ft_swap(&str[i], &str[j]);
        }
    }
}

void ft_permute(char *str, int pos, int size)
{
    if(pos == size)
    {
        write(1, str, size + 1);
        write(1 , "\n", 1);
        return;
    }

    int i = pos;
    
    while(str[i])
    {
        if( i != pos && str[i] == str[pos])
            continue;
        
        ft_swap(&str[pos], &str[i]);
        bubble_sort(str + pos + 1);
        ft_permute(str, pos + 1, size);
        bubble_sort(str + pos);
        i++;
        
    }
}
int main(int ac , char **av)
{
    if(ac == 2)
    {
        char *str = av[1];
        int len = ft_strlen(str);

        bubble_sort(str);
        ft_permute(str, 0 , len - 1);
    }
    else
        return(1);
}