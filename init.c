/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 07:17:44 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/30 17:49:57 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

//Inicializacao do MINISHELL

t_shell	*ft_blk_init(void)
{
	t_shell	*blk;

	blk = malloc(sizeof(t_shell));
	blk->cmd = NULL;
	blk->buf = NULL;
	blk->envp = NULL;
	blk->tmpdoc = "TEMPFILEHEREDOC";
	blk->rs = 0;
	blk->infilename = NULL;
	blk->redirect = 0;
	blk->stdin_backup = dup(0);
	blk->stdout_backup = dup(1);
	return (blk);
}

t_input	*ft_input_init(void)
{
	t_input	*inp;

	inp = malloc(sizeof(t_input));
	inp->cmd = NULL;
	inp->args = NULL;
	inp->echo_print = NULL;
	inp->new_path = NULL;
	inp->ex_name = NULL;
	inp->ex_val = NULL;
	inp->un_name = NULL;
	inp->exit_error = 0;
	inp->size = 0;
	return (inp);
}
