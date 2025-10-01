/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:59:40 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/01 17:11:18 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void ft_strstr(char *str,char *sub_str)
{
    int i = 0;
    int j;   

    while(str[i] != '\0')
    {
        j = 0;

        while(str[i + j] == sub_str[j] && sub_str[j] != '\0')
        {            
            j++;            
        }
        if(sub_str[j] == '\0')
        {
            write(1, "1", 1);
            return;
        } 
        i++;
    }
    write(1, "0", 1);
}   

int main(int ac , char **av)
{
    if(ac == 3)
    {
        ft_strstr(av[1],av[2]);
    }
    else
        return 0;
}