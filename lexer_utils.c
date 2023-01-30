/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:37:42 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/29 08:38:44 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

void	ft_size_args(t_input *inp, t_shell *blk)
{
	while (inp->args[inp->size])
	{
		inp->args[inp->size] = ft_expand(blk, inp->args[inp->size]);
		inp->size++;
	}
}	

void	ft_redir_path(t_input *inp, t_shell *blk)
{
	char	**splited;

	splited = ft_build_env(inp->args);
	ft_simple_redirect(blk, inp, splited, blk->buf);
}
