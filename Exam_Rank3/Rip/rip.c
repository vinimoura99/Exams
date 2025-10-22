/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:29:56 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/19 16:49:12 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int str_len(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}

void rip(char *str, char *buffer, int pos, int open , int rem, int min_rem, int len)
{
    if(pos == len)
    {
        if(open == 0 && rem == min_rem)
        { 
        write(1, buffer, len);
        write(1, "\n", 1);
        }
    }

    if(rem > min_rem)
        return;
    
    char c = str[pos];

    if(str[pos] == '(')
    {
        buffer[pos] = ' ';
        rip( str,  buffer,  pos + 1 , open  , rem + 1, min_rem, len);
        buffer[pos] = '(';
        rip( str,  buffer,  pos + 1 , open + 1 , rem , min_rem, len);
    }
    else if(str[pos] == ')')    
    {
        buffer[pos] = ' ';
        rip( str,  buffer,  pos + 1 , open  , rem + 1, min_rem, len);
        if(open > 0)
        {
            buffer[pos] = ')';
            rip( str,  buffer,  pos + 1 , open - 1 , rem , min_rem, len);
        }
    }


}
int main(int ac, char **av)
{   
    if(ac == 2)
    {
        char *str = av[1];
        char buffer[100];
        int len = str_len(str);
        int open = 0;
        int min_rem = 0;

        for(int i = 0; i < len; i++)
        {
            if(str[i] == '(')
                open++;

            else if(str[i] == ')')
            {
                if(open > 0)
                    open--;
                else
                    min_rem++;
            }
        }
        min_rem += open;

        rip(str, buffer, 0,0,0,min_rem,len);
    }

    else    
        return(1);
}