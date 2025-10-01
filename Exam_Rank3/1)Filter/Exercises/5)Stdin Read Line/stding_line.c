/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stding_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:01:16 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/01 16:10:19 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int main(void)
{
    char line_letter;
    int idx;

    while((idx = read(0,&line_letter, 1)) > 0)
    {
        write(1, &line_letter, 1);

        if(line_letter == '\n')
            break;
    }

}