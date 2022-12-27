/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:23:02 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/05/16 17:11:22 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	while (dstsize != 0 && dst[i] != '\0')
	{
		dstsize--;
		i++;
	}
	dstlen = i;
	if (dstsize == 0)
		return (dstlen + ft_strlen(src));
	i = -1;
	while (src[++i] != '\0')
	{
		if (dstsize > 1)
		{
			dst[i + dstlen] = ((char *)src)[i];
			dstsize--;
		}
	}
	dst[i + dstlen] = '\0';
	return (i + dstlen);
}
