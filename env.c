/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:47:05 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/29 17:54:00 by jeluiz4          ###   ########.fr       */
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
	if (!path)
	{
		perror("404 PATH NOT FOUND");
		return (NULL);
	}
	return (path);
}

void	ft_new_pwd(char **env, char	*str, char *str2)
{
	char	*old;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], str, ft_strlen(str)))
		{
			old = ft_strjoin(str, str2);
			free(env[i]);
			env[i] = old;
			return ;
		}
		i++;
	}
	//CHAMAR EXPORT AQUI
	//env[i] = ft_strdup(str2);
	//new_env = ft_build_env(env);
	//free(env);
	perror("404 PATH NOT FOUND");
}

int	ft_freeing(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
	return (0);
}
