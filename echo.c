/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:24:52 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/04 13:33:12 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_multi_join(t_input *inp, int i)
{
	char	*swp;

	swp = ft_strdup("");
	while (inp->args[i])
	{
		if (inp->args[i + 1])
			inp->tmp = ft_strjoin(inp->args[i], " ");
		else
			inp->tmp = ft_strjoin(inp->args[i], "\0");
		inp->echo_print = ft_strjoin(swp, inp->tmp);
		free(swp);
		swp = ft_strdup(inp->echo_print);
		free(inp->tmp);
		i++;
	}
	free(swp);
}

int	ft_find_n(t_input *inp)
{
	int	i;

	i = 1;
	if (inp->args[1][0] == '-')
	{
		while ((inp->args[1][i] == 'n'))
			i++;
		if (inp->args[1][i] == 'n' || inp->args[1][i] == '\0')
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

void	ft_clean_echo(t_shell *blk, t_input *inp)
{
	if (inp->args[2] != NULL)
	{
		if (ft_find_n(inp))
		{
			ft_multi_join(inp, 2);
			inp->size = -1;
		}
		else
			ft_multi_join(inp, 1);
	}
	else
		inp->echo_print = ft_strjoin(inp->args[1], "\0");
	blk->rs = 0;
}

void	ft_echo(t_shell *blk, t_input *inp)
{
	ft_clean_echo(blk, inp);
	if (inp->size == -1)
	{
		ft_putstr_fd(inp->echo_print, 1);
	}
	else
		ft_putendl_fd(inp->echo_print, 1);
	free(inp->echo_print);
	blk->rs = 0;
}
