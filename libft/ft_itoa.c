/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:43:28 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/05/19 16:31:24 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *start, char *end, int s, int e)
{
	char	aux;

	aux = end[e];
	end[e] = start[s];
	start[s] = aux;
}

static char	*ft_revstr(char *saida)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(saida) - 1;
	if (saida[0] == '-')
	{
		i = 1;
		while (i < len)
			ft_swap(saida, saida, len--, i++);
	}
	else
	{
		while (i < len)
			ft_swap(saida, saida, len--, i++);
	}
	return (saida);
}

static int	ft_digitsize(int n)
{
	int	sum;

	sum = 0;
	if (n < 0)
		sum++;
	while (n / 10)
	{
		sum++;
		n = n / 10;
	}
	return (sum + 2);
}

char	*ft_itoa(int n)
{
	char			*out;
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	out = ft_calloc(ft_digitsize(n), sizeof(char));
	if (!out)
		return (0);
	if (n < 0)
	{
		out[i++] = '-';
		nbr = nbr * -1;
	}
	while (nbr / 10)
	{
		out[i++] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	out[i] = nbr + 48;
	return (ft_revstr(out));
}
