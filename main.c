/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:17:32 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/27 14:54:26 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include <readline/readline.h>
#include <signal.h>

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

int	ft_exec(char *cmd, char **args, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, args, envp);
		return (0);
	}
	else if ((pid > 0) && (pid != -1))
	{
		wait(NULL);
		return (0);
	}
	perror("fork crash");
	return (127);
}

// A Ideia é separar tudo para dar mastigado pro exec e seguir a vida.
int	ft_lexer(char *str)
{
	int	i;

	i = 0;
	if (str && *str)
	{
		while (ft_space(str[i]))
			i++;
		while (ft_space(str[i]))
			i++;
		return (1);
	}
	return (0);
}

// É o nucleo do codigo Aqui que começa o merderê todo.
int	ft_prompt(t_shell *blk)
{
	char	**oi;

	oi = malloc(8 * 2);
	oi[0] = "ls";
	oi[1] = "-la";
	while (42)
	{
		blk->buf = readline("Conchinha/> ");
		if (!ft_strncmp(blk->buf, "exit", 4) || blk->buf == NULL)
		{
			write(1, "exit\n", 5);
			exit(99);
		}
		ft_history(blk->buf);
	//	if (ft_lexer(blk->buf) && blk->buf != NULL)
	//	{
		//	blk->rs = ft_exec("/usr/bin/ls", oi, blk->envp);
	//	}
	//	printf("rs %d\n", blk->rs);
		free(blk->buf);
	}
	free(oi);
	rl_clear_history();
}

// Samerda ta aqui só pq tem que ta mesmo.
int	main(int argc, char **argv, char **envp)
{
	t_shell	blk;

	(void)argc;
	(void)argv;
	blk.envp = envp;
	ft_suppress_output();
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	ft_prompt(&blk);
	return (0);
}
