/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:35 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/04 20:59:51 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

int	ft_beg_exec(t_input *inp, t_shell *blk)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(blk->fd[0]);
		dup2(blk->fd[1], STDOUT_FILENO);
		execve(inp->cmd, inp->temp, blk->envp);
	}
	else if ((pid > 0) && (pid != -1))
	{
		close(blk->fd[1]);
		dup2(blk->fd[0], STDIN_FILENO);
		wait(&blk->rs);
		ft_freeing(inp->temp);
		return (blk->rs);
	}
	perror("fork crash");
	return (127);
}

int	ft_end_exec(t_input *inp, t_shell *blk)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(blk->fd[1]);
		dup2(blk->fd[0], STDIN_FILENO);
		execve(inp->cmd, inp->temp, blk->envp);
	}
	else if ((pid > 0) && (pid != -1))
	{
		close(blk->fd[0]);
		dup2(blk->fd[1], STDOUT_FILENO);
		wait(&blk->rs);
		ft_freeing(inp->temp);
		return (blk->rs);
	}
	perror("fork crash");
	return (127);
}

int	ft_mid_exec(t_input *inp, t_shell *blk)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(blk->fd[0], STDIN_FILENO);
		dup2(blk->fd[1], STDOUT_FILENO);
		execve(inp->cmd, inp->temp, blk->envp);
	}
	else if ((pid > 0) && (pid != -1))
	{
		wait(&blk->rs);
		return (blk->rs);
	}
	perror("fork crash");
	return (127);
}

int	ft_build_path(t_shell *blk, t_input *inp)
{
	int	i;

	i = 0;
	inp->paths = ft_split(inp->cmd + 5, ':');
	inp->tmp = ft_strjoin("/", inp->temp[0]);
	free(inp->cmd);
	while (inp->paths[i])
	{
		inp->cmd = ft_strjoin(inp->paths[i], inp->tmp);
		if (!access(inp->cmd, X_OK))
			return (1);
		free(inp->cmd);
		i++;
	}
	blk->rs = 1;
	free(inp->tmp);
	ft_freeing(inp->paths);
	return (0);
}

int	ft_access_pipe(t_shell *blk, t_input *inp, int i)
{
	inp->cmd = ft_search(blk->envp, "PATH=");
	if (!access(inp->temp[i], X_OK))
	{
		if (inp->cmd != NULL)
			free(inp->cmd);
		inp->cmd = inp->temp[i];
		blk->rs = 0;
		printf("ABSOLUTE PATH SUPREMACY\n");
		return (1);
	}
	else if (inp->cmd != NULL)
	{
		return (ft_build_path(blk, inp));
	}
	else if (inp->cmd == NULL)
	{
		perror("PATH VARIABLE NOT FOUND");
		blk->rs = 1;
		return(0);
	}
	return (-1);
}

void ft_process(t_shell *blk, t_input *inp)
{
	int pid;
	int pipes[2];

	pipe(pipes);
	pid = fork();

	if (pid == 0)
	{
		close(pipes[0]);
		dup2(pipes[1], 1);
		execve(inp->cmd, inp->temp, blk->envp);
	}
	if (pid > 0)
	{
		close(pipes[1]);
		dup2(pipes[0], 0);
	}
}

void ft_process_end(t_shell *blk, t_input *inp)
{
	int pid;
	int pipes[2];

	pipe(pipes);
	pid = fork();
	blk->i = 0;
	inp->size = 0;

	if (pid == 0)
	{
		close(pipes[0]);
		dup2(pipes[1], 1);
		write(0, "ls -la | grep main", 18);
		//execve(inp->cmd, inp->temp, blk->envp);
	}
	if (pid > 0)
	{
		close(pipes[1]);
		dup2(1, pipes[0]);
		//write(1, "", 18);
	}
}

void	ft_pipe_handle(t_shell *blk, t_input *inp)
{
	int	i;

	i = 0;
	inp->temp = ft_split(inp->args[0], ' ');
	if(ft_access_pipe(blk, inp, i))
		ft_process(blk, inp);
		//ft_beg_exec(inp, blk);
	while (++i < (inp->size - 1))
	{
		inp->temp = ft_split(inp->args[i], ' ');
		if (ft_access_pipe(blk, inp, i))
			ft_process(blk, inp);
		wait(&blk->rs);
		ft_freeing(inp->temp);
	}
	inp->temp = ft_split(inp->args[i], ' ');
	if (ft_access_pipe(blk, inp, i))
	{
		ft_process_end(blk, inp);
		wait(&blk->rs);
	}
	//ft_freeing(inp->temp);
}
