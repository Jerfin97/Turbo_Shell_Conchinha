/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:23:23 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/11 15:32:02 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

// crio a variavel dando join no =
char	*ft_create_var(char *str)
{
	int		i;
	int		start;
	int		len;
	char	*tmp;
	char	*var;

	start = 0;
	i = 0;
	tmp = NULL;
	while (str[i])
	{
		if (str[i] == '$')
			break ;
		i++;
	}
	start = i + 1;
	len = ft_var_size(str);
	var = ft_substr(str, start, len); // malloc
	if (!var)
		return (NULL);
	i = 1;
	if (!ft_var_isvalid(var))
	{
		while (ft_isalnum(var[i]) || var[i] == '_')
			i++;
		tmp = ft_substr(var, 0, i);
		free(var);
	}
	var = ft_strjoin(tmp, "=");
	free(tmp);
	return (var);
}

// busco a variavel na nossa env e retorno o resultado da busca depois do =
char	*ft_var_ret(t_shell *blk, char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_search(blk->envp, str);
	if (!ret)
		return ("");// Voltar pra null caso de merda
	while (ret[i] != '=')
		i++;
	return (&ret[i + 1]);
}

// O -1 e importante pq ele faz a len com o = mas imprime sem ele, logo o
// caractere depois de variavel esta sendo ignorado, com o -1 retornamos correto
char	*ft_chase(t_shell *blk, char *str)
{
	char	*tmp;
	char	*ret;
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	ret = ft_calloc(1, 1);
	while (str[++i])
	{
		if (ft_update_quote(&flag, str[i]) == 1)
			continue ;
		else if (str[i] == '$' && flag != 1)
		{
			tmp = ft_create_var(&str[i]);
			i += ft_strlen(tmp) - 1;
			ft_swapjoin(&ret, ft_var_ret(blk, tmp));
			free(tmp);
		}
		else
		{
			tmp = ret;
			ret = ft_strjoinchar(ret, str[i]);
			free(tmp);
		}
	}
	return (ret);
}

char	*ft_expand(t_shell *blk, char *str)
{
	char	*tmp;

	if (ft_validate_quotes(str) != 0)
	{
		perror("CANT FIND CLOSE QUOTES\n");
		free(blk->exp);
		return (NULL);
	}
	tmp = ft_chase(blk, str);
	return (tmp);
}
