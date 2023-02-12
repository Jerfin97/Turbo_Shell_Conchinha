/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:23:21 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/06 15:24:35 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	uptick_str(int *mirror_flag, int *i, int val)
{
	if (*mirror_flag == 0)
	{
		*mirror_flag = val;
		*i = *i + 1;
	}
	else if (*mirror_flag == val)
	{
		*mirror_flag = 0;
		*i = *i + 1;
	}
}

char	*ft_remove_quotes(char *str)
{
	int		i;
	int		mirror_flag;
	char	*tmp;

	i = 0;
	mirror_flag = 0;
	tmp = ft_calloc(1, 1);
	while (str[i])
	{
		if (str[i] == '\'')
			uptick_str(&mirror_flag, &i, 1);
		if (str[i] == '"')
			uptick_str(&mirror_flag, &i, 2);
		if (!((str[i] == '"' && mirror_flag == 2)
				|| (str[i] == '\'' && mirror_flag == 1)) && str[i])
		{
			ft_swapjoinchar(&tmp, str[i]);
			i++;
		}
	}
	ft_swapjoinchar(&tmp, '\0');
	free(str);
	return (tmp);
}
