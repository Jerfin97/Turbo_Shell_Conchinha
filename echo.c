/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:24:52 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/30 17:51:27 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_echo(t_shell *blk, t_input *inp)
{
	inp->echo_print = inp->args[1];
	if (inp->size == 3)
		ft_putstr_fd(inp->echo_print, 1);
	else
		ft_putendl_fd(inp->echo_print, 1);
	blk->rs = 0;
}
