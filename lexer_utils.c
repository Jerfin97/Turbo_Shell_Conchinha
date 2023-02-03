/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:37:42 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/02 18:09:51 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

void	ft_size_args(t_input *inp, t_shell *blk)
{
	char	**aux;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (inp->args[inp->size])
		inp->size++;
	aux = ft_calloc(8, inp->size + 2);
	inp->size = 0;
	while (inp->args[j])
	{
		aux[j] = ft_expand(blk, inp->args[j]);
		j++;
	}
	ft_freeing(inp->args);
	inp->args = ft_calloc(8, inp->size);
	while (aux[++i])
	{
		if (aux[i][0] != '\0')
		{
			inp->args[inp->size] = ft_expand(blk, inp->args[i]);
			inp->size++;
		}
	}
	inp->args[inp->size] = NULL;
	inp->args[inp->size + 1] = NULL;
}	

void	ft_redir_path(t_input *inp, t_shell *blk)
{
	char	**splited;

	splited = ft_build_env(inp->args);
	ft_simple_redirect(blk, inp, splited, blk->buf);
}
