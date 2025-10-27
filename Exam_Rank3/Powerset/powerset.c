/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:49:44 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/27 18:25:48 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_subset(int *arr, int *path, int len)
{
	int first = 1;

	for(int i = 0;i < len;i++)
	{
		if (path[i])
		{
			if (!first)
				printf(" ");
			printf("%d", arr[i]);
			first = 0;
		}
	}
	printf("\n");
}
void powerset(int *array, int *path, int len, int idx, int sum, int target)
{
    if(idx == len)
    {
        if(sum == target)
        {
            print_subset(array,path,len);
        }
        return;
    }

    path[idx] = 1;
    powerset(array,path,len,idx + 1,sum + array[idx],target);
    path[idx] = 0;
    powerset(array,path,len,idx + 1,sum,target);
}
int main(int ac, char **av)
{
    if(ac < 3)
        return(1);
    
    int target = atoi(av[1]);
    int len = ac - 2;

    int *array = malloc(sizeof(int) * len);
    int *path = calloc(len,sizeof(int));

    if(!array || !path)
        return(1);
    
    for(int i = 0;i < len;i++)
    {
        array[i] = atoi(av[i + 2]);
    }

    powerset(array,path,len,0,0,target);

    free(array);
    free(path);
    return(0);
    
}