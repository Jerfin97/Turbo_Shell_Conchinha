/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:35:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 17:08:23 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	free(s1);
	return (newstr);
}

char	*beautiful(char **sbuffer)
{
	char	*string;
	int		npos;

	npos = lf_count(*sbuffer);
	if (npos != -1)
	{
		string = ft_gnlsubstr(*sbuffer, 0, npos + 1);
		*sbuffer = ft_substr2(*sbuffer, npos + 1,
				ft_strlen(*sbuffer) - (npos + 1));
	}
	else
	{
		string = ft_gnlsubstr(*sbuffer, 0, ft_strlen(*sbuffer));
		free(*sbuffer);
		*sbuffer = NULL;
	}
	if (ft_strlen(string) == 0)
	{
		free(string);
		return (NULL);
	}
	return (string);
}

char	*callmeloc(char *str)
{
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytes_read;
	static char	*sbuffer[4096];

	if (fd < 0 || BUFFER_SIZE < -1)
		return (NULL);
	if (!sbuffer[fd])
		sbuffer[fd] = callmeloc(sbuffer[fd]);
	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (bytes_read)
	{
		if (lf_count(sbuffer[fd]) > 1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0';
		sbuffer[fd] = ft_gnlstrjoin(sbuffer[fd], buffer);
	}
	free(buffer);
	return (beautiful(&sbuffer[fd]));
}

// erro no read é -1
/*
 *GET NEXT LINE
 * O objetivo dessa função é imprimir o conteúdo de um arquivo de texto linha 
 * por linha com auxilio da funcao
 * read, aqui só será liberada a utilização das funcoes READ , MALLOC , FREE
 * Esse é meu primeiro esboço de como abordar o caso da GNL.
 *
 * A função Read tem os seguintes parametros "ssize_t read(int fd, void *buf, 
 * size_t count)"
 *
 * File descriptors só existem acima de 0 logo se FD < 0 deve retornar NULL
 * Se nao tivermos linhas o programa deve retornar NULL
 * Se o Buffersize for menor do que zero, retornamos NULL (se for zero tbm?)
 * Se read retornar -1 retornamos NULL
 *
 * A ideia aqui é que não podemos ler o arquivo novamente do inicio 
 * de onde paramos, logo se tiver um /n no meio do nosso
 * buffer precisamos guardar a informação depois dele para ser utilizada, para 
 * isso podemos usar uma
 * variavel do tipo Static
 * ----------------------------
 * Fazemos StrJoin de ReadBuffer(RESULTADO DE READ) para um static StringBuffer 
 * Procuramos um /n no StringBuffer (podemos usar strchr)
 *		SIM -> Monte a linha em uma string de retorno lembrar de delimitar por 
 *		/n
 *		Depois disso Stringbuffer precisa ser malocada com o novo conteúdo (tud
 *		o depois de /n)
 *	Leia um Buffer_size novamente
 * ----------------------------
 * Questões que me vem a cabeça
 * Se o buffer tiver mais do que um /n? criamos uma regra especifica pra isso?
 * R: Sim, podeoms fazer isso dentro da montagem de linha por exemplo.
 *
 *
 * Lembrar -
 * If N Def BUFFER_SIZE 42
 */
