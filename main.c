/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:17:32 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/17 22:12:49 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

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
		blk->buf = readline("\e[1;93mConchinha/> \e[0m");
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
	//char		TESTE[99] = "$PATH";

	(void)argc;
	(void)argv;
	blk = ft_blk_init();
	inp = ft_input_init();
	blk->envp = ft_build_env(envp);
	ft_suppress_output();
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	//ft_access(blk, inp);
	char *teste = "< file.txt grep file";
	printf("Deveria ser 1 Resultado: %d\n", ft_count_symbols(teste));


	char *teste2 = ">> OLA MUNDO >>< Vai dar erro aqui";
	printf("Deveria ser -1 Resultado: %d\n", ft_count_symbols(teste2));


	char *teste3 = "cat main.c > file1.txt | > outfile.txt";
	printf("Deveria ser 2 Resultado: %d\n", ft_count_symbols(teste3));


	char *teste4 = "cat main.c << heredoc >> file1.txt >> file2.txt";
	printf("Deveria ser 3 Resultado: %d\n", ft_count_symbols(teste4));


	char *teste5 = "cat main.c > < algo aqui >> OREMOS";
	printf("Deveria ser -1 Resultado: %d\n", ft_count_symbols(teste5));


	char *teste6 = "<file1.txt>>mais>>um>teste>>infernal";
	printf("Deveria ser 5 Resultado: %d\n", ft_count_symbols(teste6));

	//ft_prompt(blk, inp);
	ft_freeing(blk->envp);
	//ft_freeing(teste2);
	free(blk);
	free(inp);
	return (0);
}
