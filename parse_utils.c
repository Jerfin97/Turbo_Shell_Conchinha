/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:04:41 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/09 10:52:55 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

char	*ft_space_clean(char *str,int i,int quote,int space)
{
	char *ret;

	ret = calloc(1,1);
	while(str[i] == ' ')
		i++;
	while(str[i])
	{
		ft_update_quote(&quote, str[i]);
		if(str[i] == ' ' && quote == 0 && space == 0)
		{
			ret = ft_strjoinchar(ret, ' ');
			space = 1;
		}
		else if(str[i] != ' ' || quote == 1 || quote == 2)
		{
			if(space == 1)
				space = 0;
			ret = ft_strjoinchar(ret, str[i]);
		}
		i++;
	}
	return(ret);
}

char	**ft_split_in_spaces(char *str)
{
	int i;
	int j;
	int k;
	int quotes;
	int size;
	char **ret;
	char *clean;
	quotes = 0;
	i = 0;
	k = 0;
	j = 0;
	clean = ft_space_clean(str, 0, 0, 0);
	size = ft_find_str(clean, " ");
	ret = malloc(sizeof(char **) * size + 1);
	while(clean[i])
	{
		if(clean[i] == ' ' && quotes == 0)
		{
			ret[j] = ft_substr(str, k, i - k);
			k = ft_i_next_input(&str[i]) + i;
			j++;
		}
		i++;
	}
	ret[j] = NULL;
	return(ret);
}

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
