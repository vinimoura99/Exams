/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:19:35 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/09/30 14:23:35 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int N;

    // 1. Verificação do Argumento
    if (argc != 2) {
        return 1; // Sem mensagens de erro
    }

    // 2. Obtenção da Dimensão (N)
    N = atoi(argv[1]);

    if (N <= 0) {
        return 1; // Sem mensagens de erro
    }

    // 3. Definição da Matriz
    int matriz[N][N];

    // 4. Preenchimento da Matriz
    // MUDANÇA: usar i + j em vez de (i + 1) * (j + 1)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = i + j;
        }
    }

    // 5. Impressão da Matriz
    // MUDANÇA: remover texto extra
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // MUDANÇA: formato simples sem espaços extras
            printf("%d", matriz[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}