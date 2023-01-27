/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:54:05 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/27 10:16:28 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

int	ft_switch(t_shell *blk, t_input *inp, int i)
{
	if (ft_count_symbols(inp->args[i]) > 0)
		return (1);
	else if (ft_is_builtin(blk, inp->temp))
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
