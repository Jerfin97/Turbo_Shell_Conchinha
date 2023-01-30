/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:17:32 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/29 21:54:16 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"

long long int	g_return;

void	ft_history(char *str)
{
	if (str && *str)
		add_history(str);
}

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

char	*ft_redirect_clean(char *str);

int	main(int argc, char **argv, char **envp)
{
	t_shell		*blk;
	t_input		*inp;

	g_return = 0;
	(void)argc;
	(void)argv;
	blk = ft_blk_init();
	inp = ft_input_init();
	blk->envp = ft_build_env(envp);
	ft_suppress_output();
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	ft_prompt(blk, inp);
	ft_freeing(blk->envp);
	free(blk);
	free(inp);
	return (0);
}
