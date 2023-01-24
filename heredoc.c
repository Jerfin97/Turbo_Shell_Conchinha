/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:05:37 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/24 14:05:53 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// Heredoc_Handler
// abrir um arquivo e escrever nele oque esta no prompt
// Precisa aplicar as funcionalidades do original como imprimir em stdout
//
// Dentro de pipes_utils existe um redirecionador para o heredoc

void	ft_heredoc(t_shell *blk, char *hereword)
{
	int		fd;
	char	*buffer;
	char	*tmp;

	fd = open(blk->tmpdoc, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	tmp = calloc(1, 1);
	buffer = readline("heredoc> ");
	while (42)
	{
		if (ft_strcmp(hereword, buffer) == 0)
			break ;
		ft_swapjoin(&tmp, buffer);
		ft_swapjoin(&tmp, "\n");
		buffer = readline("heredoc> ");
	}
	free(buffer);
	buffer = ft_chase(blk, tmp);
	free(tmp);
	write(fd, buffer, ft_strlen(buffer));
	free(buffer);
	close(fd);
}
