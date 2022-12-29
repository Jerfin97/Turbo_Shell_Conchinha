/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:47:05 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/29 16:21:23 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

t_lst_env	*ft_lstnew(char *line, int id)
{
	t_lst_env	*node;

	node = malloc(sizeof(t_lst_env));
	if (!node)
		return (NULL);
	node->line = line;
	node->builtin_id = id;
	node->nxt = NULL;
	return (node);
}

t_lst_env	*ft_lstlast(t_lst_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> nxt != NULL)
		lst = lst -> nxt;
	return (lst);
}

void	ft_lstadd_back(t_lst_env **lst, t_lst_env *new)
{
	t_lst_env	*last_node;

	if (!(*lst) && new)
	{
		*lst = new;
		new -> nxt = NULL;
	}
	else if (lst && new)
	{
		last_node = ft_lstlast(*lst);
		last_node -> nxt = new;
		new -> nxt = NULL;
	}	
}

void	build_lst_env(char **envp, t_lst_env **env)
{
	int		i;
	int		id;

	i = 0;
	while (envp[i])
	{
		id = 0;
		if (!ft_strncmp(envp[i], "PWD=", 4))
			id = 1;
		if (!ft_strncmp(envp[i], "OLDPWD=", 7))
			id = 2;
		if (!ft_strncmp(envp[i], "PATH=", 5))
			id = 3;
		ft_lstadd_back(env, ft_lstnew(envp[i], id));
		i++;
	}
}
