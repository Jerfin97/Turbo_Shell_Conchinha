/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:35:33 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/28 16:50:12 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	built_run(t_input *inp, t_shell *blk, char **args)
{
	// ECHO
	if (!ft_strcmp(args[0], "echo"))
		ft_echo(blk, inp, args);
	// CD
	else if (!ft_strcmp(args[0], "cd"))
		ft_cd(blk, args[1], args);
	// ENV
	else if (!ft_strcmp(args[0], "env"))
		ft_printenv(blk, args);
	//PWD
	else if (!ft_strcmp(args[0], "pwd"))
		ft_pwd(blk, args);
	// EXPORT
	else if (!ft_strcmp(args[0], "export"))
		ft_cleanse(blk, args);
	// UNSET
	else if (!ft_strcmp(args[0], "unset"))
		ft_unset(blk, args);
	// EXIT
	else if (!ft_strcmp(args[0], "exit") || blk->buf == NULL)
		ft_exit(inp, blk, args);
}

int	ft_is_builtin(t_shell *blk, char **args)
{
	if (!ft_strcmp(args[0], "echo"))
		return (1);
	else if (!ft_strcmp(args[0], "cd"))
		return (1);
	else if (!ft_strcmp(args[0], "env"))
		return (1);
	else if (!ft_strcmp(args[0], "pwd"))
		return (1);
	else if (!ft_strcmp(args[0], "export"))
		return (1);
	else if (!ft_strcmp(args[0], "unset"))
		return (1);
	else if (!ft_strcmp(args[0], "exit") || blk->buf == NULL)
		return (1);
	else if (!ft_strcmp(args[0], "heredoc"))
		return (2);
	return (0);
}

char	**ft_create_args(t_shell *blk)
{
	char	**ret;
	char	*tmp;

	tmp = NULL;
	if (ft_validate_quotes(blk->buf))
		return (perror("CANT FIND CLOSE QUOTES"), NULL);
	else if (ft_find_str(blk->buf, "|") == -1)
		return (perror("VERIFICAR ERNANI | ERRADO"), NULL);
	else if (ft_find_str(blk->buf, "|") > 0)
		return (ret = ft_hand_split(blk->buf, "|"));
	else if (ft_count_symbols(blk->buf) == -1)
		return (perror("ERRRNANI > OU >> ERRADO"), NULL);
	else if (ft_count_symbols(blk->buf) > 0)
		return (ret = ft_split_in_redirect(blk->buf));
	else
	{
		tmp = ft_space_clean(blk->buf);
		if (tmp == NULL)
			return (NULL);
		ret = ft_split_in_spaces(tmp, 0, 0, 0);
		free(tmp);
		return (ret);
	}
}
//lembrar poassar copia de inp args no redirect
void	ft_lexer(t_shell *blk, t_input *inp)
{
	if (blk->buf && *blk->buf)
	{
		inp->args = ft_create_args(blk);
		if (inp->args == NULL)
			return ;
		while (inp->args[inp->size])
		{
			inp->args[inp->size] = ft_expand(blk, inp->args[inp->size]);
			inp->size++;
		}
		if (ft_find_str(blk->buf, "|") > 0)
		{
			ft_pipe_handle(blk, inp);
		}
		else if (ft_count_symbols(blk->buf) > 0)
		{
			char **splited;
			splited = ft_build_env(inp->args);
			ft_simple_redirect(blk, inp, splited, blk->buf);
		}
		else if (ft_is_builtin(blk, inp->args))
			built_run(inp, blk, inp->args);
		else
			ft_access(blk, inp);
		ft_freeing(inp->args);
		//free(inp->args);
	}
	inp->size = 0;
	ft_exit_d(blk);
	return ;
}
