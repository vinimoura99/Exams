/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:51:26 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/01 12:54:57 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void ft_strcmp(char *to, char *compare)
{
    int i = 0;
    int j = 0;

    while(to[i] == compare[j] && compare[j] != '\0')
    {
        i++;
        j++;
    }
    if(to[i] != compare[j])
    {
        write(1, "0", 1);
    }
    else
         write(1, "1", 1);
}


int main(int ac, char **av)
{
    if(ac == 3)
    {
        ft_strcmp(av[1], av[2]);        
    }
    else
        write(1, "error!", 6);
        write(1, "\n", 2);
}