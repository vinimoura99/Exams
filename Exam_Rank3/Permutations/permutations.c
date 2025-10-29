/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:05:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/29 10:46:22 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void swap(char *a, char *b)
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

void sort(char *str)
{
    int len = ft_strlen(str);
    for(int i = 0;i < len;i++)
    {
        for(int j = i + 1;j < len;j++)
        {
            if(str[i] > str[j])
                swap(&str[i],&str[j]);
        }   
    }
}

void permutation(char *str, int pos, int end_pos)
{
    if(pos == end_pos)
    {
        write(1, str, end_pos + 1);
        write(1, "\n", 1);
        return;
    }

    int i = pos;

    while(str[i])
    {
        swap(&str[pos],&str[i]);
        sort(str + pos + 1);
        permutation(str, pos + 1, end_pos);
        sort(str + pos);
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *str = av[1];
        int len = ft_strlen(str);

        sort(str);
        permutation(str,0,len - 1);
    }
    else 
        return(1);
}
