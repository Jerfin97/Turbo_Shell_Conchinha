/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:24:41 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/03 21:28:36 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	free_end(t_shell *blk, t_input *inp)
{	
	ft_freeing(inp->args);
	free(blk->aux);
	free(blk->buf);
	free(blk->pwd);
	ft_freeing(blk->envp);
	free(blk);
	free(inp);
	write(1, "exit\n", 5);
	g_return = 0;
	exit(g_return);
}

void	ft_exit(t_input *inp, t_shell *blk, char **args)
{
	long int	*pop;

	if (args[2] != NULL)
	{
		g_return = 1;
		perror("Conchinha: exit: numero excessivo de argumentos");
		return ;
	}
	if (args[1] != NULL)
	{
		pop = ft_a_rlylong_int(args[1], 0, 0LL);
		if (pop == NULL)
		{
			free (pop);
			printf("Conchinha: exit: %s: requer argumento numerico\n", args[1]);
			exit(2);
		}
		g_return = pop[0];
		free(pop);
		exit(g_return);
	}
	if (!ft_strncmp(inp->args[0], "exit", 4))
		free_end(blk, inp);
}

void	ft_exit_d(t_shell *blk, t_input *inp)
{
	if (blk->buf == NULL)
	{
		free(blk->buf);
		ft_freeing(blk->envp);
		free(blk->pwd);
		free(blk);
		free(inp);
		write(1, "exit\n", 4);
		exit(g_return);
	}
}
