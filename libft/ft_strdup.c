/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:02:52 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/28 15:09:43 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	return (dest);
}
