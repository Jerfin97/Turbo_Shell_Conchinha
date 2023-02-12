/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:24:52 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/31 21:52:36 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

int	ft_find_n(char **args, int i)
{
	int	j;

	j = 0;
	if (args[i] == NULL)
	{
		return (0);
	}
	if ((args[i][j++] == '-') && (args[i][j] == 'n'))
	{
		while ((args[i][j] == 'n') && (args[i][j]))
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

void	ft_multi_print(t_input *inp, int i, char **args)
{
	inp->size = inp->size;
	while (args[i])
	{
		if (args[i + 1])
			printf("%s ", args[i]);
		else
			printf("%s", args[i]);
		i++;
	}
}

void	ft_clean_echo(t_input *inp, char **args)
{
	int	i;

	i = 1;
	if (args[i] != NULL)
	{
		if (ft_find_n(args, i))
		{
			while (ft_find_n(args, i))
				i++;
			ft_multi_print(inp, i, args);
			inp->size = -1;
		}
		else
			ft_multi_print(inp, 1, args);
	}
	else if (args[i])
		printf("%s", args[i]);
	g_return = 0;
}

void	ft_echo(t_input *inp, char **args)
{
	ft_clean_echo(inp, args);
	if (inp->size == -1)
	{
		printf("%c", '\0');
	}
	else
	{
		printf("\n");
	}
	g_return = 0;
}
