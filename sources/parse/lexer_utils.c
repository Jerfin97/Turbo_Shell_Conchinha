/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:37:42 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/05 10:31:31 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	ft_free_tables(char **aux, char **tmp, t_input *inp)
{
	ft_freeing(aux);
	ft_freeing(inp->args);
	inp->args = ft_build_env(tmp);
	ft_freeing(tmp);
}

void	ft_size_args(t_input *inp, t_shell *blk, int i, int j)
{
	char	**aux;
	char	**tmp;

	aux = ft_build_env(inp->args);
	while (inp->args[j])
	{
		aux[j] = ft_expand(blk, aux[j]);
		j++;
	}
	tmp = ft_calloc(sizeof(char *), j + 2);
	while (aux[i])
	{
		if ((aux[i][0] == '\0' && !ft_strrchr(inp->args[i], '$'))
			|| aux[i][0])
		{
			tmp[inp->size] = ft_strdup(aux[i]);
			inp->size++;
		}
		i++;
	}
	tmp[inp->size] = NULL;
	tmp[inp->size + 1] = NULL;
	ft_free_tables(aux, tmp, inp);
}

void	ft_redir_path(t_input *inp, t_shell *blk)
{
	char	**splited;

	splited = ft_build_env(inp->args);
	ft_simple_redirect(blk, inp, splited, blk->buf);
}
