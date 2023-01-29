/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapjoinchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:24:32 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/29 08:24:39 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapjoinchar(char **s1, char s2)
{
	char	*tmp;

	tmp = ft_strjoinchar(*s1, s2);
	free(*s1);
	*s1 = tmp;
}
