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

//Pega o Path absoluto com a funcao getcwd
//precisa de mais testes

void	ft_pwd(t_shell *blk)
{
	char	*buffer;

	buffer = getcwd(NULL, 0);
	if (!buffer)
		blk->rs = 1;
	else
	{
		printf("%s\n", buffer);
		blk->rs = 0;
		free(buffer);
	}
}
