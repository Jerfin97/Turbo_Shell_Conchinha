/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:54:05 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/07 11:56:57 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

int	ft_switch(t_shell *blk, t_input *inp, int i)
{
	if (ft_is_builtin(blk, inp->temp))
		return (1);
	else if (ft_access_pipe(blk, inp, i))
		return (1);
	return (0);
}

void	ft_restore_fds(t_shell *blk)
{
	dup2(blk->stdin_backup, 0);
	dup2(blk->stdout_backup, 1);
}

//Esse redirecionador funciona caso exista heredoc ou infile setado dentro de
//blk fazendo o input padrao ser heredoc ou infile, como preferir.

void	ft_redirect_infile(t_shell *blk)
{
	blk->fd_in = dup(0);
	if (blk->heredoc_name)
	{
		ft_heredoc(blk, blk->heredoc_name);
		blk->fd_in = open(blk->heredoc_name, O_RDONLY);
		close(0);
		dup2(blk->fd_in, 0);
	}
	if (blk->infilename)
	{
		blk->fd_in = open(blk->infilename, O_RDONLY);
		close(0);
		dup2(blk->fd_in, 0);
	}
}
