/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:27:33 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/29 10:24:11 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

//Pega o Path absoluto utilizando como base a Variavel de ambiente PWD

void	ft_pwd(t_shell *blk)
{
	char	*buffer;
	int		i;

	i = 3;
	buffer = ft_search(blk->envp, "PWD=");
	if (!buffer)
	{
		buffer = getcwd(NULL, 0);
		printf("%s\n", buffer);
		free(buffer);
	}
	else
	{
		while(buffer[i++])
			write(1, &buffer[i], 1);
		write(1, "\n", 1);
		blk->rs = 0;
		free(buffer);
	}
}
