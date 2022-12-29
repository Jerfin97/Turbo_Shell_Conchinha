/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 07:17:44 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/29 12:01:39 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

//Inicializacao do MINISHELL

/*
void	ft_shellinit(t_shell *blk, t_lst_input *inp, t_lst_env *env)
{
	blk = ft_blkinit();
	env = ft_envinit();
	inp = ft_inputinit();
}*/

t_shell	*ft_blkinit(void)
{
	t_shell	*blk;

	blk = malloc(sizeof(t_shell));
	blk->cmd = NULL;
	blk->buf = NULL;
	blk->envp = NULL;
	blk->tmpdoc = "TEMPFILEHEREDOC";
	return (blk);
}

t_lst_env	*ft_envinit(void)
{
	t_lst_env	*env;

	env = malloc(sizeof(t_lst_env));
	env->line = NULL;
	env->nxt = NULL;
	return (env);
}

t_lst_input	*ft_inputinit(void)
{
	t_lst_input	*inp;

	inp = malloc(sizeof(t_lst_input));
	inp->cmd = NULL;
	inp->args = NULL;
	inp->echo_print = NULL;
	inp->new_path = NULL;
	inp->ex_name = NULL;
	inp->ex_val = NULL;
	inp->un_name = NULL;
	inp->exit_error = 0;
	return (inp);
}
