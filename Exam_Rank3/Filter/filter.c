/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:34:49 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/23 11:12:31 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filter(char *buffer, char *filter)
{
    int i = 0;
    int j;
    int len = strlen(filter);

    while(buffer[i])
    {
        j = 0;

        while(filter[j] && buffer[i + j] == filter[j])
        {
            j++;
        }
        if(j == len)
        {
            while(j > 0)
            {
                write(1, "*", 1);
                j--;
            }
            i += len;
        }
        else
        {
            write(1, &buffer[i], 1);
            i++;
        }
    }
}
int main(int ac , char **av)
{
    if(ac == 2)
    {
        char buffer[24000];
        int bytes_read;
        int len = 0;

        while((bytes_read = read(0, buffer + len, sizeof(buffer) - len - 1)) > 0)
            len += bytes_read;
        if(len < 0)
        {
            perror("Error");
            return(1);
        }
        filter(buffer, av[1]);
    }
    else
        return(1);
}