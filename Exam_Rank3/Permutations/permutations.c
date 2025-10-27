/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:05:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/27 11:03:14 by vmoura-d         ###   ########.fr       */
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

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(char *str)
{
    int len = ft_strlen(str);

    for(int i = 0; i < len; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(str[i] > str[j])
                swap(&str[i],&str[j]);
        }
    }
}

void permutation(char *str, int start , int end)
{
    if(start == end)
    {
        write(1, str, end + 1);
        write(1, "\n", 1);
        return;
    }

    int i = start;

    while(str[i])
    {
        if(i != start && str[start] == str[i])
            continue;
        
        swap(&str[start],&str[i]);
        bubble_sort(str + start + 1);
        permutation(str, start + 1, end);
        bubble_sort(str + start);
        i++;
    }
}
int main(int ac , char **av)
{
    //abc teu argumento ( ./permutation "abc")
    if(ac == 2)
    {
        char *str = av[1];
        int len = ft_strlen(av[1]);

        bubble_sort(str);
        permutation(str,0,len - 1);
    }
    else
        return(1);
}