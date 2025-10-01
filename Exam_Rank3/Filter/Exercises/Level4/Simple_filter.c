/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simple_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:43:34 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/09/29 20:12:11 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

#define MAX_INPUT 4096  // tamanho máximo da entrada

void replace_substring(char *buf, ssize_t len, char *sub)
{
    size_t sub_len = strlen(sub);
    ssize_t i = 0;

    while (i + sub_len <= len)
    {
        size_t j = 0;
        while (j < sub_len && buf[i + j] == sub[j])
            j++;
        if (j == sub_len)
        {
            size_t k = 0;
            while (k < sub_len)
            {
                buf[i + k] = '*';
                k++;
            }
            i += sub_len; // pula a substring
        }
        else
            i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(1, "error", 5);
        return 1;
    }

    char buf[MAX_INPUT];
    ssize_t len = read(0, buf, MAX_INPUT);
    if (len < 0)
        return 1;

    replace_substring(buf, len, av[1]);

    write(1, buf, len);
    return 0;
}
