/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:04:41 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/08 12:10:07 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

int	ft_i_next_input(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			break ;
		i++;
	}
	return (i);
}

char	**ft_hand_split(char *str, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		quote;
	char	**ret;

	i = 0;
	j = 0;
	k = 0;
	quote = 0;
	ret = malloc(sizeof(char **) * ft_find_str(str, sep) + 1);
	while (str[i])
	{
		ft_update_quote(&quote, str[i]);
		if (!ft_strncmp(&str[i], sep, ft_strlen(sep)) && quote == 0)
		{
			ret[j] = ft_substr(str, k, i - k);
			k = ft_i_next_input(&str[i]) + i;
			j++;
		}
		i++;
	}
	ret[j] = ft_substr(str, k, i - k);
	ret[j + 1] = NULL;
	return (ret);
}

int	ft_has_input_next(char *str, char *sep)
{
	int		i;

	i = 0;
	if (ft_strncmp(str, sep, ft_strlen(sep)))
	{
		while (str[i])
		{
			if (ft_isalpha(str[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

// Retornando a quantidade de limitadores VALIDOS
// se for 0 nao temos limitadores na string
// se for -1 tem limitadores errados, formatacao de strin errada
//
int	ft_find_str(char *str, char *sep)
{
	int		i;
	int		quote;
	int		ret;

	i = 0;
	quote = 0;
	ret = 0;
	while (str[i])
	{
		ft_update_quote(&quote, str[i]);
		if (!ft_strncmp(&str[i], sep, ft_strlen(sep)) && quote == 0)
		{
			if (ft_has_input_next(&str[i + 1], sep) == 1)
				ret++;
			if (ft_has_input_next(&str[i + 1], sep) == 0)
				return (-1);
		}
		i++;
	}
	return (ret);
}
