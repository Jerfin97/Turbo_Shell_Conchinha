/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:54:05 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/30 10:05:50 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

int	ft_switch(t_shell *blk, t_input *inp, int i)
{
	if (ft_count_symbols(inp->args[i]) > 0)
		return (1);
	else if (ft_is_builtin(blk, inp->temp))
		return (1);
	else if (ft_access_pipe(blk, inp))
		return (42);
	return (0);
}

void	ft_restore_fds(t_shell *blk)
{
	dup2(blk->stdin_backup, 0);
	dup2(blk->stdout_backup, 1);
}

int	ft_build_path(t_shell *blk, t_input *inp)
{
	int	i;

	i = 0;
	inp->paths = ft_split(inp->cmd + 5, ':');
	inp->tmp = ft_strjoin("/", inp->temp[0]);
	while (inp->paths[i])
	{
		free(inp->cmd);
		inp->cmd = ft_strjoin(inp->paths[i], inp->tmp);
		if (!access(inp->cmd, X_OK))
		{
			free(inp->tmp);
			ft_freeing(inp->paths);
			return (1);
		}
		i++;
	}
	g_return = 1;
	free(inp->tmp);
	ft_freeing(inp->paths);
	return (0);
}

int	ft_abs_path_pipe(t_input *inp, t_shell *blk)
{
	if (inp->cmd != NULL)
		free(inp->cmd);
	inp->cmd = ft_strdup(inp->temp[0]);
	g_return = 0;
	if (ft_is_dir(inp->temp[0]))
		return (1);
	else
	{
		perror("PASTA NAO MERMAO NO PIPE AINDA ");
		g_return = 126;
	}
	return (0);
}

int	ft_access_pipe(t_shell *blk, t_input *inp)
{
	inp->cmd = ft_search(blk->envp, "PATH=");
	if (!access(inp->temp[0], X_OK))
		return (ft_abs_path_pipe(inp, blk));
	else if (inp->cmd != NULL)
		return (ft_build_path(blk, inp));
	else if (inp->cmd == NULL)
	{
		perror("PATH VARIABLE NOT FOUND");
		g_return = 1;
		return (0);
	}
	return (-1);
}
