/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_mini.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:26:18 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/30 07:37:09 by dvargas          ###   ########.fr       */
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
typedef struct s_input
{
	char	*cmd;
	char	**args;
	char	*echo_print;
	char	*new_path;
	char	*ex_name;
	char	*ex_val;
	char	*un_name;
	int		exit_error;
}				t_input;

//Init
void		shellinit(t_shell *blk, t_input *inp);
t_shell		*ft_blkinit(void);
t_input		*ft_inputinit(void);

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
void		ft_cd(t_shell *blk, char *str);
void		ft_pwd(t_shell *blk);

//ENV CREATION / ENV MANIPULATION
char		**ft_build_env(char **envp);
char		*ft_search(char **env, char *str);
int			ft_new_pwd(t_shell *blk, char *str, char *str2);
int			ft_freeing(char	**matriz);
void		ft_export(t_shell *blk, char *str, char *str2);
void		ft_printenv(t_shell *blk);
void		ft_unset(t_shell *blk, char *str);
char		**ft_build_unset(t_shell *blk, char *str);
#endif
