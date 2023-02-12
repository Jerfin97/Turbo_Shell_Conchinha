/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:53:08 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/25 09:54:54 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

int	ft_symbol_control(int *i, char *str, char good)
{
	if (str[*i + 1] == good)
		*i = *i + 1;
	while (str[*i])
	{
		*i = *i + 1;
		if (ft_isprint(str[*i]) == 1 && str[*i] != ' ')
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
	int		quote;

	quote = 0;
	i = -1;
	count = 0;
	while (str[++i])
	{
		ft_update_quote(&quote, str[i]);
		if (str[i] == '>' && quote == 0)
		{
			count++;
			if (ft_symbol_control(&i, str, '>') == -1)
				return (-1);
		}
		else if (str[i] == '<' && quote == 0)
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

char	**ft_compose_cmd(char **matrix)
{
	char	*tmp;
	char	**aux;
	int		i;
	int		j;

	i = 1;
	tmp = ft_strdup(matrix[0]);
	while (matrix[i])
	{
		j = 1;
		aux = ft_split(matrix[i], ' ');
		while (aux[j])
		{
			ft_swapjoin(&tmp, aux[j]);
			ft_swapjoin(&tmp, " ");
			j++;
		}
		ft_freeing(aux);
		i++;
	}
	aux = ft_split(tmp, ' ');
	free(tmp);
	return (aux);
}
