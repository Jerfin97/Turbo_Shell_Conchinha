/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:04:41 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/25 15:56:24 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

void	ft_swapjoinchar(char **s1, char s2)
{
	char	*tmp;

	tmp = ft_strjoinchar(*s1, s2);
	free(*s1);
	*s1 = tmp;
}

// Essa funcao recebe uma string 'suja' e devolve ela com espacamento correto
// menos tudo que esta entre quotes. se o ultimo char for espaco ela coloca como
// \0
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
