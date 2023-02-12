/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:05:37 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/06 18:15:21 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

char	*ft_heredoc_name_generator(int i)
{
	char		*name;
	char		*number;

	number = ft_itoa(i);
	if (!number)
		return (NULL);
	name = ft_strjoin(".here_doc_name", number);
	free(number);
	i++;
	return (name);
}

char	*ft_here_routine(char *hereword, char *aux)
{
	char	*buffer;

	aux = ft_calloc(1, 1);
	while (42)
	{
		buffer = readline("heredoc> ");
		if (g_return == 130 || buffer == NULL)
		{
			free(buffer);
			if (g_return == 130)
				return (free(aux), NULL);
			printf("Conchinha: warning: here-document delimited by");
			printf(" end-of-file (wanted `%s')\n", hereword);
			break ;
		}
		if (!ft_strcmp(hereword, buffer))
			break ;
		ft_swapjoin(&aux, buffer);
		ft_swapjoin(&aux, "\n");
		free(buffer);
	}
	return (free(buffer), aux);
}

int	ft_heredoc_list_add(t_shell *blk, char *heredoc_name, int i, int fd)
{
	blk->heredoc_list[i] = ft_strdup(heredoc_name);
	if (g_return == 130)
	{
		close(fd);
		return (0);
	}
	return (1);
}

void	ft_heredoc_end(char *buffer, char *heredoc_name, char *tmp, int fd)
{
	free(buffer);
	free(heredoc_name);
	free(tmp);
	close(fd);
}

void	ft_heredoc(t_shell *blk, char *hereword, int pos)
{
	int		fd;
	char	*buffer;
	char	*tmp;
	char	*heredoc_name;

	heredoc_name = ft_heredoc_name_generator(pos);
	fd = open(heredoc_name, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		g_return = 1;
	}
	if (!ft_heredoc_list_add(blk, heredoc_name, pos, fd))
		return ;
	tmp = ft_here_routine(hereword, NULL);
	if (tmp == NULL && g_return == 130)
	{
		close(fd);
		return ;
	}
	buffer = ft_chase(blk, tmp, -1, 0);
	write(fd, buffer, ft_strlen(buffer));
	ft_heredoc_end(buffer, heredoc_name, tmp, fd);
}
