/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:42:16 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/01 12:49:21 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *arg)
{
   int count = 0;
   while(arg[count] != '\0')
   {
    count++;
   }
   return(count);
}


int main(int ac, char **av)
{
    if(ac == 2)
    {
        int len = ft_strlen(av[1]);
        write(1, av[1], len);
        write(1, "\n", 1);
    }
    else
    {
        write(1, "error", 5);
        write(1, "\n", 1);
    }
       
}