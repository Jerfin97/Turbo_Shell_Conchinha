/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:27:48 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/08 10:53:36 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

int	ft_new_pwd(t_shell *blk, char	*str, char *str2)
{
	char	*old;
	int		i;

	i = 0;
	while (blk->envp[i])
	{
		if (!ft_strncmp(blk->envp[i], str, ft_strlen(str)))
		{
			old = ft_strjoin(str, str2);
			free(blk->envp[i]);
			blk->envp[i] = old;
			return (0);
		}
		i++;
	}
	return (1);
}

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
