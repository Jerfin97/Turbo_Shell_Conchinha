/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:31:12 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/29 08:31:50 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// A Ideia é só chamar o exec pra forkar e executar o comando.
// E retornar o signal 0 se der bom ou o de erro Caso de merda.

int	ft_exec(char *cmd, char **args, char **envp, t_shell *blk)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, args, envp);
	}
	else if ((pid > 0) && (pid != -1))
	{
		wait(&blk->rs);
		return (blk->rs);
	}
	perror("fork crash");
	return (127);
}
