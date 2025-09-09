/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:38:57 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/09/09 13:48:55 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Lembrar de put_str
void print_stars(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, "*", 1);
        i++;
    }
}

void filter_line(char *line, char *str)
{
    int i = 0;
    int j;

    while(line[i])
    {
        j = 0;
        while(line[i + j] && line[i + j] == str[j])
        {
            j++;
        }
        if(str[j] == '\0')
        {
            print_stars(str);
            i += j;
        }
        else
            write(1, &line[i++],1);
    }
}

int main(int ac, char **av)
{
    char c;
    char line[1024]; // buffer para a linha
    int i = 0;

    if (ac != 2)
        return (1);

    while (read(0, &c, 1) > 0)
    {
        line[i++] = c;
        if (c == '\n') // linha completa
        {
            line[i] = '\0';
            filter_line(line, av[1]);
            i = 0;
        }
    }

    if (i > 0) // última linha sem \n
    {
        line[i] = '\0';
        filter_line(line, av[1]);
    }

    return (0);
}