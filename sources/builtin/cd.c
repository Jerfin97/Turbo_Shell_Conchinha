/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:28:40 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/05 10:15:24 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

int	change_dir(t_shell *blk, char *str)
{
	char	*buffer;
	char	*tmp;

	buffer = ft_search(blk->envp, "HOME=");
	tmp = buffer + 5;
	if (!str)
	{
		if (chdir(tmp) == -1)
		{
			printf("HOME not defined\n");
			g_return = 1;
			return (g_return);
		}
	}
	else if (chdir(str) == -1)
	{
		printf("No Such File or Directory\n");
		free(buffer);
		g_return = 1;
		return (g_return);
	}
	free(buffer);
	return (0);
}

void	ft_cd_end(t_shell *blk, char *old_path)
{
	ft_new_pwd(blk, "PWD=", old_path);
	ft_export(blk, "OLDPWD=", old_path);
	free(blk->pwd);
	blk->pwd = getcwd(NULL, 0);
	free(old_path);
}

void	ft_cd_error(void)
{
	printf("cd: error retrieving current directory: getcwd: cannot");
	printf("access parent directories: No such file or directory\n");
	g_return = 1;
}

void	ft_cd(t_shell *blk, char *str, char **args)
{
	char	*old_path;
	int		size;

	size = 0;
	while (args[size])
		size++;
	if (size > 2)
	{
		g_return = 1;
		printf("TOO MANY ARGS\n");
		return ;
	}
	if (change_dir(blk, str) == 0)
	{
		old_path = getcwd(NULL, 0);
		if (!old_path)
		{
			free(old_path);
			ft_cd_error();
			return ;
		}
		ft_cd_end(blk, old_path);
		return ;
	}
	g_return = 1;
}
