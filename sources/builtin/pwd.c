/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:27:33 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/08 13:06:09 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	ft_pwd(t_shell *blk, char **args)
{
	if (args[1] != NULL)
	{
		g_return = 1;
		perror("TOO MANY ARGS");
		return ;
	}
	else
	{
		printf("%s\n", blk->pwd);
		g_return = 0;
	}
}
