/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:56:30 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/07 11:32:33 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char const *s1, char s2)
{
	char	*temp;
	int		len2;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1);
	len2 = 1;
	temp = ft_calloc((len + len2 + 1), sizeof(char));
	if (temp)
	{
		ft_strlcpy(temp, s1, len + 1);
		ft_strlcat(temp, &s2, len + len2 + 1);
	}
	return (temp);
}
