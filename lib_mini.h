/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_mini.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:26:18 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/29 11:55:16 by jeluiz4          ###   ########.fr       */
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
# include <fcntl.h>

//STRUCT CORE DO MINISHELL
typedef struct s_shell
{
	char	**cmd;
	int		i;
	int		rs;
	char	*buf;
	char	**envp;
	char	*tmpdoc;
}				t_shell;

//STRUCT DE INPUT
typedef struct s_lst_input
{
	char	*cmd;
	char	**args;
	char	*echo_print;
	char	*new_path;
	char	*ex_name;
	char	*ex_val;
	char	*un_name;
	int		exit_error;
}				t_lst_input;

//STRUCT DO ENVP
typedef struct s_lst_env
{
	char				*line;
	struct s_lst_env	*nxt;
}				t_lst_env;

//Init
void		ft_shellinit(t_shell *blk, t_lst_input *inp, t_lst_env *env);
t_lst_env	*ft_envinit(void);
t_shell		*ft_blkinit(void);
t_lst_input	*ft_inputinit(void);

//Heredoc
void		ft_heredoc(t_shell *blk, char *hereword);

// Signal Handler
void		signal_handler(int signo);
void		ft_suppress_output(void);

//EXECUTE
int			ft_exec(char *cmd, char **args, char **envp, t_shell *blk);

//BUILTINS
void		ft_echo(int flag, char *content, t_shell *blk);
void		ft_exit(char *str);
void		ft_cd(t_shell *blk, t_lst_env *env, t_lst_input *inp);
#endif
