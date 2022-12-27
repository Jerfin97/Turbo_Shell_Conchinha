/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:44:40 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 18:43:36 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	char	*str;
	int		len;

	if (nb == 0)
		return (ft_putchar('0'));
	str = ft_itoa(nb);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_putnbru(unsigned int nb)
{
	char	*str;
	int		len;

	if (nb == 0)
		return (ft_putchar('0'));
	str = ft_utoa(nb);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_puthex(unsigned int i, char *base)
{
	char	*str;
	int		len;

	if (i == 0)
		return (ft_putchar('0'));
	str = ft_hex16base(i, base);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_putp(void *i)
{
	char	*str;
	char	len;

	if (i == 0)
		return (ft_putstr("0x0"));
	ft_putchar('0');
	ft_putchar('x');
	str = ft_hexptr((unsigned long)i, "0123456789abcdef");
	len = ft_putstr(str);
	free(str);
	return (len + 2);
}
