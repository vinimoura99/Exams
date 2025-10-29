/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:45:34 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/29 16:57:47 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int size = 0;
    for(int i = 0;str[i];i++)
        size++;
    return(size);
}

int calculate(char *str, int len)
{
    int i = 0;
    int open = 0;
    int close = 0;
    
    while(i < len)
    {
        if(str[i] == '(')
            open++;
        else if(str[i] == ')')
        {
            if(open > 0)
                open--;
            else
                close++;
        }
        i++;
    }
    return(open + close);
}

void rip(char *str, int len, int idx, int open, int close, int remove, int min_remove, char *buffer)
{
    if(len == idx)
    {
        buffer[idx] = '\0';
        if(open == close && min_remove == remove)
            puts(buffer);
        return;
    }

    buffer[idx] = str[idx];
    if(str[idx] == '(')
         rip(str, len, idx + 1, open + 1, close, remove, min_remove,buffer);
    else if(str[idx] == ')' && open > close)
         rip(str, len, idx + 1, open , close  + 1 , remove, min_remove,buffer);
    buffer[idx] = ' ';
         rip(str, len, idx + 1, open , close , remove + 1, min_remove,buffer);
}

int main(int ac , char **av)
{
    if(ac == 2)
    {
        char *str = av[1];
        int len = ft_strlen(str);
        int min_remove;
        char buffer[len + 1];

        min_remove = calculate(str,len);

        rip(str,len,0,0,0,0,min_remove,buffer);
    }   
    else
        return(1);
}