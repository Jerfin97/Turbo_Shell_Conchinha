/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:17:32 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/27 11:47:11 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

int	g_rs;

// Separado porque ele sempre vai manter o historico se for comando ou não.
void	ft_history(char *str)
{
	if (str && *str)
		add_history(str);
}

int	ft_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

// A Ideia é só chamar o exec pra forkar e executar o comando.
// E retornar o signal 0 se der bom ou o de erro Caso de merda.
int	ft_exec(char *cmd, char *flag, char *content)
{
	cmd = flag;
	content = flag;
	flag = cmd;
	return (1);
}

// A Ideia é separar tudo para dar mastigado pro exec e seguir a vida.
void	ft_lexer(char *str)
{
	int	i;

	i = 0;
	while (ft_space(str[i]))
		i++;
	while (!ft_space(str[i]))
		i++;
	printf("Pos digits %s\n", (str + i));
}

// É o nucleo do codigo Aqui que começa o merderê todo.
int	ft_prompt(t_shell *blk)
{
	while (42)
	{
		blk->buf = readline("Conchinha/> ");
		ft_history(blk->buf);
		//ft_lexer(blk->buf);
		free(blk->buf);
	}
	rl_clear_history();
}

// Samerda ta aqui só pq tem que ta mesmo.
int	main(void)
{
	t_shell	blk;

	ft_prompt(&blk);
	return (0);
}
