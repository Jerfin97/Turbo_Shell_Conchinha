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
	char	*temp;

	if (!s)
		return (0);
	temp = ft_calloc(len + 1, sizeof(char));
	if (!temp)
		return (0);
	if (start >= ft_strlen(s))
		return (temp);
	ft_strlcpy(temp, &s[start], len + 1);
	return (temp);
}
