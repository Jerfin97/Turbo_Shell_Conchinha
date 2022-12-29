/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:17:32 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/29 17:54:33 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// Separado porque ele sempre vai manter o historico se for comando ou não.
void	ft_history(char *str)
{
	if (str && *str)
		add_history(str);
}

// A Ideia é separar tudo para dar mastigado pro exec e seguir a vida.
int	ft_lexer(t_shell *blk)
{
	//int		i;
	//char	**cmd;

	//i = 0;
	printf("%s\n", blk->buf);
	//blk->rs = ft_exec("/usr/bin/ls", oi, blk->envp);
	//cmd = ft_split(blk->buf, ' ');
	return (0);
}

// É o nucleo do codigo Aqui que começa o merderê todo.
int	ft_prompt(t_shell *blk)
{
	while (42)
	{
		blk->buf = readline("Conchinha/> ");
		ft_exit(blk->buf);
		ft_history(blk->buf);
		//ft_lexer(blk);
		//ft_exec("./a.out", oi, blk->envp, blk);
		if (ft_strcmp(blk->buf, "pwd") == 0)
			ft_pwd(blk);
		free(blk->buf);
	}
	rl_clear_history();
}

// Samerda ta aqui só pq tem que ta mesmo.
int	main(int argc, char **argv, char **envp)
{
	t_shell		*blk;
	//t_lst_input	inp;

	(void)argc;
	(void)argv;
	//ft_shellinit(&blk, &inp, &env);
	blk = ft_blkinit();
	blk->envp = ft_build_env(envp);
	//printf("OLD %s\n", ft_search(blk->envp, "OLDPWD="));
	//ft_new_pwd(blk->envp, "OLDPWD=", "EU TO AQUI\0");
	//printf("NEW %s\n", ft_search(blk->envp, "OLDPWD="));
	ft_suppress_output();
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	ft_prompt(blk);
	return (0);
}
