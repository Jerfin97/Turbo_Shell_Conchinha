/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:41:06 by dvargas           #+#    #+#             */
/*   Updated: 2023/02/04 21:08:01 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	ft_redir_error(t_shell *blk, char *str)
{
	ft_restore_fds(blk);
	printf("%s : ", str);
	printf("%s\n", strerror(errno));
	g_return = 1;
}

int	ft_infile_open(t_shell *blk, char *str)
{
	blk->fd_in = open(str, O_RDONLY);
	if (blk->fd_in < 0)
	{
		ft_redir_error(blk, str);
		return (-1);
	}
	close(0);
	dup2(blk->fd_in, 0);
	return (1);
}

int	ft_open_func(t_shell *blk, char *aux, int flag)
{
	if (flag == 1)
	{
		blk->fd_in = open(aux, O_APPEND | O_CREAT | O_WRONLY, 0644);
		if (blk->fd_in < 0)
		{
			ft_redir_error(blk, aux);
			return (-1);
		}
	}
	else
	{
		blk->fd_in = open(aux, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (blk->fd_in < 0)
		{
			ft_redir_error(blk, aux);
			return (-1);
		}
	}
	return (1);
}

int	ft_split_inf(t_shell *blk, char **tmp, int j)
{
	char	**aux;
	int		out;

	aux = ft_split(tmp [j + 1], ' ');
	out = ft_infile_open(blk, aux[0]);
	ft_freeing(aux);
	return (out);
}

int	ft_split_hdoc(t_shell *blk, char **tmp, int j, int i)
{
	char		**aux;
	char		*temp;

	temp = ft_space_clean(tmp[j + 1]);
	aux = ft_split_in_spaces(temp, 0, 0, 0);
	if (aux[0] != NULL)
		aux[0] = ft_remove_quotes(aux[0]);
	free(temp);
	if (aux[0] == NULL)
		ft_heredoc(blk, "\0", i);
	else
		ft_heredoc(blk, aux[0], i);
	ft_freeing(aux);
	return (0);
}
