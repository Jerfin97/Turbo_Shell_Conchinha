/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:19:13 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 18:37:24 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_treatchar(char str, va_list list)
{
	int	i;

	i = 0;
	if (str == 'c')
		i += ft_putchar(va_arg(list, int));
	else if (str == 's')
		i += ft_putstr(va_arg(list, char *));
	else if (str == 'p')
		i += ft_putp(va_arg(list, void *));
	else if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(list, int));
	else if (str == 'u')
		i += ft_putnbru(va_arg(list, unsigned int));
	else if (str == 'x')
		i += ft_puthex(va_arg(list, unsigned int), "0123456789abcdef");
	else if (str == 'X')
		i += ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (str == '%')
		i += ft_putchar('%');
	else
		return (0);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		f;
	va_list	list;

	i = 0;
	f = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			f += ft_treatchar(str[i + 1], list);
			i++;
		}
		else
			f += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (f);
}
