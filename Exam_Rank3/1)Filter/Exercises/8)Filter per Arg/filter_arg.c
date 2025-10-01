/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:24:46 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/01 19:34:43 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strstr(char *str, char *sub_str)
{
    int i = 0;
    int j;

    while (str[i] != '\0')
    {
        j = 0;
        while (str[i + j] == sub_str[j] && sub_str[j] != '\0')
            j++;
        if (sub_str[j] == '\0')
            return 1; // encontrou
        i++;
    }
    return 0; // não encontrou
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char letter;
        char line[1024];
        char *to_find =  av[1];
        int idx = 0;
        int n;
    
        while ((n = read(0, &letter, 1)) > 0)
        {
            line[idx++] = letter;
    
            if (letter == '\n')
            {
                line[idx] = '\0';
                if (ft_strstr(line, to_find))
                    write(1, line, idx);
                idx = 0;
            }
        }
    
        // Processa a última linha se não terminou com \n
        if (idx > 0)
        {
            line[idx] = '\0';
            if (ft_strstr(line, to_find))
                write(1, line, idx);
        }
    
        return 0;
    }
    else 
        return 0;
}