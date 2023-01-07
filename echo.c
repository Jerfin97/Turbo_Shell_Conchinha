/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:24:52 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/07 19:08:21 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

int	ft_find_n(char **args, int i)
{
	int	j;

	j = 0;
	if (args[i][j++] == '-')
	{
		while ((args[i][j] == 'n'))
			j++;
		if (args[i][j] == 'n' || args[i][j] == '\0')
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

void	ft_clean_echo(t_shell *blk, t_input *inp, char **args)
{
	int	i;

	i = 2;
	if (args[1] != NULL)
	{
		if (ft_find_n(args, 1))
		{
			while (ft_find_n(args, i))
				i++;
			ft_multi_join(inp, i, args);
			inp->size = -1;
		}
		else
			ft_multi_join(inp, 1, args);
	}
	else if (args[1])
		inp->echo_print = ft_strjoin(args[1], "\0");
	else
		inp->echo_print = ft_strdup("");
	blk->rs = 0;
}

void	ft_echo(t_shell *blk, t_input *inp, char **args)
{
	ft_clean_echo(blk, inp, args);
	if (inp->size == -1)
	{
		printf("%s", inp->echo_print);
	}
	else
	{
		printf("%s\n", inp->echo_print);
	}
	free(inp->echo_print);
	blk->rs = 0;
}
