/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:35:33 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/30 16:27:17 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	built_run(t_input *inp, t_shell *blk)
{
	// ECHO
	if (!strncmp(inp->args[0],"echo", 5))
		ft_echo(blk, inp);
	// CD
	else if (!strncmp(inp->args[0],"cd", 3))
		ft_cd(blk, inp->args[1]);
	// ENV
	else if (!strncmp(inp->args[0],"env", 4))
		ft_printenv(blk);
	//PWD
	else if (!strncmp(inp->args[0],"pwd", 4))
		ft_pwd(blk);
	// EXPORT
	else if (!strncmp(inp->args[0],"export", 7))
		ft_export(blk, "VAL=", "5");
	// UNSET
	else if (!strncmp(inp->args[0],"unset", 6))
		ft_unset(blk, inp->args[1]);
	// EXIT
	else if (!strncmp(inp->args[0],"exit", 5) || blk->buf == NULL)
		ft_exit(inp, blk);
}

void	ft_lexer(t_shell *blk, t_input *inp)
{
	if	(blk->buf && *blk->buf)
	{
		printf("lexer %s -- %d\n", blk->buf, inp->exit_error);
		inp->args = ft_split(blk->buf, ' ');
		built_run(inp, blk);
		ft_freeing(inp->args);
	}
	ft_exit_d(blk);
	return ;
}
