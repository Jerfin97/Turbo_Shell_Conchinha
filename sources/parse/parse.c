/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:59:08 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/17 22:55:40 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

char	**ft_split_in_spaces(char *clean, int i, int j, int quote)
{
	int		k;
	char	**ret;

	k = 0;
	ret = ft_calloc(sizeof(char *), ft_split_count(clean, " ") + 2);
	while (clean[i])
	{
		ft_update_quote(&quote, clean[i]);
		if ((clean[i] == ' ') && (quote == 0))
		{
			ret[j] = ft_substr(clean, k, i - k);
			k = i + 1;
			j++;
		}
		i++;
	}
	ret[j] = ft_substr(clean, k, i - k);
	ret[j + 1] = NULL;
	return (ret);
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
	ret = ft_calloc(sizeof(char *), ft_find_str(str, sep, 0, 0) + 2);
	while (str[i])
	{
		ft_update_quote(&quote, str[i]);
		if (!ft_strncmp(&str[i], sep, ft_strlen(sep)) && quote == 0)
		{
			ret[j] = ft_substr(str, k, i - k);
			k = ft_i_next_input(&str[i]) + i + 1;
			j++;
		}
		i++;
	}
	ret[j] = ft_substr(str, k, i - k);
	ret[j + 1] = NULL;
	return (ret);
}
