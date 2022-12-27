/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:20:59 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 18:42:15 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbsizeptr(unsigned long nb)
{
	size_t	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*ft_hexptr(unsigned long nb, char *base)
{
	int		i;
	char	*ada;

	i = nbsizeptr(nb);
	ada = malloc (sizeof(char) * (i + 1));
	if (!ada)
		return (NULL);
	ada[i] = '\0';
	while (nb > 0)
	{
		ada[--i] = base[nb % 16];
		nb /= 16;
	}
	return (ada);
}
