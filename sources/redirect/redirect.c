/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:54:43 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/06 18:06:39 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

int	ft_state(t_shell *blk, char **tmp, int j, int i)
{
	int	out;
	int	fd_out;

	fd_out = dup(1);
	ft_restore_fds(blk);
	out = ft_split_hdoc(blk, tmp, j, i);
	dup2(fd_out, 1);
	return (out);
}

int	ft_redirect_do(t_shell *blk, char **tmp, char *basestring, int j)
{
	int			i;
	int			out;

	i = -1;
	out = 0;
	while (basestring[++i] && out >= 0)
	{
		if (basestring[i] == SHIFT_R)
			out = ft_outfile_open(tmp, j, 42, blk);
		else if (basestring[i] == SHIFT_L)
			out = ft_split_inf(blk, tmp, j);
		else if (basestring[i] == SHIFT_DR)
			out = ft_outfile_open(tmp, j, 1, blk);
		else if (basestring[i] == SHIFT_DL)
		{
			out = ft_infile_open(blk, blk->heredoc_list[blk->doc]);
			blk->doc++;
		}
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

int	ft_outfile_open(char **str, int j, int flag, t_shell *blk)
{
	char	**aux;
	int		out;

	out = 1;
	if (str[j + 1] == NULL)
		aux = ft_split(str[j], ' ');
	else
		aux = ft_split(str[j + 1], ' ');
	if (flag == 1)
		out = ft_open_func(blk, aux[0], flag);
	else
		out = ft_open_func(blk, aux[0], flag);
	ft_freeing(aux);
	dup2(blk->fd_in, 1);
	return (out);
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
	if ((tmp[0] && flag > 0) && (g_return != 130))
		ft_redirect_access(blk, inp, tmp);
	close(blk->fd_in);
	blk->fd_in = dup(0);
	ft_restore_fds(blk);
	ft_freeing(tmp);
	free(basestring);
}
