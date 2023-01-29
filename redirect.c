/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:54:43 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/29 08:43:16 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

int	ft_redirect_do(t_shell *blk, char **tmp, char *basestring, int j)
{
	int		i;
	int		out;

	i = -1;
	while (basestring[++i])
	{
		if (basestring[i] == SHIFT_R)
			out = ft_outfile_open(tmp, j, 42, blk);
		else if (basestring[i] == SHIFT_L)
			out = ft_split_inf(blk, tmp, j);
		else if (basestring[i] == SHIFT_DR)
			out = ft_outfile_open(tmp, j, 1, blk);
		else if (basestring[i] == SHIFT_DL)
			out = ft_split_hdoc(blk, tmp, j);
		if (!basestring[i + 1])
			close(blk->fd_in);
		j++;
	}
	return (out);
}

void	ft_redirect_access(t_shell *blk, t_input *inp, char **redir)
{
	char	**tmp;

	if (redir == NULL)
		ft_access(blk, inp);
	tmp = inp->args;
	inp->args = redir;
	ft_access(blk, inp);
	inp->args = tmp;
}

void	ft_simple_redirect(t_shell *blk, t_input *inp, char **split, char *str)
{
	char	**tmp;
	char	*basestring;
	int		flag;

	basestring = ft_red_stk(str);
	tmp = ft_compose_cmd(split);
	flag = ft_redirect_do(blk, split, basestring, 0);
	ft_freeing(split);
	if (tmp[0] && flag)
		ft_redirect_access(blk, inp, tmp);
	ft_restore_fds(blk);
	ft_freeing(tmp);
	free(basestring);
	unlink(blk->tmpdoc);
}
