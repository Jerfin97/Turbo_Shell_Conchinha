/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:35:33 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/17 22:51:56 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	built_run(t_input *inp, t_shell *blk, char **args)
{
	// ECHO
	if (!ft_strncmp(args[0], "echo", 4))
		ft_echo(blk, inp, args);
	// CD
	else if (!ft_strncmp(args[0], "cd", 2))
		ft_cd(blk, args[1], args);
	// ENV
	else if (!ft_strncmp(args[0], "env", 3))
		ft_printenv(blk, args);
	//PWD
	else if (!ft_strncmp(args[0], "pwd", 3))
		ft_pwd(blk, args);
	// EXPORT
	else if (!ft_strncmp(args[0], "export", 6))
		ft_cleanse(blk, args);
	// UNSET
	else if (!ft_strncmp(args[0], "unset", 5))
		ft_unset(blk, args);
	// EXIT
	else if (!ft_strncmp(args[0], "exit", 4) || blk->buf == NULL)
		ft_exit(inp, blk, args);
}

int	ft_is_builtin(t_shell *blk, char **args)
{
	if (!ft_strncmp(args[0], "echo", 4))
		return (1);
	else if (!ft_strncmp(args[0], "cd", 2))
		return (1);
	else if (!ft_strncmp(args[0], "env", 3))
		return (1);
	else if (!ft_strncmp(args[0], "pwd", 3))
		return (1);
	else if (!ft_strncmp(args[0], "export", 6))
		return (1);
	else if (!ft_strncmp(args[0], "unset", 5))
		return (1);
	else if (!ft_strncmp(args[0], "exit", 4) || blk->buf == NULL)
		return (1);
	else if (!ft_strncmp(args[0], "heredoc", 7))
		return(2);
	return (0);
}

/*int	ft_has_pipes(char *str)
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
			//if (str[i + 1] == '|')
			//	return (-1);
		}
		i++;
	}
	return (pipe);
}*/

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
	else if (ft_find_str(blk->buf, ">>") == -1)
		return(perror("ERRRNANI > OU >> ERRADO"), NULL);
	//else if (ft_find_str(blk->buf, ">") > 0)
	//	return (ret = ft_hand_split(blk->buf, "|"));
	else
	{
		tmp = ft_space_clean(blk->buf);
		tmp = ft_expand(blk, tmp);
		if (tmp == NULL)
			return (NULL); 
		ret = ft_split_in_spaces(tmp, 0, 0, 0);
		free(tmp);
		return (ret);
	}
}

void	ft_lexer(t_shell *blk, t_input *inp)
{
	if (blk->buf && *blk->buf)
	{
		inp->args = ft_create_args(blk);
		if (inp->args == NULL)
			return ;
		while (inp->args[inp->size])
			inp->size++;
		if (ft_find_str(blk->buf, "|") > 0)
		{
			ft_pipe_handle(blk, inp);
		}
		else if (ft_is_builtin(blk, inp->args))
			built_run(inp, blk, inp->args);
		else if (ft_find_str(blk->buf, "|") == 0)
			ft_access(blk, inp);
		ft_freeing(inp->args);
        //free(inp->args);
	}
	inp->size = 0;
	ft_exit_d(blk);
	return ;
}
