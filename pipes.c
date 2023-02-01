/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:35 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/01 00:06:01 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_process_do(t_shell *blk, t_input *inp, int i)
{
	char	**tmp;

	if (ft_count_symbols(inp->args[i]) > 0)
	{
		tmp = ft_split_in_redirect(inp->args[i]);
		ft_simple_redirect(blk, inp, tmp, inp->args[i]);
		exit(0);
	}
	else if (ft_is_builtin(blk, inp->temp))
	{
		built_run(inp, blk, inp->temp);
		if (ft_strcmp(inp->temp[0], "exit"))
			exit(0);
	}
	else
	{
		execve(inp->cmd, inp->temp, blk->envp);
		exit(182);
	}
}

void	ft_process(t_shell *blk, t_input *inp, int i)
{
	int		pid;
	int		pipes[2];

	if (pipe(pipes) == -1)
		perror("PIPE CREATION ERROR");
	pid = fork();
	if (pid == 0)
	{
		close(pipes[0]);
		dup2(blk->fd_in, 0);
		dup2(pipes[1], 1);
		ft_process_do(blk, inp, i);
	}
	if (pid > 0)
	{
		close(pipes[1]);
		blk->fd_in = pipes[0];
		//wait((int *)g_return);
	}
}

void	ft_process_end(t_shell *blk, t_input *inp, int i)
{
	int		pid;
	int		out;
	char	**tmp;

	out = 0;
	pid = fork();
	printf("Pre exit %d\n", out);
	if (pid == 0)
	{
		dup2(blk->fd_in, 0);
		if (ft_count_symbols(inp->args[i]) > 0)
		{
			tmp = ft_split_in_redirect(inp->args[i]);
			ft_simple_redirect(blk, inp, tmp, inp->args[i]);
			exit(0);
		}
		if (ft_is_builtin(blk, inp->temp))
		{
			built_run(inp, blk, inp->temp);
			g_return = 50;
			exit(50);
		}
		else
		{
			execve(inp->cmd, inp->temp, blk->envp);
			exit(50);
		}
	}
	if (pid > 0)
	{
		close(blk->fd_in);
		//waitpid(0, &out, WNOHANG);
	}
	printf("Pos exit %d\n", out);
}

void	ft_process_error(t_shell *blk)
{
	int		pid;
	int		pipes[2];

	if (pipe(pipes) == -1)
		perror("PIPE CREATION ERROR");
	pid = fork();
	if (pid == 0)
	{
		close(pipes[0]);
		dup2(blk->fd_in, 0);
		dup2(pipes[1], 1);
		printf("%c", '\0');
		exit(1);
	}
	if (pid > 0)
	{
		close(pipes[1]);
		blk->fd_in = pipes[0];
		wait((int *)g_return);
	}
}

void	ft_pipe_routine(t_shell *blk, t_input *inp, int i, int key)
{
	inp->tmp = ft_chase(blk, inp->args[i], -1, 0);
	inp->temp = ft_split(inp->tmp, ' ');
	free(inp->tmp);
	key = ft_switch(blk, inp, i);
	if (key == 0)
	{
		printf("Command not found %s\n", inp->temp[0]);
		ft_process_error(blk);
	}
	else if (key)
	{
		ft_process(blk, inp, i);
	}
	if (key == 42)
		free(inp->cmd);
	//wait((int *)g_return);
	ft_freeing(inp->temp);
}

void	ft_pipe_handle(t_shell *blk, t_input *inp)
{
	int		i;
	int		key;

	key = 0;
	i = -1;
	while (++i < inp->size - 1)
		ft_pipe_routine(blk, inp, i, key);
	inp->tmp = ft_chase(blk, inp->args[i], -1, 0);
	inp->temp = ft_split(inp->tmp, ' ');
	free(inp->tmp);
	key = ft_switch(blk, inp, i);
	if (key == 0)
	{
		printf("Command not found %s\n", inp->temp[0]);
		ft_process_error(blk);
	}
	else if (key)
	{
		ft_process_end(blk, inp, i);
		if (key == 42)
			free(inp->cmd);
	}
	//i = -1;
	//while (++i < inp->size)
	waitpid(0, (int *)g_return, WNOHANG);
	//	wait(NULL);
	ft_freeing(inp->temp);
	ft_restore_fds(blk);
}
