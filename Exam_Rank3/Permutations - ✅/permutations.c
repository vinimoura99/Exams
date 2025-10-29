/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:05:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/29 20:31:02 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str);
void bubble_sort(char *str);
void swap(char *a , char *b);
void permutation(char *str, int pos, int end_pos);

int main(int ac, char **av)
{
    if(ac == 2)
    {
        // ./permutation abc

        char *str = av[1];
        int len = ft_strlen(av[1]);

        bubble_sort(str);

        permutation(str,0,len - 1);
        return(0);
        
    }
    else 
        return(1);
}

void permutation(char *str, int pos, int end_pos)
{
    if(pos == end_pos)
    {
        write(1, str, end_pos + 1);
        write(1, "\n",1);
        return;
    }

    int i = pos;

    while(str[i])
    {
        swap(&str[pos], &str[i]);
        bubble_sort(str + pos + 1);
        permutation(str,pos + 1,end_pos);
        bubble_sort(str + pos);
        i++;
    }
}
void bubble_sort(char *str)
{
    int len = ft_strlen(str);

    for(int i = 0;i < len; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(str[i] > str[j])
                swap(&str[i],&str[j]);
        }
    }
}

void swap(char *a , char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
int ft_strlen(char *str)
{
    int size = 0;

    for(int i = 0;str[i];i++)
        size++;
    
    return(size);
}