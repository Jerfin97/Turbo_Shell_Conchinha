/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:05:37 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/29 09:11:43 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// Heredoc_Handler
// abrir um arquivo e escrever nele oque esta no prompt
// Precisa aplicar as funcionalidades do original como imprimir em stdout

void ft_heredoc(t_shell *blk, char *hereword)
{
	int		fd;
	char	*buffer;
	
	fd = open(blk->tmpdoc, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	buffer = readline("heredoc> ");
	while(1)
		{
			if(ft_strcmp(hereword, buffer) == 0)
				break;
			write(fd, buffer, ft_strlen(buffer));
			write(fd, "\n", 1);
			buffer = readline("heredoc> ");
	}
	free(buffer);
	close(fd);
}
