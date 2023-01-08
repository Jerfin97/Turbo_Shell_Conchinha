/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_export_unset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:17:56 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/08 11:39:46 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

//verifico se a variavel e valida? talvez seja util no export
int	ft_var_isvalid(char *str)
{
	int	i;

	i = 0;
	if (ft_isalpha(str[i]) || str[i] == '_')
		return (0);
	else
		return (1);
}

int	ft_valid_name(char *str, int flag)
{
	int	i;

	i = 1;
	while (ft_isalnum(str[i]) || (str[i] == '_'))
		i++;
	if (str[i] == '=' && flag == 0)
		return (0);
	return (i);
}

void	ft_cleanse(t_shell *blk, char **args)
{
	int		i;
	char	**str;

	i = 1;
	blk->rs = 0;
	while (args[i])
	{
		if (!ft_var_isvalid(args[i]) && !ft_valid_name(args[i], 0))
		{
			str = malloc(3 * sizeof(char *));
			str[2] = NULL;
			str[0] = ft_substr(args[i], 0, ft_valid_name(args[i], 1));
			str[1] = ft_strdup(args[i] + ft_valid_name(args[i], 1));
			ft_export(blk, str[0], str[1]);
			ft_freeing(str);
		}
		else if (blk->rs == 0)
		{
			args[i][ft_valid_name(args[i], 1)] = '\0';
			printf("export: not an identifier: %s\n", args[i]);
			blk->rs = 1;
		}
		i++;
	}
}
