/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:17:32 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/29 07:19:41 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

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

int	ft_exec(char *cmd, char **args, char **envp, t_shell *blk)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, args, envp);
	}
	else if ((pid > 0) && (pid != -1))
	{
		wait(&blk->rs);
		return (blk->rs);
	}
	perror("fork crash");
	return (127);
}

// A Ideia é separar tudo para dar mastigado pro exec e seguir a vida.
int	ft_lexer(t_shell *blk)
{
	//int		i;
	//char	**cmd;

	//i = 0;
	printf("%s\n",blk->buf);
	//blk->rs = ft_exec("/usr/bin/ls", oi, blk->envp);
	//cmd = ft_split(blk->buf, ' ');
	return (0);
}

void	ft_exit(char *str)
{
	if (!ft_strncmp(str, "exit", 4) || str == NULL)
	{
		free(str);
		write(1, "exit\n", 5);
		exit(0);
	}
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
		ft_exit(blk->buf);
		ft_history(blk->buf);
		//ft_lexer(blk);
		ft_exec("./a.out", oi, blk->envp, blk);
		free(blk->buf);
	}
	free(oi);
	rl_clear_history();
}


// Samerda ta aqui só pq tem que ta mesmo.
int	main(int argc, char **argv, char **envp)
{
	t_shell	*blk;

	(void)argc;
	(void)argv;
	blk = ft_blkinit();
	blk->envp = envp;
	ft_suppress_output();
	signal(SIGINT,  signal_handler);
	signal(SIGQUIT, signal_handler);
	ft_prompt(blk);
	return (0);
}
