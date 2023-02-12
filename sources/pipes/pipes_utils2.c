/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:22:21 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/04 12:23:34 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	ft_end_pipes(t_shell *blk, t_input *inp)
{
	int		i;
	int		return_status;

	return_status = 0;
	i = -1;
	close(blk->fd_in);
	blk->fd_in = dup(0);
	while (++i < inp->size)
	{
		waitpid(blk->pid[i], &return_status, 0);
		if (WIFEXITED(return_status))
			g_return = WEXITSTATUS(return_status);
		if (WIFSIGNALED(return_status))
			g_return = 128 + WTERMSIG(return_status);
	}
	ft_freeing(inp->temp);
	free(blk->pid);
	ft_restore_fds(blk);
}

void	ft_process_error(t_shell *blk, t_input *inp)
{
	int		pid;
	int		pipes[2];

	if ((inp->temp[0][0] == '\0' && !ft_strrchr(blk->aux, '$'))
		|| inp->temp[0][0])
		printf("Command not found %s\n", inp->temp[0]);
	if (pipe(pipes) == -1)
		perror("PIPE CREATION ERROR");
	pid = fork();
	if (pid == 0)
	{
		close(pipes[0]);
		dup2(blk->fd_in, 0);
		dup2(pipes[1], 1);
		printf("%s", "");
		exit(127);
	}
	if (pid > 0)
	{
		close(pipes[1]);
		blk->fd_in = pipes[0];
		blk->pid[blk->rs] = pid;
		blk->rs++;
	}
}

void	ft_pid_control(t_shell *blk, int pid)
{
		blk->pid[blk->rs] = pid;
		blk->rs++;
}
