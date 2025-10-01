/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stdin_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:01:08 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/09/29 19:12:36 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(void)
{
    char    buf;
    ssize_t bytes_read;
    ssize_t bytes_written;

    while (1)
    {
        bytes_read = read(0, &buf, 1); // lê 1 caractere do stdin
        if (bytes_read < 0)
            return (1);                // erro de leitura
        if (bytes_read == 0)
            break;                     // fim da entrada (EOF)

        // escreve o caractere e guarda o retorno
        bytes_written = write(1, &buf, 1);
        if (bytes_written < 0)          // só agora verifica erro
            return (1);                // erro de escrita
    }
    return (0);
}

