/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:05:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/21 19:31:39 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void organize_str(char *str)
{
    int i,j;
    int len = strlen(str);

    for(i = 0; i < len; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(str[i] > str[j])
            {
                swap(&str[i], &str[j]);
            }
        }
    }
}

void permutations(char *str, int start , int end)
{
    int i;

    if(start == end)
    {
        write(1, str, end + 1);
        write(1, "\n", 1);
        return;
    }

    i = start;
    while(i <= end)
    {
        if (i != start && str[i] == str[start])
			continue;
        swap(&str[start], &str[i]);
		organize_str(str + start + 1); // mantém o resto ordenado
		permutations(str, start + 1, end);
		organize_str(str + start); // restaura a ordem
        i++;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *str = av[1];
        int len = strlen(str);

        if(len == 0)
        {
            write(1, "\n", 1);
            return(0);
        }

        organize_str(str);

        permutations(str, 0, len - 1);

        return(0);
    }
    else
        return(1);
}