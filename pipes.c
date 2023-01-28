/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:35 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/28 16:50:55 by jeluiz4          ###   ########.fr       */
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
		execve(inp->cmd, inp->temp, blk->envp);
}

void	ft_process(t_shell *blk, t_input *inp, int i)
{
	int		pid;
	int		pipes[2];

	if (pipe(pipes) == -1)
		perror("VEM DE ERRO NO PIPE MEU AMOR");
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
		wait(NULL);
	}
}

void	ft_process_end(t_shell *blk, t_input *inp, int i)
{
	int		pid;
	char	**tmp;

	pid = fork();
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
			exit(0);
		}
		else
			execve(inp->cmd, inp->temp, blk->envp);
	}
	if (pid > 0)
		wait(NULL);
}

// Se precisarmos redirecionar para arquivo, blk->fd_pipe vai precisar dar Open
// Tentei testar com outra estrutura, mas parece que e necessario chamar antes
// do while e uma chamada de process_end depois do while.
// ft_process_end - isntrucao de redirecionamento esta em blk, juntamente com o
// const char * para nome de arquivo, esse precisa ser verificado antes de
// vir pra ca lembrar de fechar os fds dentro de blk sao eles
// blk -> stdin_backup
// blk -> stdout_backup
// blk -> fd_in;

void	ft_pipe_routine(t_shell *blk, t_input *inp, int i, int key)
{
	inp->tmp = ft_chase(blk, inp->args[i], -1, 0);
	inp->temp = ft_split(inp->tmp, ' ');
	free(inp->tmp);
	key = ft_switch(blk, inp, i);
	if (key)
		ft_process(blk, inp, i);
	if (key == 42)
		free(inp->cmd);
	wait(&blk->rs);
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
	inp->tmp = ft_chase(blk, inp->args[i], -1 ,0);
	inp->temp = ft_split(inp->tmp, ' ');
	free(inp->tmp);
	key = ft_switch(blk, inp, i);
	if (key)
	{
		ft_process_end(blk, inp, i);
		if (key == 42)
			free(inp->cmd);
		wait(&blk->rs);
	}
	ft_freeing(inp->temp);
	ft_restore_fds(blk);
}
