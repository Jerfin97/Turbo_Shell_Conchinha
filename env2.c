/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:14:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/30 07:29:50 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

char	**ft_build_env(char	**envp)
{
	char	**ret;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (envp[i])
	{
		ret[i] = ft_strdup(envp[i]);
		i++;
	}
	ret[i] = NULL;
	ret[i + 1] = NULL;
	return (ret);
}

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

char	*ft_search(char **env, char *str)
{
	int		i;
	char	*path;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], str, ft_strlen(str)))
		{
			path = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	if (!env[i])
		return (NULL);
	return (path);
}
