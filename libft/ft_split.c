/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:51:17 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/05/19 16:34:57 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	sum;
	int	size;

	i = 0;
	sum = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (size != 0)
				sum++;
			size = 0;
		}
		else
			size++;
		i++;
	}
	if (size != 0)
		sum++;
	return (sum);
}

static int	ft_freeing(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
	return (0);
}

static int	ft_mount(char const *s, char c, char **matriz, int sum)
{
	int	size;
	int	i;
	int	mi;

	size = 0;
	i = 0;
	mi = 0;
	while (mi < sum)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (size != 0)
			{
				matriz[mi] = ft_calloc(size + 1, sizeof(char));
				if (!matriz[mi])
					return (ft_freeing(matriz));
				ft_strlcpy(matriz[mi++], s + (i - size), size + 1);
			}
			size = 0;
		}
		else
			size++;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**matriz;

	if (!s)
		return (0);
	i = ft_wordcount((char *)s, c);
	matriz = malloc((i + 2) * sizeof(char *));
	if (!matriz)
	{
		free(matriz);
		return (0);
	}
	if (ft_mount(s, c, matriz, i))
	{
		matriz[i] = NULL;
		matriz[i + 1] = NULL;
		return (matriz);
	}
	return (0);
}
