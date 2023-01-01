/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:24:52 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/30 17:51:27 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_multijoin(t_input *inp, int i)
{
	while (inp->args[i])
	{
		inp->tmp = ft_strjoin(inp->args[i], " ");
		if (inp->args[i + 1] != NULL)
		{
			inp->echo_print = ft_strjoin(inp->tmp, inp->args[i + 1]);
			free(inp->tmp);
			i = 2 + i;
		}
		else
			i++;
	}
}

void	ft_clean_echo(t_shell *blk, t_input *inp)
{
	int	i;

	i = 1;
	if (inp->args[2] != NULL)
	{
		if (inp->args[1][0] == '-')
		{
			while((inp->args[1][i] == 'n'))
				i++;
			if (inp->args[1][i] == 'n' || inp->args[1][i] == '\0')
			{
				inp->echo_print = ft_strdup(inp->args[2]);
				inp->size = 3;
			}
			else
			{
				inp->tmp = ft_strjoin(inp->args[1], " ");
				inp->echo_print = ft_strjoin(inp->tmp, inp->args[2]);
				free(inp->tmp);
			}
		}
		else
			inp->echo_print = ft_strjoin(inp->args[1], inp->args[2]);
	}
	else
		inp->echo_print = inp->args[1];
	blk->rs = 0;
}

void	ft_echo(t_shell *blk, t_input *inp)
{
	ft_clean_echo(blk, inp);
	if (inp->size >= 3)
		ft_putstr_fd(inp->echo_print, 1);
	else
		ft_putendl_fd(inp->echo_print, 1);
	blk->rs = 0;
}
