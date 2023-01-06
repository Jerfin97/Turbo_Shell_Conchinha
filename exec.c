/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:31:12 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/06 10:37:54 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// A Ideia é só chamar o exec pra forkar e executar o comando.
// E retornar o signal 0 se der bom ou o de erro Caso de merda.

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
			blk->rs = 0;
			free(inp->cmd);
			free(inp->tmp);
			ft_freeing(inp->paths);
			return ;
		}
		free(inp->cmd);
		i++;
	}
	blk->rs = 1;
	free(inp->tmp);
	ft_freeing(inp->paths);
}

void	ft_access(t_shell *blk, t_input *inp)
{
	inp->cmd = ft_search(blk->envp, "PATH=");
	if (!access(inp->args[0], X_OK))
	{
		if (inp->cmd != NULL)
			free(inp->cmd);
		inp->cmd = inp->args[0];
		blk->rs = 0;
		printf("ABSOLUTE PATH SUPREMACY\n");
		ft_exec(inp, blk);
	}
	else if (inp->cmd != NULL)
	{
		ft_build_exec(blk, inp);
	}
	if ((inp->cmd != NULL) & (blk->rs == 1))
	{
		perror("PATH NOT FOUND");
		blk->rs = 1;
	}
}

int	ft_exec(t_input *inp, t_shell *blk)
{
	int	pid;

	pid = fork();
	//inp->cmd = inp->args[0];
	if (pid == 0)
	{
		execve(inp->cmd, inp->args, blk->envp);
	}
	else if ((pid > 0) && (pid != -1))
	{
		wait(&blk->rs);
		return (blk->rs);
	}
	perror("fork crash");
	//ft_exec("./a.out",inp, blk);
	return (127);
}
