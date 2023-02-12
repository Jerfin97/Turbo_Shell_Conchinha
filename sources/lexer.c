/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:35:33 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/05 10:36:17 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_mini.h"

void	built_run(t_input *inp, t_shell *blk, char **args)
{
	if (!args[0])
		return ;
	if (!ft_strcmp(args[0], "echo"))
		ft_echo(inp, args);
	else if (!ft_strcmp(args[0], "cd"))
		ft_cd(blk, args[1], args);
	else if (!ft_strcmp(args[0], "env"))
		ft_printenv(blk, args);
	else if (!ft_strcmp(args[0], "pwd"))
		ft_pwd(blk, args);
	else if (!ft_strcmp(args[0], "export"))
		ft_cleanse(blk, args);
	else if (!ft_strcmp(args[0], "unset"))
		ft_unset(blk, args);
	else if (!ft_strcmp(args[0], "exit") || blk->buf == NULL)
		ft_exit(inp, blk, args);
}

int	ft_is_builtin(t_shell *blk, char **args)
{
	if (!args[0])
		return (0);
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
	return (0);
}

char	**ft_create_args(t_shell *blk)
{
	char	**ret;
	char	*tmp;

	tmp = NULL;
	if (ft_validate_quotes(blk->buf))
		return (perror("CANT FIND CLOSE QUOTES"), NULL);
	else if (ft_count_symbols(blk->buf) == -1)
		return (perror("Syntax error near \
			unexpected token \">\" or \"<\""), NULL);
	else if (ft_find_str(blk->buf, "|", 0, 0) == -1)
		return (perror("Syntax error near unexpected token \"|\" "), NULL);
	else if (ft_find_str(blk->buf, "|", 0, 0) > 0)
		return (ret = ft_hand_split(blk->buf, "|"));
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

void	ft_free_lexer(t_input *inp, t_shell *blk)
{
	ft_freeing(inp->args);
	inp->exit_error = 0;
	if (blk->heredoc_list != NULL)
	{
		while (blk->heredoc_list[inp->exit_error])
		{
			unlink(blk->heredoc_list[inp->exit_error]);
			inp->exit_error++;
		}
		ft_freeing(blk->heredoc_list);
		blk->heredoc_list = NULL;
		blk->doc = 0;
	}
	else
		blk->doc = 0;
	free(blk->aux);
	free(blk->og);
}

void	ft_lexer(t_shell *blk, t_input *inp)
{
	if (blk->buf && *blk->buf)
	{
		inp->args = ft_create_args(blk);
		if (inp->args == NULL)
			return ;
		blk->aux = ft_strdup(inp->args[0]);
		ft_size_args(inp, blk, 0, 0);
		if (ft_count_symbols(blk->buf) > 0)
			ft_create_docs(inp, blk);
		if (ft_find_str(blk->buf, "|", 0, 0) > 0)
			ft_pipe_handle(blk, inp);
		else if (ft_count_symbols(blk->buf) > 0)
			ft_redir_path(inp, blk);
		else if (ft_is_builtin(blk, inp->args))
			built_run(inp, blk, inp->args);
		else if (inp->args[0] == NULL)
			inp->size = 0;
		else
			ft_access(blk, inp);
		ft_free_lexer(inp, blk);
	}
	inp->size = 0;
	ft_exit_d(blk, inp);
	return ;
}
