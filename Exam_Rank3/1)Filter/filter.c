/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:16:43 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/16 09:08:41 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filter(char *str, char *find)
{
    int i = 0;
    int j;
    int len = strlen(find);

    while(str[i])
    {
        j = 0;
        
        while(find[j] && str[i + j] == find[j])
            j++;
        
        if ( j == len)
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
            write(1, &str[i], 1);
            i++;
        }
        
    }
}


int main(int ac, char **av)
{
    char buffer[2400];
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
/* void filter(char *str, char *find)
{
    int idx = 0;
    int idx2;
    int len = strlen(find);

    while(str[idx])
    {
        idx2 = 0;
        while(find[idx2] && str[idx + idx2] == find[idx2])
            idx2++;

        if(idx2 == len)
        {
            while(idx2 > 0)
            {
                write(1, "*", 1);
                idx2--;
            }
            idx += len;
        }
        else
        {
            write(1, &str[idx], 1);
            idx++;
        }
    }
}


int main(int ac, char **av)
{
    char buffer[2400];
    int b_read;
    int len = 0;

    while((b_read = read(0, buffer + len, sizeof(buffer) - len - 1)) > 0)
        len += b_read;

    if(len < 0)
    {
        perror("error");
        return(1);
    }

    filter(buffer, av[1]);
}
 */