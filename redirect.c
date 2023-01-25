/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:54:43 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/25 09:55:07 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

void	ft_heredoc_open(t_shell *blk, char *str)
{
	ft_heredoc(blk, str);
	blk->fd_in = open(blk->tmpdoc, O_RDONLY);
	if (blk->fd_in < 0)
		perror("ERNANI");
	close(0);
	dup2(blk->fd_in, 0);
}

void	ft_infile_open(t_shell *blk, char *str)
{
	blk->fd_in = open(str, O_RDONLY);
	if (blk->fd_in < 0)
		perror("ERNANI");
	close(0);
	dup2(blk->fd_in, 0);
}

void	ft_outfile_open(char *str, int flag)
{
	int		outfile;
	char	*outfile_name;
	int		i;

	i = 0;
	while (str[i] != ' ')
		i++;
	outfile_name = ft_substr(str, 0, i);
	if (flag == 1)
		outfile = open(outfile_name, O_APPEND | O_CREAT | O_WRONLY, 0777);
	else
		outfile = open(outfile_name, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	dup2(outfile, 1);
}

void	ft_redirect_do(t_shell *blk, char **tmp, char *basestring, int j)
{
	char	**aux;
	int		i;

	i = -1;
	while (basestring[++i])
	{
		if (basestring[i] == SHIFT_R)
			ft_outfile_open(tmp[j + 1], 42);
		if (basestring[i] == SHIFT_L)
		{
			aux = ft_split(tmp [j + 1], ' ');
			ft_infile_open(blk, aux[0]);
			ft_freeing(aux);
		}
		if (basestring[i] == SHIFT_DR)
			ft_outfile_open(tmp[j + 1], 1);
		if (basestring[i] == SHIFT_DL)
		{
			aux = ft_split(tmp[j + 1], ' ');
			ft_heredoc_open(blk, aux[0]);
			ft_freeing(aux);
		}
		i++;
		j++;
	}
}

void	ft_simple_redirect(t_shell *blk, t_input *inp)
{
	char	**tmp;
	char	*basestring;

	basestring = ft_red_stk(blk->buf);
	tmp = inp->args;
	inp->args = ft_compose_cmd(tmp);
	ft_redirect_do(blk, tmp, basestring, 0);
	if (inp->args[0])
		ft_access(blk, inp);
	ft_restore_fds(blk);
	free(basestring);
	unlink(blk->tmpdoc);
	//ft_freeing(tmp);
}
