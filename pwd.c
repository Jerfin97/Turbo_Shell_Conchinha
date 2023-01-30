/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:27:33 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/08 13:06:09 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

//Pega o Path absoluto utilizando como base a Variavel de ambiente PWD

void	ft_pwd(t_shell *blk, char **args)
{
	char	*buffer;

	if (args[1] != NULL)
	{
		g_return = 1;
		perror("TOO MANY ARGS");
		return ;
	}
	buffer = ft_search(blk->envp, "PWD=");
	if (!buffer)
	{
		buffer = getcwd(NULL, 0);
		printf("%s\n", buffer);
		free(buffer);
	}
	else
	{
		printf("%s\n", buffer + 4);
		g_return = 0;
		free(buffer);
	}
}
