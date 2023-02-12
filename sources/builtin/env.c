/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:47:05 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/09 23:17:46 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	ft_printenv(t_shell *blk, char **args)
{
	int	i;

	i = 0;
	if (args[1] != NULL)
	{
		g_return = 127;
		perror("TOO MANY ARGS");
		return ;
	}
	while (blk->envp[i])
	{
		printf("%s\n", blk->envp[i]);
		i++;
	}
	g_return = 0;
}
