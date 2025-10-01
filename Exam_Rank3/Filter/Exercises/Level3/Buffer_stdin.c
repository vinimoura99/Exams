/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Buffer_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:15:49 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/09/29 19:18:03 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(void)
{
    char    *buf;
    ssize_t bytes_read;
    ssize_t bytes_written;

    buf = (char *)malloc(BUFFER_SIZE);
    if (!buf)
        return (1); // erro de malloc

    while (1)
    {
        bytes_read = read(0, buf, BUFFER_SIZE); // lê até 10 bytes
        if (bytes_read < 0)
        {
            free(buf);
            return (1); // erro de leitura
        }
        if (bytes_read == 0)
            break; // EOF

        bytes_written = write(1, buf, bytes_read); // escreve o que foi lido
        if (bytes_written < 0)
        {
            free(buf);
            return (1); // erro de escrita
        }
    }

    free(buf);
    return (0);
}
