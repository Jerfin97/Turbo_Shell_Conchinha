/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:50:58 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/05 17:58:40 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// vejo o tamanho da variavel
int	ft_var_size(char *str)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			break ;
		i++;
	}
	while (str[i])
	{
		if (ft_isspace(str[i]) == 1 || str[i] == '"' || str[i] == '\'')
			break ;
		size++;
		i++;
	}
	return (size - 1);
}

void	ft_set_flag(int *flag, int set, int *update_flag)
{
	*flag = set;
	*update_flag = 1;
}

// essa funcao da update nas aspas fechando e abrindo duplas e singulares
int	ft_update_quote(int *flag, char c)
{
	int		update_flag;

	update_flag = 0;
	if (c == '\'')
	{
		if (*flag == 0)
			ft_set_flag(flag, 1, &update_flag);
		else if (*flag == 1)
			ft_set_flag(flag, 0, &update_flag);
	}
	if (c == '"')
	{
		if (*flag == 0)
			ft_set_flag(flag, 2, &update_flag);
		else if (*flag == 2)
			ft_set_flag(flag, 0, &update_flag);
	}
	return (update_flag);
}

//parecida com a de cima, retorna algum numero
//se chegar ao fim da string com alguma aspa aberta.
int	ft_validate_quotes(char *str)
{
	int		i;
	int		mirror_flag;

	i = 0;
	mirror_flag = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (mirror_flag == 0)
				mirror_flag = 1;
			else if (mirror_flag == 1)
				mirror_flag = 0;
		}
		if (str[i] == '"')
		{
			if (mirror_flag == 0)
				mirror_flag = 2;
			else if (mirror_flag == 2)
				mirror_flag = 0;
		}
		i++;
	}
	return (mirror_flag);
}

void	ft_swapjoin(char **s1, char *s2)

{
	char	*tmp;

	tmp = ft_strjoin(*s1, s2);
	free(*s1);
	*s1 = tmp;
}
