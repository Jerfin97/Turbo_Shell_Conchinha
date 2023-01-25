/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:05:37 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/25 10:39:47 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// Heredoc_Handler
// abrir um arquivo e escrever nele oque esta no prompt
// Precisa aplicar as funcionalidades do original como imprimir em stdout
//
// Dentro de pipes_utils existe um redirecionador para o heredoc

char	*ft_here_routine(char *hereword)
{
	char	*buffer;
	char	*aux;

	aux = ft_calloc(1, 1);
	while (42)
	{
		buffer = readline("heredoc> ");
		if (buffer == NULL)
		{
			free(buffer);
			break ;
		}
		if (ft_strcmp(hereword, buffer) == 0)
		{
			free(buffer);
			break ;
		}
		ft_swapjoin(&aux, buffer);
		ft_swapjoin(&aux, "\n");
		free(buffer);
	}
	return (aux);
}

void	ft_heredoc(t_shell *blk, char *hereword)
{
	int		fd;
	char	*buffer;
	char	*tmp;

	fd = open(blk->tmpdoc, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	tmp = ft_here_routine(hereword);
	buffer = ft_chase(blk, tmp);
	free(tmp);
	write(fd, buffer, ft_strlen(buffer));
	free(buffer);
	close(fd);
}
