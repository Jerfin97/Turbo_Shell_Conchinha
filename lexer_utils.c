/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:37:42 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/03 19:00:26 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

void	ft_size_args(t_input *inp, t_shell *blk)
{
	char	**aux;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	ft_freeing(aux);
	ft_freeing(inp->args);
	tmp[inp->size] = NULL;
	tmp[inp->size + 1] = NULL;
	inp->args = ft_build_env(tmp);
	ft_freeing(tmp);
}

void	ft_redir_path(t_input *inp, t_shell *blk)
{
	char	**splited;

	splited = ft_build_env(inp->args);
	ft_simple_redirect(blk, inp, splited, blk->buf);
}
