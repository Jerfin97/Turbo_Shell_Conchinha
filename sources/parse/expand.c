/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:23:23 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/29 08:35:59 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

char	*ft_create_var(char *str, int i, int start, char *tmp)
{
	int		len;
	char	*var;

	while (str[i])
	{
		if (str[i] == '$')
			break ;
		i++;
	}
	start = i + 1;
	len = ft_var_size(str);
	var = ft_substr(str, start, len);
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

void	ft_expand_return(int *i, char *end, char **ret)
{
	int		return_tmp;

	return_tmp = (int)g_return;
	*i = *i + 1;
	end = ft_itoa(return_tmp);
	if (end != NULL)
	{
		ft_swapjoin(ret, end);
		free(end);
	}
}

void	ft_expand_var(char *end, char **ret)
{
	if (end != NULL)
	{
		ft_swapjoin(ret, end);
		free(end);
	}
}

char	*ft_chase(t_shell *blk, char *str, int i, int flag)
{
	char	*tmp;
	char	*ret;
	char	*end;

	ret = ft_calloc(1, 1);
	while (str[++i])
	{
		if (ft_update_quote(&flag, str[i]) == 1)
			continue ;
		else if (str[i] == '$' && str[i + 1] == '?')
			ft_expand_return(&i, end, &ret);
		else if ((str[i] == '$')
			&& (flag != 1) && (!ft_var_isvalid(&str[i + 1])))
		{
			tmp = ft_create_var(&str[i], 0, 0, NULL);
			i += ft_strlen(tmp) - 1;
			end = ft_var_ret(blk, tmp);
			ft_expand_var(end, &ret);
			free(tmp);
		}
		else
			ft_swapjoinchar(&ret, str[i]);
	}
	return (ret);
}

char	*ft_expand(t_shell *blk, char *str)
{
	char	*tmp;

	tmp = ft_chase(blk, str, -1, 0);
	free(str);
	return (tmp);
}
