/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:54:43 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/28 16:50:56 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

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

void	ft_simple_redirect(t_shell *blk, t_input *inp, char **splited, char *str)
{
	char	**tmp;
	char	*basestring;
	int		flag;

	basestring = ft_red_stk(str);
	tmp = ft_compose_cmd(splited);
	flag = ft_redirect_do(blk, splited, basestring, 0);
	ft_freeing(splited);
	if (tmp[0] && flag)
		ft_redirect_access(blk, inp, tmp);
	ft_restore_fds(blk);
	ft_freeing(tmp);
	free(basestring);
	unlink(blk->tmpdoc);
}
