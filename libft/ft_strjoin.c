/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:15:25 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/10/05 14:57:49 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		len2;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	temp = ft_calloc((len + len2 + 1), sizeof(char));
	if (temp)
	{
		ft_strlcpy(temp, s1, len + 1);
		ft_strlcat(temp, s2, len + len2 + 1);
	}
	return (temp);
}
