/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:54:43 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/17 22:11:46 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

//Tomar cuidado com o isalpha, pode bugar algumas coisas no futuro uma solucao
//para um possivel problema com variavel seja ignorar o $ como faco com o space
int	ft_symbol_control(int *i, char *str, char good)
{
	if (str[*i + 1] == good)
		*i = *i + 1;
	while (str[*i])
	{
		*i = *i + 1;
		if (ft_isalpha(str[*i]) == 1 && str[*i] != ' ')
			return (0);
		if (str[*i] == '<' || str[*i] == '>' || str[*i] == '\0')
			return (-1);
	}
	return (0);
}

int	ft_count_symbols(char *str)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '>')
		{
			count++;
			if (ft_symbol_control(&i, str, '>') == -1)
				return (-1);
		}
		else if (str[i] == '<')
		{
			count++;
			if (ft_symbol_control(&i, str, '<') == -1)
				return (-1);
		}
	}
	return (count);
}

char	**ft_split_in_redirect(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**ret;

	i = 0;
	j = 0;
	k = 0;
	ret = ft_calloc(sizeof(char *), ft_count_redir_sep(str) + 2);
	if (!ret)
		return (printf("MALLOC CRASH"), NULL);
	while (str[i])
	{
		if (ft_is_redir_sep(str, i))
		{
			ret[j] = ft_substr(str, k, i - k);
			k = ft_i_next_redir(&str[i]) + i;
			i = k;
			j++;
		}
		i++;
	}
	ret[j] = ft_substr(str, k, i - k);
	ret[j + 1] = NULL;
	return (ret);
}

void	ft_heredoc_open(t_shell *blk)
{
	if (blk->heredoc_name)
	{
		ft_heredoc(blk, blk->heredoc_name);
		blk->fd_in = open(blk->heredoc_name, O_RDONLY);
		if (blk->fd_in < 0)
			perror("ERNANI");
		close(0);
		dup2(blk->fd_in, 0);
	}
}

void	ft_infile_open(t_shell *blk)
{
	if (blk->infilename)
	{
		blk->fd_in = open(blk->infilename, O_RDONLY);
		if (blk->fd_in < 0)
			perror("ERNANI");
		close(0);
		dup2(blk->fd_in, 0);
	}
}

void	ft_outfile_open(t_shell *blk)
{
	int		outfile;

	if (blk->append == 1)
		outfile = open(blk->outfile_name, O_APPEND | O_CREAT | O_WRONLY, 0777);
	else
		outfile = open(blk->outfile_name, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	dup2(outfile, 1);
}

//Essa funcao chama as outras tres funcoes de redirecionamento dependendo das
//informacoes contidas em blk.
void	ft_redirect_infile(t_shell *blk)
{
	blk->fd_in = dup(0);
	if (blk->heredoc_name)
		ft_heredoc_open(blk);
	if (blk->infilename)
		ft_infile_open(blk);
	if (blk->outfile_name)
		ft_outfile_open(blk);
}
