/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_mini.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:26:18 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/29 07:18:36 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MINI_H
# define LIB_MINI_H

# include "libft/libft.h"
# include <stdio.h>
# include "/usr/include/readline/readline.h"
# include "/usr/include/readline/history.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>

typedef struct s_shell
{
	char	**cmd;
	int		i;
	int		rs;
	char	*buf;
	char	**envp;
}				t_shell;

//Init
t_shell *ft_blkinit(void);

// Signal Handler

void	signal_handler(int signo);
void	ft_suppress_output(void);
#endif
