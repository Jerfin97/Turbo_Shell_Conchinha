/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:47:35 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/17 20:28:36 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

char	*ft_red_stk(char *str)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	out = ft_calloc(128, 1);
	if (out == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '>' && str[i + 1] == '>')
		{
			out[j] = SHIFT_DR;
			j++;
			i += 2;
		}
		else if (str[i] == '<' && str[i + 1] == '<')
		{
			out[j] = SHIFT_DL;
			j++;
			i += 2;
		}
		else if (str[i] == '>')
		{
			out[j] = SHIFT_R;
			j++;
			i++;
		}
		else if (str[i] == '<')
		{
			out[j] = SHIFT_L;
			j++;
			i++;
		}
		else
			i++;
	}
	return (out);
}

int	ft_is_redir_sep(char *str, int i)
{
	if (str[i] == '>' || str[i] == '<')
	{
		if (str[i + 1] == '>' || str[i + 1] == '<')
			return (1);
		return (1);
	}
	return (0);
}

int	ft_count_redir_sep(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			count++;
			if (str[i] == '>' || str[i] == '<')
				i++;
		}
		i++;
	}
	return (count);
}

int	ft_i_next_redir(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]) && str[i] != ' '
			&& str[i] != '<' && str[i] != '>')
			break ;
		i++;
	}
	return (i);
}
