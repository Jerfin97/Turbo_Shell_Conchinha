/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:31:12 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/01 16:52:54 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	ft_build_exec(t_shell *blk, t_input *inp)
{
	int	i;

	i = 0;
	inp->paths = ft_split(inp->cmd + 5, ':');
	inp->tmp = ft_strjoin("/", inp->args[0]);
	while (inp->paths[i])
	{
		free(inp->cmd);
		inp->cmd = ft_strjoin(inp->paths[i], inp->tmp);
		if (!access(inp->cmd, X_OK))
		{
			g_return = ft_exec(inp, blk);
			blk->ctrl = 0;
			free(inp->cmd);
			free(inp->tmp);
			ft_freeing(inp->paths);
			return ;
		}
		i++;
	}
	blk->ctrl = 1;
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

void	ft_abs_path_supremacy(t_input *inp, t_shell *blk)
{
	if (inp->cmd != NULL)
		free(inp->cmd);
	inp->cmd = inp->args[0];
	g_return = 0;
	if (ft_is_dir(inp->args[0]))
		ft_exec(inp, blk);
	else
	{
		printf("%s :Is a directory\n", inp->args[0]);
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
		if (blk->ctrl == 0)
			return ;
	}
	if (blk->ctrl == 1 || (inp->args[0][0] != '\0') || (inp->args[0][0] != ' '))
	{
		free(inp->cmd);
		perror("PATH NOT FOUND");
		g_return = 127;
	}
}

int	ft_exec(t_input *inp, t_shell *blk)
{
	int	pid;
	int	return_status;

	pid = fork();
	if (pid == 0)
	{
		ft_child_signal();
		execve(inp->cmd, inp->args, blk->envp);
	}
	else if ((pid > 0) && (pid != -1))
	{
		waitpid(0, &return_status, 0);
		if (WIFEXITED(return_status))
			g_return = WEXITSTATUS(return_status);
		if (WIFSIGNALED(return_status))
			g_return = 128 + WTERMSIG(return_status);
		return (g_return);
	}
	perror("fork crash");
	return (127);
}
