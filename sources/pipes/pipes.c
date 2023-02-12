/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:35 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/04 18:26:57 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

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
		exit(0);
	}
	else
		execve(inp->cmd, inp->temp, blk->envp);
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
		ft_child_signal();
		close(pipes[0]);
		dup2(blk->fd_in, 0);
		dup2(pipes[1], 1);
		ft_process_do(blk, inp, i);
	}
	if (pid > 0)
	{
		close(pipes[1]);
		close(blk->fd_in);
		blk->fd_in = pipes[0];
		blk->pid[blk->rs] = pid;
		blk->rs++;
	}
}

void	ft_process_end(t_shell *blk, t_input *inp, int i)
{
	int		pid;
	char	**tmp;

	pid = fork();
	if (pid == 0)
	{
		blk->doc = blk->qtd - 1;
		ft_child_signal();
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
			exit(0);
		}
		else
			execve(inp->cmd, inp->temp, blk->envp);
	}
	if (pid > 0)
		ft_pid_control(blk, pid);
}

void	ft_pipe_routine(t_shell *blk, t_input *inp, int i, int key)
{
	inp->tmp = ft_chase(blk, inp->args[i], -1, 0);
	inp->temp = ft_split(inp->tmp, ' ');
	free(inp->tmp);
	key = ft_switch(blk, inp, i);
	if (key == 0)
		ft_process_error(blk, inp);
	else if (key)
	{
		ft_process(blk, inp, i);
	}
	if (key == 42)
		free(inp->cmd);
	ft_freeing(inp->temp);
	blk->doc++;
}

void	ft_pipe_handle(t_shell *blk, t_input *inp)
{
	int		i;
	int		key;

	blk->rs = 0;
	key = 0;
	i = -1;
	blk->pid = ft_calloc(sizeof(int), inp->size);
	while (++i < inp->size - 1)
		ft_pipe_routine(blk, inp, i, key);
	inp->tmp = ft_chase(blk, inp->args[i], -1, 0);
	inp->temp = ft_split(inp->tmp, ' ');
	free(inp->tmp);
	key = ft_switch(blk, inp, i);
	if (key == 0)
		ft_process_error(blk, inp);
	else if (key)
	{
		ft_process_end(blk, inp, i);
		if (key == 42)
			free(inp->cmd);
	}
	ft_end_pipes(blk, inp);
}
