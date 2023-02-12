/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:04:41 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/29 08:25:24 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

char	*ft_space_clean(char *str)
{
	char	*ret;
	int		i;
	int		quote;

	i = 0;
	quote = 0;
	ret = ft_calloc(1, 1);
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		ft_update_quote(&quote, str[i]);
		if (str[i] == ' ' && quote == 0 && str[i - 1] != ' ')
			ft_swapjoinchar(&ret, ' ');
		else if (str[i] != ' ' || quote == 1 || quote == 2)
			ft_swapjoinchar(&ret, str[i]);
		i++;
	}
	if (ret[ft_strlen(ret) - 1] == ' ')
		ret[ft_strlen(ret) - 1] = '\0';
	else
		ret[i] = '\0';
	return (ret);
}

int	ft_i_next_input(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			break ;
		i++;
	}
	return (i);
}

int	ft_has_input_next(char *str, char *sep)
{
	int		i;

	i = 0;
	if (ft_strncmp(str, sep, ft_strlen(sep)))
	{
		while (str[i])
		{
			if (ft_isprint(str[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_find_str(char *str, char *sep, int i, int p)
{
	int		quote;
	int		ret;

	quote = 0;
	ret = 0;
	while (str[i])
	{
		ft_update_quote(&quote, str[i]);
		if (!ft_strncmp(&str[i], sep, ft_strlen(sep)) && quote == 0)
		{
			if (p == i || p == i -1)
				return (-1);
			if (ft_has_input_next(&str[i + 1], sep) == 1)
				ret++;
			if (ft_has_input_next(&str[i + 1], sep) == 0)
				return (-1);
			p = i;
		}
		if (ft_isspace(str[i]))
			p++;
		i++;
	}	
	if (p == i - 1)
		return (-1);
	return (ret);
}

int	ft_split_count(char *str, char *sep)
{
	int		i;
	int		quote;
	int		ret;

	i = 0;
	quote = 0;
	ret = 1;
	while (str[i])
	{
		ft_update_quote(&quote, str[i]);
		if (!ft_strncmp(&str[i], sep, ft_strlen(sep)) && quote == 0)
		{
			if (ft_has_input_next(&str[i + 1], sep) == 1)
				ret++;
		}
		i++;
	}
	return (ret);
}
