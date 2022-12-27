/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:06:33 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/05/18 18:22:14 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last;

	last = (int)ft_strlen(s);
	while (last >= 0)
	{
		if (s[last] == (char )c)
			return (((char *)s) + last);
		last--;
	}
	return (0);
}
