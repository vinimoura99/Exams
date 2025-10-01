/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:45:33 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/01 16:28:57 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Lembrar sempre do que a funcao read faz.
read(0, buffer, size)

Aonde sabemos que :
0 -> entrada ( stdin)
buffer -> aonde salvar 
size -> quantidade a salvar */

#include <unistd.h>

int main(void)
{   
    char buffer[1024];
    int n;

    n = read(0, buffer, 1024);

    if (n > 0)
        write(1, buffer, n);
    else
        return 0;
}