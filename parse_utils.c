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

int	ft_has_input_next(char *str, char *c)
{
	int		i;

	i = 0;
	if (ft_strncmp(str, c, ft_strlen(c)))
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
int	ft_find_str(char *str, char *c)
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
		if (!ft_strncmp(&str[i], c, ft_strlen(c)) && quote == 0)
		{
			if (ft_has_input_next(&str[i + 1], c) == 1)
				ret++;
			if (ft_has_input_next(&str[i + 1], c) == 0)
				return (-1);
		}
		i++;
	}
	return (ret);
}
