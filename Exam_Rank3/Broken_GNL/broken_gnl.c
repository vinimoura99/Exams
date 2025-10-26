/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:09:22 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/26 11:10:19 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "broken_GNL.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret = 0;
	if(!s)
		return(0);
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	else
		return (ft_memcpy(dest, src, n));
	
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp;

	while (!(tmp = ft_strchr(b, '\n')))
	{
		if(*b)
		{
			if (!str_append_str(&ret, b))
			return (NULL);
			b[0] = '\0';
		}	

		int	read_ret = read(fd, b, BUFFER_SIZE);

		if (read_ret == -1)
		{
			free(ret);
			return (NULL);
		}
		if (read_ret == 0)
		{
			return (ret);
		}		

		b[read_ret] = 0;
		/* tmp = ft_strchr(b, '\n'); */
	}

	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	return (ret);
}
int main(int ac, char **av) 
{
    int fd;
    char *line;
    
    
    if (ac < 2) 
    {
        printf("Uso: %s <caminho_do_arquivo>\n", av[0]);
        return 1;
    }

    
    fd = open(av[1], O_RDONLY);

    if (fd < 0)
    {
        perror("Error");
        return(1);
    }
    
    
    while(1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break; 

        printf("Line : %s", line);
        free(line); 
    }

    close(fd);
    return(0);
}