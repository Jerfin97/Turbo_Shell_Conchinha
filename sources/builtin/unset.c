/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:38:45 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/08 12:36:26 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

int	ft_re_create(t_shell *blk, char **ret, char *str)
{
	int	i;

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
	return (i);
}

char	**ft_build_unset(t_shell *blk, char *str)
{
	char	**ret;
	int		i;

	i = 0;
	blk->i = 0;
	while (blk->envp[i])
		i++;
	ret = ft_calloc(sizeof(char *), (i + 2));
	i = ft_re_create(blk, ret, str);
	ret[i - blk->i] = NULL;
	ret[i + 1 - blk->i] = NULL;
	free(str);
	return (ret);
}

void	ft_unset(t_shell *blk, char **args)
{
	char	**new_env;
	int		i;

	i = 1;
	while (args[i])
	{
		new_env = ft_build_unset(blk, ft_strjoin(args[i], "="));
		ft_freeing(blk->envp);
		blk->envp = new_env;
		if (ft_var_isvalid(args[i]))
		{
			printf("unset: not an identifier: %s\n", args[i]);
			g_return = 1;
		}
		i++;
	}
}
