/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:05:37 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/29 11:24:29 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

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

void	ft_heredoc(t_shell *blk, char *hereword)
{
	int		fd;
	char	*buffer;
	char	*tmp;
	char	*aux;

	fd = open(blk->tmpdoc, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	g_return = -42;
	aux = NULL;
	tmp = ft_here_routine(hereword, aux);
	if (tmp == NULL && g_return == 130)
	{
		close(fd);
		return ;
	}
	buffer = ft_chase(blk, tmp, -1, 0);
	free(tmp);
	write(fd, buffer, ft_strlen(buffer));
	free(buffer);
	close(fd);
}
