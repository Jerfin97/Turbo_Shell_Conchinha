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
	if (!env[i])
	{
	//	perror("404 PATH NOT FOUND");
		return (NULL);
	}
	return (path);
}

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

int	ft_freeing(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (0);
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

// Erros estranhos aqui
// a coisa ta feia
char	**ft_letsunset(t_shell *blk, char *str)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (blk->envp[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (blk->envp[i])
	{
		if (ft_strncmp(blk->envp[i], str, ft_strlen(str)))
		{
			ret[i - j] = ft_strdup(blk->envp[i]);
			i++;
		}
		else
		{
			j++;
			i++;
		}
	}
	ret[i - j] = NULL;
	ret[i + 1 - j] = NULL;
	return (ret);
}

void	ft_unset(t_shell *blk, char *str)
{
	char	**new_env;

	new_env = ft_letsunset(blk, str);
	ft_freeing(blk->envp);
	blk->envp = new_env;
}
