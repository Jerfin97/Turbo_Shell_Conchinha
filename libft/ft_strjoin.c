/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:15:25 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/24 13:52:47 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	temp = ft_calloc((len + 1), sizeof(char));
	if (!temp)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		temp[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i])
	{
		temp[len + i] = s2[i];
		i++;
	}
	return (temp);
}
