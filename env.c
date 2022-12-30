/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:47:05 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/30 17:49:21 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

void	ft_export(t_shell *blk, char *str, char *str2)
{
	char	**new_env;
	int		i;

	i = 0;
	if (ft_new_pwd(blk, str, str2) == 0)
	{
		blk->rs = 0;
		return ;
	}
	while (blk->envp[i])
		i++;
	blk->envp[i] = ft_strjoin(str, str2);
	new_env = ft_build_env(blk->envp);
	ft_freeing(blk->envp);
	blk->envp = new_env;
	blk->rs = 0;
}

void	ft_printenv(t_shell *blk)
{
	int	i;

	i = 0;
	while (blk->envp[i])
	{
		printf("%s\n", blk->envp[i]);
		i++;
	}
	blk->rs = 0;
}

void	ft_unset(t_shell *blk, char *str)
{
	char	**new_env;

	new_env = ft_build_unset(blk, str);
	ft_freeing(blk->envp);
	blk->envp = new_env;
}
