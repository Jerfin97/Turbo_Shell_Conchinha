/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:35:33 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/04 13:34:54 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include <stdio.h>

void	built_run(t_input *inp, t_shell *blk)
{
	// ECHO
	if (!strncmp(inp->args[0], "echo", 5))
		ft_echo(blk, inp);
	// CD
	else if (!strncmp(inp->args[0], "cd", 3))
		ft_cd(blk, inp->args[1]);
	// ENV
	else if (!strncmp(inp->args[0], "env", 4))
		ft_printenv(blk);
	//PWD
	else if (!strncmp(inp->args[0], "pwd", 4))
		ft_pwd(blk);
	// EXPORT
	else if (!strncmp(inp->args[0], "export", 7))
		ft_export(blk, "VAL=", "5");
	// UNSET
	else if (!strncmp(inp->args[0], "unset", 6))
		ft_unset(blk, inp->args[1]);
	// EXIT
	else if (!strncmp(inp->args[0], "exit", 5) || blk->buf == NULL)
		ft_exit(inp, blk);
}

int	ft_is_builtin(t_shell *blk, t_input *inp)
{
	if (!strncmp(inp->args[0], "echo", 5))
		return (1);
	else if (!strncmp(inp->args[0], "cd", 3))
		return (1);
	else if (!strncmp(inp->args[0], "env", 4))
		return (1);
	else if (!strncmp(inp->args[0], "pwd", 4))
		return (1);
	else if (!strncmp(inp->args[0], "export", 7))
		return (1);
	else if (!strncmp(inp->args[0], "unset", 6))
		return (1);
	else if (!strncmp(inp->args[0], "exit", 5) || blk->buf == NULL)
		return (1);
	return (0);
}

int	ft_has_pipes(char *str)
{
	int		i;
	int		pipe;

	i = 0;
	pipe = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			pipe++;
			if (str[i + 1] == '|')
				return (-1);
		}
		i++;
	}
	return (pipe);
}

char	**ft_create_args(t_shell *blk)
{
	char	**ret;

	if (ft_has_pipes(blk->buf) == -1)
		return (perror("VERIFICAR ERNANI"), NULL);
	if (ft_has_pipes(blk->buf) > 0)
		return (ret = ft_split(blk->buf, '|'));
	else
		return (ret = ft_split(blk->buf, ' '));
}

void	ft_lexer(t_shell *blk, t_input *inp)
{
	if (blk->buf && *blk->buf)
	{
		inp->args = ft_create_args(blk);
		if (!inp->args)
			return ;
		while (inp->args[inp->size])
			inp->size++;
		if (ft_is_builtin(blk, inp))
			built_run(inp, blk);
		else
			ft_access(blk, inp);
		ft_freeing(inp->args);
	}
	ft_exit_d(blk);
	return ;
}
