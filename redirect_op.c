/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:41:06 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/29 08:42:41 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

int	ft_heredoc_open(t_shell *blk, char *str)
{
	ft_heredoc(blk, str);
	blk->fd_in = open(blk->tmpdoc, O_RDONLY);
	if (blk->fd_in < 0)
	{
		printf("%s\n", strerror(errno));
		return (0);
	}
	close(0);
	dup2(blk->fd_in, 0);
	return (1);
}

int	ft_infile_open(t_shell *blk, char *str)
{
	blk->fd_in = open(str, O_RDONLY);
	if (blk->fd_in < 0)
	{
		printf("%s : ", str);
		printf("%s\n", strerror(errno));
		return (0);
	}
	close(0);
	dup2(blk->fd_in, 0);
	return (1);
}

void	ft_open_func(t_shell *blk, char *aux, int flag)
{
	if (flag == 1)
	{
		blk->fd_in = open(aux, O_APPEND | O_CREAT | O_WRONLY, 0644);
		if (blk->fd_in < 0)
		{
		printf("%s : ", aux);
		printf("%s\n", strerror(errno));
		}
	}
	else
	{
		blk->fd_in = open(aux, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (blk->fd_in < 0)
		{
		printf("%s : ", aux);
		printf("%s\n", strerror(errno));
		}
	}
}

int	ft_outfile_open(char **str, int j, int flag, t_shell *blk)
{
	char	**aux;

	if (str[j + 1] == NULL)
		aux = ft_split(str[j], ' ');
	else
		aux = ft_split(str[j + 1], ' ');
	if (flag == 1)
	{
		ft_open_func(blk, aux[0], flag);
		ft_freeing(aux);
		return (0);
	}
	else
	{
		ft_open_func(blk, aux[0], flag);
		ft_freeing(aux);
		return (0);
	}
	ft_freeing(aux);
	dup2(blk->fd_in, 1);
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

int	ft_split_hdoc(t_shell *blk, char **tmp, int j)
{
	char	**aux;
	int		out;

	aux = ft_split(tmp [j + 1], ' ');
	out = ft_heredoc_open(blk, aux[0]);
	ft_freeing(aux);
	return (out);
}
