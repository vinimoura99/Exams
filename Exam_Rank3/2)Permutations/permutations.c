/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:13:26 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/16 09:23:02 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void swap(char *str, char *str2)
{
    char tmp = *str;
    *str = *str2;
    *str2 = tmp;
}


void organize(char *str)
{
    int i,j;
    int len = strlen(str);

    for(i = 0; i < len; i++)
    {
        for(j = i + 1; j < len;j++)
        {
            if(str[i] > str[j])
            {
                swap(&str[i],&str[j]);
            }
        }
    }
}

void permute(char *str, int start, int end)
{
    int i;    

    if(start == end)
    {
        write(1, str, end + 1);
        write(1, "\n", 1);
        return;
    }

    i = start;
    while(i <= end)
    {
        swap(&str[start], &str[i]);
        permute(str, start + 1, end);
        swap(&str[start], &str[i]);
        i++;

    }
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *str = av[1];

        organize(str);
        permute(str, 0, strlen(str) - 1);
    }
    else
        return(1);
} 


 /* // Swap two characters in a string
// Example: 'abc' -> swap a and c -> 'cba'
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

// Sort a string in lexicographical (alphabetical) order
// Example: 'cba' -> 'abc'
void organize(char *str)
{
    int i, j;
    int len = strlen(str);
    
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (str[i] > str[j])
            {
                swap(&str[i], &str[j]);
            }
        }
    }
}

// Generate all permutations of the string using recursion
void permute(char *str, int start, int end)
{
    int i;

    // Base case: if start index reaches end, print the permutation
    if (start == end)
    {
        write(1, str, end + 1);
        write(1, "\n", 1);
        return;
    }

    // Loop through all characters from start to end
    for (i = start; i <= end; i++)
    {
        swap(&str[start], &str[i]);        // Swap current character with start
        permute(str, start + 1, end);      // Recurse for the rest of the string
        swap(&str[start], &str[i]);        // Backtrack: restore original order
    }
}

int main(int ac, char **av)
{
    // Check if a string was provided
    if (ac != 2)
        return 0;

    char *str = av[1];

    // Step 1: sort the string lexicographically
    organize(str);

    // Step 2: generate and print all permutations
    permute(str, 0, strlen(str) - 1);

    return 0;
} */
 