/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:32:11 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/28 11:50:46 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib_mini.h"

void	signal_handler(int signo)
{
	int	i;

	i = -42;
	wait(&i);
	if (signo == SIGINT && (i == -42))
	{
		g_return = 130;
		if (RL_ISSTATE(RL_STATE_READCMD))
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
		else
			write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
	else if (i != -42)
	{
		g_return = i;
		write(1, "\n", 1);
		rl_replace_line("\n", 0);
		rl_redisplay();
	}
}

void	ft_suppress_output(void)
{
	struct termios	new_settings;

	if (tcgetattr(0, &new_settings))
		perror("minishell: tcsetattr");
	new_settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &new_settings))
		perror("minishell: tcsetattr");
}

void	ft_child_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
