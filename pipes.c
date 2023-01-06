/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:35 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/06 19:21:27 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

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
		//printf("ABSOLUTE PATH SUPREMACY\n");
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
		return (0);
	}
	return (-1);
}

void	ft_process(t_shell *blk, t_input *inp)
{
	int		pid;
	int		pipes[2];

	if (pipe(pipes) == -1)
		perror("VEM DE ERRO NO PIPE MEU AMOR");
	pid = fork();
	if (pid == 0)
	{
		close(pipes[0]);
		dup2(pipes[1], 1);
		dup2(blk->fd_pipe, 0);
		if (ft_is_builtin(blk, inp->temp))
		{
			built_run(inp, blk, inp->temp);
			exit(0);
		}
		else
			execve(inp->cmd, inp->temp, blk->envp);
	}
	if (pid > 0)
	{
		close(pipes[1]);
		blk->fd_pipe = pipes[0];
	}
}

void	ft_process_end(t_shell *blk, t_input *inp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(blk->fd_pipe, 0);
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
void	ft_pipe_handle(t_shell *blk, t_input *inp)
{
	int	i;

	blk->fd_pipe = dup(0);
	i = 0;
	inp->temp = ft_split(inp->args[0], ' ');
	//if (ft_access_pipe(blk, inp, i))
	if (ft_switch(blk, inp, i))
		ft_process(blk, inp);
	while (++i < (inp->size - 1))
	{
		inp->temp = ft_split(inp->args[i], ' ');
		//if (ft_access_pipe(blk, inp, i))
		if (ft_switch(blk, inp, i))
			ft_process(blk, inp);
		wait(&blk->rs);
		ft_freeing(inp->temp);
	}
	inp->temp = ft_split(inp->args[i], ' ');
	//if (ft_access_pipe(blk, inp, i))
	if (ft_switch(blk, inp, i))
	{
		ft_process_end(blk, inp);
		wait(&blk->rs);
	}
	ft_freeing(inp->temp);
}
