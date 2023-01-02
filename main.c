/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:17:32 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/31 12:24:20 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// Separado porque ele sempre vai manter o historico se for comando ou não.
void	ft_history(char *str)
{
	if (str && *str)
		add_history(str);
}

// É o nucleo do codigo Aqui que começa o merderê todo.
int	ft_prompt(t_shell *blk, t_input *inp)
{
	while (42)
	{
		blk->buf = readline("Conchinha/> ");
		ft_history(blk->buf);
		ft_lexer(blk, inp);
		free(blk->buf);
	}
	rl_clear_history();
}

// Samerda ta aqui só pq tem que ta mesmo.
int	main(int argc, char **argv, char **envp)
{
	t_shell		*blk;
	t_input		*inp;

	(void)argc;
	(void)argv;
	blk = ft_blk_init();
	inp = ft_input_init();
	blk->envp = ft_build_env(envp);
	ft_suppress_output();
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	//ft_access(blk, inp);
	//printf("%s", ft_create_var(TESTE));
	char *TESTE = "\"'\"'$PAPERSIZE";
	char *TESTE2 = "'''\"$PAPERSIZE\"'";
	char *TESTE3 = "\"'\"'$PAPERSIZE'\"'\"";
	printf("\n====TESTE1===== Correto = \"a4\" \n");
	ft_expand(blk, TESTE);
	printf("\n====TESTE2===== Correto = \"$PAPERSIZE\" \n");
	ft_expand(blk, TESTE2);
	printf("\n====TESTE3===== Correto = '$PAPERSIZE'\n");
	ft_expand(blk, TESTE3);
	//printf("RESULTADO DO TESTE: %s\n", ft_var_ret(blk, "ASDAS="));
	//ft_prompt(blk, inp);
	//ft_freeing(blk->envp);
	free(blk);
	free(inp);
	return (0);
}
