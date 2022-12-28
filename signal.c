#include "lib_mini.h"

// Forma de lidar com o sinal recebido pela main.
// SigINT me mostra uma nova linha
// SigQUIT deve ser ignorado, eu fiz essa logica com sigaction,
// precisa declarar uma estrutura sigaction para ignorar o sinal.

void	signal_handler(int signo)
{
	//struct sigaction sig;

	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	/*
	else if (signo == SIGQUIT)
	{
		//sig.sa_handler = SIG_IGN;
		//sigaction(SIGQUIT, &sig, NULL);
	}
	*/
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
