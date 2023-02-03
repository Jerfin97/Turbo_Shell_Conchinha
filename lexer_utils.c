/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:37:42 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/03 17:17:03 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

void	ft_size_args(t_input *inp, t_shell *blk)
{
	char	**aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (inp->args[inp->size])
		inp->size++;
	aux = ft_calloc(8, inp->size + 2);
	while (inp->args[j])
	{
		aux[j] = ft_expand(blk, inp->args[j]);
		j++;
	}
	free(inp->args);
	inp->args = ft_calloc(8, inp->size + 2);
	inp->size = 0;
	while (aux[i])
	{
		if (aux[i] != NULL)
		{
			inp->args[inp->size] = aux[i];
			inp->size++;
		}
		i++;
	}
	inp->args[inp->size] = NULL;
	inp->args[inp->size + 1] = NULL;
}

void	ft_redir_path(t_input *inp, t_shell *blk)
{
	char	**splited;

	splited = ft_build_env(inp->args);
	ft_simple_redirect(blk, inp, splited, blk->og);
}
