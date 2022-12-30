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

void	ft_new_path(t_lst_env *env)
{
	char	*path;

	path = getcwd(NULL, 0);
	// VAI NO NODO ID = PWD E MUDA O PWD = PATH;
	free(path);
}

void	ft_old_path(char *old, t_lst_env *env)
{
	// VAI NO NODO ID = PWD E MUDA OLD_PWD = OLD_PATH
}

void	ft_cd(t_shell *blk, t_lst_env *env, t_lst_input *inp)
{
	char	*old_path;

	old_path = getcwd(NULL, 0);
	if (chdir(inp->new_path))
	{
		free(old_path);
		blk->rs = 1;
	}
	else
	{
		//ft_new_path(env);
		//ft_old_path(old_path, env);
		free(old_path);
		blk->rs = 0;
	}
}
