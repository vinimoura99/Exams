/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:09:22 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/10/17 12:31:59 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "broken_GNL.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//localizar a primeira ocorrência de um caractere específico dentro de uma string.
char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c) //Adicionar a condicional s[i];
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

//A função memcpy() (Memory Copy) é usada para copiar um bloco de bytes de uma área da memória para outra.
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

//Usada para calcular tamanho de str
size_t	ft_strlen(char *s)
{
	size_t	ret = 0;
	if(!s)
	{
		return 0;
	}
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

//É um protótipo de função não-padrão (ou seja, não faz parte da biblioteca C normal)
//que combina a funcionalidade de manipulação de memória de baixo nível (memcpy) com a manipulação de strings.
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

//é uma função customizada, não-padrão da biblioteca C,
// projetada para anexar (concatenar) uma string (s2) ao final de outra string (*s1), 
// gerenciando a alocação de memória dinamicamente.
int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

//O propósito principal de ft_memmove é copiar n bytes de um bloco de memória de origem (src) 
// para um bloco de memória de destino (dest), garantindo que a cópia funcione corretamente mesmo 
// que as duas áreas de memória se sobreponham.
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

	char	*tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, b))		
			return (NULL);		
			
		int	read_ret = read(fd, b, BUFFER_SIZE); //Leitura

		if (read_ret <= 0) 
		{
			free(ret);
			return (NULL);
		}			

		b[read_ret] = 0;		
		tmp = ft_strchr(b, '\n'); //Adicionar
	}

	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	
	ft_memmove(b, tmp + 1,ft_strlen(tmp + 1) + 1); //Adionar
	return (ret);
}


//Usada so para testarmos se esta tudo certo , nao sera usada nem dada
// main corrigido e simplificado para testar
int main(int ac, char **av) // Adicionar argumentos para o checker
{
    int fd;
    char *line;
    
    // Seu checker passa o arquivo no av[1]
    if (ac < 2) 
    {
        printf("Uso: %s <caminho_do_arquivo>\n", av[0]);
        return 1;
    }

    // Abertura do arquivo passado pelo checker
    fd = open(av[1], O_RDONLY);

    if (fd < 0)
    {
        perror("Error");
        return(1);
    }
    
    // O seu loop deve parar quando line for NULL (0) e liberar a memória!
    while(1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break; // Sai do loop se NULL (fim de arquivo ou erro)

        printf("Line : %s", line); // Note que o printf aqui não tem '\n' no final
        free(line); // LIBERAR A MEMÓRIA AQUI!
    }

    close(fd);
    return(0);
}