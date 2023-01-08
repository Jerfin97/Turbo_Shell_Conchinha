/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:35 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/07 11:42:12 by dvargas          ###   ########.fr       */
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
		dup2(blk->fd_in, 0);
		dup2(pipes[1], 1);
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
		blk->fd_in = pipes[0];
		wait(NULL);
	}
}

void	ft_process_end(t_shell *blk, t_input *inp)
{
	int		pid;
	int		fileout;

	pid = fork();
	if (pid == 0)
	{
		dup2(blk->fd_in, 0);
		if (blk->redirect == 1)
		{
			fileout = open("TESTE123.txt", O_TRUNC | O_CREAT | O_WRONLY, 0777);
			dup2(fileout, 1);
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
	{
		wait(NULL);
	}
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

void	ft_pipe_handle(t_shell *blk, t_input *inp)
{
	int		i;

	ft_redirect_infile(blk);
	i = -1;
	while (++i < inp->size - 1)
	{
		inp->temp = ft_split(inp->args[i], ' ');
		if (ft_switch(blk, inp, i))
			ft_process(blk, inp);
		wait(&blk->rs);
		ft_freeing(inp->temp);
	}
	inp->temp = ft_split(inp->args[i], ' ');
	if (ft_switch(blk, inp, i))
	{
		ft_process_end(blk, inp);
		wait(&blk->rs);
	}
	ft_freeing(inp->temp);
	ft_restore_fds(blk);
}
