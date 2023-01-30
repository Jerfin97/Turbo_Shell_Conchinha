/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_rlylong_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:51:07 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/29 22:47:58 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

int	ft_minus(char *str, int *i, long int *sign)
{
	if (str[0] == '-' && str[1] == '-' && str[2] == '\0')
		return (42);
	if (str[*i] == '-')
		*sign = *sign * -1;
	if (str[*i] == '-' || str[*i] == '+')
		*i = *i + 1;
	return (0);
}

void	ft_sum_up(long int *out, char *str, int *i)
{
	int	index;

	index = *i;
	while (ft_isdigit(str[index]))
	{
		*out = *out * 10 + str[index] - '0';
		index++;
	}
	*i = index;
}

long int	*ft_a_rlylong_int(char *str, int i, long int out)
{
	long int	sign;
	long int	*pop;

	sign = 1;
	pop = ft_calloc(sizeof(long int), 8);
	while (ft_isspace(str[i]))
		i++;
	if (ft_minus(str, &i, &sign) == 42)
	{
		pop[0] = 0;
		return (pop);
	}
	ft_sum_up(&out, str, &i);
	out = out * sign;
	if (((sign == -1) && (out > 0)) || ((sign == 1) && (out < 0))
		|| !ft_isdigit(str[i - 1]))
	{
		free(pop);
		return (NULL);
	}
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
	{
		free(pop);
		return (NULL);
	}
	pop[0] = out;
	return (pop);
}
