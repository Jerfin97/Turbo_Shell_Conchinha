/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:28:40 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/24 14:02:33 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

//Se str for nula, joga para Home
//se o caminho de str for invalido, retorn deu ruim.
int	change_dir(t_shell *blk, char *str)
{
	char	*buffer;
	char	*tmp;

	buffer = ft_search(blk->envp, "HOME=");
	tmp = buffer + 5;
	if (!str || !tmp)
	{
		printf("HOME not defined\n");
		g_return = 1;
		return(g_return);
	}
	else if (chdir(str) == -1)
	{
		printf("No Such File or Directory\n");
		g_return = 1;
		return(g_return);
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

// Aqui a magica acontece, pego o old_path se change dir funcionar com str
// atualizamos os paths nas variaveis de ambiente.
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
	old_path = getcwd(NULL, 0);
	if (change_dir(blk, str) == 0)
	{
		old_path = getcwd(NULL, 0);
		if(!old_path)
		{
			free(old_path);
			printf("cd: error retrieving current directory: getcwd: cannot");
			printf("access parent directories: No such file or directory\n");
			g_return = 1;
			return ;
		}
		ft_cd_end(blk, old_path);
		return ;
	}
	else
	{
		free(old_path);
		g_return = 1;
	}
}
