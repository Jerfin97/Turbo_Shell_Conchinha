/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:31:12 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/30 09:06:40 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_build_exec(t_shell *blk, t_input *inp)
{
	int	i;

	i = 0;
	inp->paths = ft_split(inp->cmd + 5, ':');
	inp->tmp = ft_strjoin("/", inp->args[0]);
	free(inp->cmd);
	while (inp->paths[i])
	{
		inp->cmd = ft_strjoin(inp->paths[i], inp->tmp);
		if (!access(inp->cmd, X_OK))
		{
			ft_exec(inp, blk);
			g_return = 0;
			free(inp->cmd);
			free(inp->tmp);
			ft_freeing(inp->paths);
			return ;
		}
		free(inp->cmd);
		i++;
	}
	g_return = 1;
	free(inp->tmp);
	ft_freeing(inp->paths);
}

int	ft_is_dir(char *path)
{
	void	*fd;

	fd = opendir(path);
	if (fd != NULL)
	{
		closedir(fd);
		return (0);
	}
	return (1);
}

void    ft_abs_path_supremacy(t_input *inp, t_shell *blk)
{
    if (inp->cmd != NULL)
        free(inp->cmd);
    inp->cmd = inp->args[0];
    g_return = 0;
    if (ft_is_dir(inp->args[0]))
        ft_exec(inp, blk);
    else
    {
        perror("PASTA NAO FELLADAPOTA");
        g_return = 126;
    }
}

void	ft_access(t_shell *blk, t_input *inp)
{
	inp->cmd = ft_search(blk->envp, "PATH=");
	if (!access(inp->args[0], X_OK))
	{
		ft_abs_path_supremacy(inp, blk);
		return ;
	}
	else if ((inp->cmd != NULL)
		&& (inp->args[0][0] != '\0') && (inp->args[0][0] != ' '))
	{
		ft_build_exec(blk, inp);
		if (g_return == 0)
			return ;
	}
	if (g_return == 1 || (inp->args[0][0] != '\0') || (inp->args[0][0] != ' '))
	{
		perror("PATH NOT FOUND");
		g_return = 127;
	}
}

int	ft_exec(t_input *inp, t_shell *blk)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(inp->cmd, inp->args, blk->envp);
	}
	else if ((pid > 0) && (pid != -1))
	{
		wait((int*)g_return);
		return (g_return);
	}
	perror("fork crash");
	return (127);
}
