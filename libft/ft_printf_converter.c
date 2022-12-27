/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:24:30 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 18:32:59 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbsize(long nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int nb)
{
	int		i;
	char	*ada;

	i = nbsize(nb);
	ada = malloc(sizeof(char) * (i + 1));
	if (!ada)
		return (NULL);
	ada[i] = '\0';
	while (nb > 0)
	{
		ada[--i] = 48 + (nb % 10);
		nb /= 10;
	}
	return (ada);
}

char	*ft_itoa(int n)
{
	char	*ada;
	long	i;
	long	nb;

	ada = NULL;
	nb = n;
	i = nbsize(n);
	ada = malloc (sizeof(char) * (i + 1));
	if (!ada)
		return (NULL);
	if (nb < 0)
	{
		ada[0] = '-';
		nb *= -1;
	}
	ada[i] = '\0';
	while (nb > 0)
	{
		ada[--i] = 48 + (nb % 10);
		nb /= 10;
	}
	return (ada);
}
