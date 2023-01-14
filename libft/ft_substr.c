/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:37:54 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/05/19 15:39:58 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) + start) < len)
		len = ft_strlen(s) + start;
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = ft_calloc(sizeof(*s), len + 1);
	if (!substr)
		return (NULL);
	while (i < start)
		i++;
	j = 0;
	while (j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}
