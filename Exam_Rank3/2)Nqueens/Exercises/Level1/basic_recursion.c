/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_recursion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:55:25 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/09/30 14:01:59 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* ****************************Atoi****************************************** */

int ft_atoi(char *number)
{   
    int res = 0;
    int idx = 0;
    int sig = 1;

    while(number[idx] == 32 || number[idx] >= 9 && number[idx] <= 13)
    {
        idx++;
    }

    if(number[idx] == '-')
    {
        sig = -1;
        idx++;            
    }

    while(number[idx] >= '0' && number[idx] <= '9')
    {
        res = (res * 10) + (number[idx] - '0');
		idx++;
    }
    return(res * sig);
}

/* ****************************Basic Rec***************************************** */

void basic_recursion(int current, int max)
{
    if (current > max)
    {
        printf("\n");
        return;
    }
        
    
    printf("%d", current);

    if(current <= max)
    {
        printf(" ");
    }

    basic_recursion(current + 1, max);
    
}


int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nbr = ft_atoi(av[1]);
        basic_recursion(1, nbr);

    }
    else
        write(1, "error", 1);
}