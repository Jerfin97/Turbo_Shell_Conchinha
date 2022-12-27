/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:45:22 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/05/19 15:22:52 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s2len;

	s2len = ft_strlen(s2);
	if (!s2)
		return ((char *)s1);
	while (*s1 && s2len <= len--)
	{
		if (!ft_memcmp(s1, s2, s2len))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
