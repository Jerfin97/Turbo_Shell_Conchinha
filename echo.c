/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:24:52 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/07 10:49:53 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_multi_join(t_input *inp, int i, char **args)
{
	char	*swp;

	swp = ft_strdup("");
	while (args[i])
	{
		if (args[i + 1])
			inp->tmp = ft_strjoin(args[i], " ");
		else
			inp->tmp = ft_strjoin(args[i], "\0");
		inp->echo_print = ft_strjoin(swp, inp->tmp);
		free(swp);
		swp = ft_strdup(inp->echo_print);
		free(inp->tmp);
		i++;
	}
	free(swp);
}

int	ft_find_n(char **args)
{
	int	i;

	i = 1;
	if (args[1][0] == '-')
	{
		while ((args[1][i] == 'n'))
			i++;
		if (args[1][i] == 'n' || args[1][i] == '\0')
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	return (0);
}

void	ft_clean_echo(t_shell *blk, t_input *inp, char **args)
{
	if (args[2] != NULL)
	{
		if (ft_find_n(args))
		{
			ft_multi_join(inp, 2, args);
			inp->size = -1;
		}
		else
			ft_multi_join(inp, 1, args);
	}
	else
		inp->echo_print = ft_strjoin(args[1], "\0");
	blk->rs = 0;
}

void	ft_echo(t_shell *blk, t_input *inp, char **args)
{
	ft_clean_echo(blk, inp, args);
	if (inp->size == -1)
	{
		//ft_putstr_fd(inp->echo_print, 1);
		printf("%s", inp->echo_print);
	}
	else
	{
		printf("%s\n", inp->echo_print);
		//ft_putendl_fd(inp->echo_print, 1);
	}
	free(inp->echo_print);
	blk->rs = 0;
}
