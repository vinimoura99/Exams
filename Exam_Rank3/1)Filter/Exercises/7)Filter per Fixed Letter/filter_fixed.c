/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_fixed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:13:12 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/03 10:53:46 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <string.h>

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

int main(void)
{
    char c;
    char line[1024];
    char *find = "42";
    int idx = 0;
    int n;

    while ((n = read(0, &c, 1)) > 0)
    {
        line[idx++] = c;

        if (c == '\n')
        {
            line[idx] = '\0';
            if (ft_strstr(line, find))
                write(1, line, idx);
            idx = 0;
        }
    }

    // Processa a última linha se não terminou com \n
    if (idx > 0)
    {
        line[idx] = '\0';
        if (strstr(line, "42"))
            write(1, line, idx);
    }

    return 0;
}