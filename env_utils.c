/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:14:49 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/07 20:38:31 by jeluiz4          ###   ########.fr       */
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

int	ft_var_exist(char **env, char *str)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], str, ft_strlen(str)))
			return (0);
		i++;
	}
	return (1);
}
