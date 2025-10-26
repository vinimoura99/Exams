/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:45:34 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/26 11:46:42 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
    write(1, "\n", 1);
}

void solve(char *s, int i, int left, int right, int open)
{
    if (!s[i])
    {
        if (left == 0 && right == 0 && open == 0)
            ft_putstr(s);
        return;
    }

    if (s[i] == '(')
    {
        if (left > 0)
        {
            char tmp = s[i];
            s[i] = ' ';
            solve(s, i + 1, left - 1, right, open);
            s[i] = tmp;
        }
        solve(s, i + 1, left, right, open + 1);
    }
    else if (s[i] == ')')
    {
        if (right > 0)
        {
            char tmp = s[i];
            s[i] = ' ';
            solve(s, i + 1, left, right - 1, open);
            s[i] = tmp;
        }
        if (open > 0)
            solve(s, i + 1, left, right, open - 1);
    }
    else
        solve(s, i + 1, left, right, open);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    char *s = av[1];
    int left = 0, right = 0;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(')
            left++;
        else if (s[i] == ')')
        {
            if (left > 0) left--;
            else right++;
        }
    }

    solve(s, 0, left, right, 0);
    
    return 0;
}
