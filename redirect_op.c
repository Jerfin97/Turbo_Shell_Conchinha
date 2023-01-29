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
		perror("ERNANI-HEREDOC");
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
		printf("%s\n\n", str);
		perror("ERNANI-INFILE");
		return (0);
	}
	close(0);
	dup2(blk->fd_in, 0);
	return (1);
}

int	ft_outfile_open(char **str, int j, int flag, t_shell *blk)
{
	char	**aux;

	if (str[j + 1] == NULL)
		aux = ft_split(str[j], ' ');
	else
		aux = ft_split(str[j + 1], ' ');
	if (flag == 1)
		blk->fd_in = open(aux[0], O_APPEND | O_CREAT | O_WRONLY, 0777);
	else
		blk->fd_in = open(aux[0], O_TRUNC | O_CREAT | O_WRONLY, 0777);
	ft_freeing(aux);
	dup2(blk->fd_in, 1);
	return (1);
}

int	ft_split_inf(t_shell *blk, char **tmp, int j)
{
	char	**aux;
	int		out;

	if (tmp[j][0])
		aux = ft_split(tmp [j], ' ');
	else
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
