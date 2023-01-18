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
