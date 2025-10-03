/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stding_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:01:16 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/03 11:26:33 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int main(void)
{
    char line_letter;
    char line[45000];
    int idx;
    int count = 0;

    while((idx = read(0,&line_letter, 1)) > 0)
    {
        line[count++] = line_letter;      

        if(line_letter == '\n')
            write(1, &line, count);
        
    }

}