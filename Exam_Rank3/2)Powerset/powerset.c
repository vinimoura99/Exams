/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:15:39 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/15 13:18:07 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int *set;       // array of numbers
int total;        // total numbers
int target;   // target sum
int *sub;     // temporary subset

void generate(int index, int current_sum, int subset_size)
{
    if (index == total)
    {
        if (current_sum == target)
        {
            for (int i = 0; i < subset_size; i++)
            {
                if (i > 0) 
                    printf(" ");
                    
                printf("%d", sub[i]);
            }
            printf("\n");
        }
        return;
    }

    // Do not include current number
    generate(index + 1, current_sum, subset_size);

    // Include current number
    sub[subset_size] = set[index];
    generate(index + 1, current_sum + set[index], subset_size + 1);
}

int main(int argc, char **argv)
{
    if (argc < 2) return 0;

    target = atoi(argv[1]);
    total = argc - 2;

    set = malloc(total * sizeof(int));
    sub = malloc(total * sizeof(int));
    if (!set || !sub) return 1;

    for (int i = 0; i < total; i++)
        set[i] = atoi(argv[i + 2]);

    generate(0, 0, 0);

    free(set);
    free(sub);
}
