/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:28:40 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/24 13:41:11 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

//Update no path SEM PRECISAR QUE TENHA PWD

void	update_path(t_shell *blk, char *str)
{
	char	*buffer;

	buffer = getcwd(NULL, 0);
	ft_new_pwd(blk, "OLDPWD=", str);
	ft_new_pwd(blk, "PWD=", buffer);
	free(buffer);
}

//Se str for nula, joga para Home
//se o caminho de str for invalido, retorn deu ruim.
int	change_dir(t_shell *blk, char *str)
{
	char	*buffer;
	char	*tmp;

	buffer = ft_search(blk->envp, "HOME=");
	tmp = buffer + 5;
	if (!str || str[0] == '\0')
	{
		if (chdir(tmp) == -1)
		{
			printf("deu ruim no chdir buffer\n");
			blk->rs = 1;
		}
	}
	else if (chdir(str) == -1)
	{
		printf("No Such File or Directory\n");
		blk->rs = 1;
	}
	free(buffer);
	return (0);
}

// Aqui a magica acontece, pego o old_path se change dir funcionar com str
// atualizamos os paths nas variaveis de ambiente.
void	ft_cd(t_shell *blk, char *str, char **args)
{
	char	*old_path;
	int	size;

	size = 0;
	while (args[size])
		size++;
	if (size > 2)
	{
		blk->rs = 1;
		perror("TOO MANY ARGS");
		return ;
	}
	old_path = getcwd(NULL, 0);
	if (change_dir(blk, str) == 0)
	{
		update_path(blk, old_path);
		free(old_path);
		blk->rs = 0;
	}
	else
		blk->rs = 1;
}
