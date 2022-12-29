/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:32:11 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/29 15:20:02 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

// Forma de lidar com o sinal recebido pela main.
// SigINT me mostra uma nova linha
// SigQUIT deve ser ignorado, eu fiz essa logica com sigaction,
// precisa declarar uma estrutura sigaction para ignorar o sinal.

void	signal_handler(int signo)
{
	int	i;
	//struct sigaction sig;

	i = -42;
	wait(&i);
	if (signo == SIGINT && (i == -42))
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signo == SIGQUIT)
	{
		//sig.sa_handler = SIG_IGN;
		//sigaction(SIGQUIT, &sig, NULL);
		rl_redisplay();
	}
	else if (i != -42)
	{
		write(1, "\n", 1);
		rl_replace_line("\n", 0);
		rl_redisplay();
	}
}

//Modifica as configurações do terminal para nao imprimir os comandos do teclado

void	ft_suppress_output(void)
{
	struct termios	new_settings;

	if (tcgetattr(0, &new_settings))
		perror("minishell: tcsetattr");
	new_settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &new_settings))
		perror("minishell: tcsetattr");
}
