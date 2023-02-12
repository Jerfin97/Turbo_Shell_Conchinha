/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:48 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/06 17:49:22 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	ft_create_docs(t_input *inp, t_shell *blk)
{
	char	*basestr;
	char	**redir;
	int		i;
	int		qtd;

	i = 0;
	qtd = 0;
	inp->exit_error = 0;
	g_return = -42;
	blk->heredoc_list = ft_calloc(sizeof(char *), 256);
	redir = ft_split_in_redirect(blk->buf);
	i = 0;
	basestr = ft_red_stk(blk->buf);
	while (basestr[i])
	{
		if (basestr[i] == SHIFT_DL)
		{
			ft_split_hdoc(blk, redir, i, qtd);
			qtd++;
		}
		i++;
	}
	blk->qtd = qtd;
	ft_freeing(redir);
	free(basestr);
}
