/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_rlylong_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:51:07 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/03 22:13:06 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lib_mini.h"

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

void	ft_sum_up(unsigned long long *out, char *str, int *i)
{
	int					index;
	unsigned long long	no;

	index = *i;
	no = 0;
	while (ft_isdigit(str[index]))
	{
		*out = *out * 10 + str[index] - '0';
		if (no > *out)
		{
			*out = 9223372036854775809LLU;
			return ;
		}
		no = *out;
		index++;
	}
	*i = index;
}

long int	*ft_a_rlylong_int(char *str, int i, unsigned long long out)
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
	if ((out > 9223372036854775807LLU && sign == 1)
		|| (out > 9223372036854775808LLU && sign == -1))
		return (free(pop), NULL);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (free(pop), NULL);
	pop[0] = (long int)out * sign;
	return (pop);
}
