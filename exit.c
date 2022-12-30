/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:24:41 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/30 16:28:44 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_exit(t_input *inp, t_shell *blk)
{
	if (!ft_strncmp(inp->args[0], "exit", 4))
	{
		ft_freeing(inp->args);
		free(blk->buf);
		write(1, "exit\n", 5);
		blk->rs = 0;
		exit(blk->rs);
	}
}

void	ft_exit_d(t_shell *blk)
{
	if (blk->buf == NULL)
	{
		free(blk->buf);
		write(1, "exit\n", 4);
		blk->rs = 0;
		exit(blk->rs);
	}
}
