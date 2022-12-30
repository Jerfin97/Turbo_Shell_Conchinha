/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:28:40 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/29 11:55:20 by jeluiz4          ###   ########.fr       */
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

	buffer = ft_search(blk->envp, "HOME=");
	buffer = buffer + 5;
	if (!str)
	{
		if (chdir(buffer) == -1)
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
	return (0);
}

// Aqui a magica acontece, pego o old_path se change dir funcionar com str
// atualizamos os paths nas variaveis de ambiente.
void	ft_cd(t_shell *blk, char *str)
{
	char	*old_path;

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
