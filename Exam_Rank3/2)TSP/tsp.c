/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:47:08 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/15 13:47:09 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Calcula a distância euclidiana entre dois pontos
float distance(float x1, float y1, float x2, float y2)
{
    float dx = x1 - x2;
    float dy = y1 - y2;
    return sqrtf(dx*dx + dy*dy);
}

// Calcula o comprimento total de um caminho
float path_length(float *x, float *y, int *perm, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n; // volta para o início
        sum += distance(x[perm[i]], y[perm[i]], x[perm[j]], y[perm[j]]);
    }
    return sum;
}

// Gera todas as permutações e encontra a menor
void permute(float *x, float *y, int *perm, int start, int n, float *best)
{
    if (start == n)
    {
        float len = path_length(x, y, perm, n);
        if (len < *best)
            *best = len;
        return;
    }

    for (int i = start; i < n; i++)
    {
        int temp = perm[start];
        perm[start] = perm[i];
        perm[i] = temp;

        permute(x, y, perm, start + 1, n, best);

        // desfaz a troca
        temp = perm[start];
        perm[start] = perm[i];
        perm[i] = temp;
    }
}

int main(void)
{
    float x[11], y[11];
    int n = 0;

    // lê até 11 cidades
    while (n < 11 && scanf("%f, %f\n", &x[n], &y[n]) == 2)
        n++;

    int perm[11];
    for (int i = 0; i < n; i++)
        perm[i] = i;

    float best = 1e9; // inicializa com número grande
    permute(x, y, perm, 0, n, &best);

    printf("%.2f\n", best);
}
