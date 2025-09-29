/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search_and_Replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:20:08 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/09/29 17:43:33 by vmoura-d         ###   ########.fr       */
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

void search_and_replace(char *str, char *find)
{
    int i=0;
    int j;

    while(str[i])
    {   
        j = 0;

        if(str[i] == find[j])
        {
            int new_pos = 0;
            
            while(str[i + new_pos] == find[j] && find[j] != '\0')
            {
                new_pos++;
                j++;
            }

            if(find[j] == '\0')
            {
                int count = str_len(find);
                int count2 = 0;

                while(count2 < count)
                {
                    write(1, "*", 1);
                    count2++;
                }
                i += new_pos;
            }
            else
            {
                write(1, &str[i], 1);
                i++;
            }
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
       
            
        
    }
    write(1, "\n",1);
}

int main(int ac, char **av)
{
    if(ac == 3)
    {
        search_and_replace(av[1],av[2]);
    }

    //Funny way to do str lenght and return a write with a value without counting on hand
    //Like when wanna do hello world with while and has to count how many letter have to do write(1, str, size);
    else
    {
        char std[] = "error";
        int len = str_len(std);
                
        write(1, &std, len);
    }
        
}