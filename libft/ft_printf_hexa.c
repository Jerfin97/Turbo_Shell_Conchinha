/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:31:54 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 18:41:30 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbsize16(unsigned int nb)
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

char	*ft_hex16base(unsigned int nb, char *base)
{
	int		i;
	char	*ada;

	i = nbsize16(nb);
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
