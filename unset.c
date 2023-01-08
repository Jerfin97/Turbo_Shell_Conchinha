/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:38:45 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/08 08:55:50 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

char	**ft_build_unset(t_shell *blk, char *str)
{
	char	**ret;
	int		i;

	i = 0;
	blk->i = 0;
	while (blk->envp[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (blk->envp[i])
	{
		if (ft_strncmp(blk->envp[i], str, ft_strlen(str)))
		{
			ret[i - blk->i] = ft_strdup(blk->envp[i]);
			i++;
		}
		else
		{
			blk->i++;
			i++;
		}
	}
	ret[i - blk->i] = NULL;
	ret[i + 1 - blk->i] = NULL;
	return (ret);
}

void	ft_unset(t_shell *blk, char **args)
{
	char	**new_env;
	int		i;

	i = 0;
	while (args[i])
	{
		new_env = ft_build_unset(blk, args[i]);
		ft_freeing(blk->envp);
		blk->envp = new_env;
		i++;
	}
}
