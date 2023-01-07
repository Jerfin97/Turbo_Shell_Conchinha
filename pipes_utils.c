/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:25:52 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/07 11:43:16 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_restore_fds(t_shell *blk)
{
	dup2(blk->stdin_backup, 0);
	dup2(blk->stdout_backup, 1);
}

void	ft_redirect_infile(t_shell *blk)
{
	blk->fd_in = dup(0);
	if (blk->infilename)
	{
		blk->fd_in = open(blk->infilename, O_RDONLY);
		close(0);
		dup2(blk->fd_in, 0);
	}
}
