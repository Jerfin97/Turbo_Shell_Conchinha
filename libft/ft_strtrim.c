/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:36:40 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/10/05 14:58:45 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cut(char const *str, char const *cut)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (cut[j] != '\0')
		{
			if (str[i] == cut[j])
				break ;
			if (cut[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static size_t	ft_cutoff(size_t start, size_t end, char *s1, char *cut)
{
	size_t	j;

	while (--end > start)
	{
		j = 0;
		while (cut[j] != '\0')
		{
			if (s1[end] == cut[j])
				break ;
			if (cut[j + 1] == '\0')
				return (end);
			j++;
		}
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *trim)
{
	size_t	start;
	size_t	end;
	char	*out;

	if (!s1)
		return (0);
	start = ft_cut(s1, trim);
	end = ft_strlen(s1);
	end = ft_cutoff(start, end, (char *)s1, (char *)trim);
	out = malloc(end - start + 2);
	if (out)
		ft_strlcpy(out, s1 + start, end - start + 2);
	return (out);
}
