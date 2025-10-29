/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:34:49 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/29 20:03:56 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filter(char *str, char *filter);
int ft_strlen(char *str);

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char buffer[24000];
        int b_read;
        int len = 0;

        while((b_read = read(0,buffer + len,sizeof(buffer) - len - 1)) > 0)
            len += b_read;

        if(len < 0)
        {
            perror("Error");
            return(0);
        }

        filter(buffer,av[1]);
        
    }
    else 
        return(1);
}

int ft_strlen(char *str)
{
    int size = 0;
    for(int i = 0;str[i];i++)
        size++;
    return(size);
    
}
void filter(char *str, char *filter)
{
    int i = 0;
    int j;
    int len = ft_strlen(filter);

    while(str[i])
    {
        j = 0;

        while(filter[j] && str[i + j] == filter[j])
            j++;
        

        if(j == len)
        {
            while (j > 0)
            {
                write(1, "*", 1);
                j--;
            }
            i += len;
        }

        else
        {
            write(1, &str[i], 1);
            i++;
        }
    }
}