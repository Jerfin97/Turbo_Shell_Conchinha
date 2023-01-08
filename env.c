/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:47:05 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/08 13:06:18 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_printenv(t_shell *blk, char **args)
{
	int	i;

	i = 0;
	if (args[1] != NULL)
	{
		blk->rs = 1;
		perror("TOO MANY ARGS");
		return ;
	}
	while (blk->envp[i])
	{
		printf("%s\n", blk->envp[i]);
		i++;
	}
	blk->rs = 0;
}
