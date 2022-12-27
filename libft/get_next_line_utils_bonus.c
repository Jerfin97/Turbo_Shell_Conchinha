/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:07:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 16:50:30 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnlsubstr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) + start) < len)
		len = ft_strlen(s) + start;
	substr = malloc(sizeof(*s) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) + start) < len)
		len = ft_strlen(s) + start;
	substr = malloc(sizeof(*s) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	free(s);
	return (substr);
}

int	lf_count(char *str)
{
	int	position;

	position = 0;
	while (str[position])
	{
		if (str[position] == '\n')
		{
			return (position);
		}
		position++;
	}
	return (-1);
}
