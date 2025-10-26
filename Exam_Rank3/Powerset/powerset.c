/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:26:22 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/26 11:44:10 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void print_subset(int *subset, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i > 0) 
            printf(" ");
        printf("%d", subset[i]);
    }
    printf("\n");
}

void powerset_simple(int *set, int set_len, int *subset, int subset_len, int target)
{
    // soma o subconjunto atual
    int sum = 0;
    
    for (int i = 0; i < subset_len; i++)
        sum += subset[i];

    // se bate com o alvo, imprime
    if (sum == target)
        print_subset(subset, subset_len);

    // para cada número ainda não incluído, tenta incluí-lo
    for (int i = subset_len; i < set_len; i++)
    {
        subset[subset_len] = set[i];
        powerset_simple(set, set_len, subset, subset_len + 1, target);
    }
}

int main(int argc, char **argv)
{
    if (argc < 3) 
        return 1;

    int target = atoi(argv[1]);
    int set_len = argc - 2;
    int *set = malloc(sizeof(int) * set_len);
    int *subset = malloc(sizeof(int) * set_len);

    if (!set || !subset)
         return 1;

    for (int i = 0; i < set_len; i++)
        set[i] = atoi(argv[i + 2]);

    powerset_simple(set, set_len, subset, 0, target);

    free(set);
    free(subset);
    
    return 0;
}
