/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:16:43 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/15 14:58:58 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filter(char *str, char *find)
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
