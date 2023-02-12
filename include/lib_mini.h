/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_mini.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:26:18 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/02/06 15:24:34 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MINI_H
# define LIB_MINI_H

# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/ioctl.h>
//# include <readline/readline.h>
//# include <readline/history.h>
# include "readline/readline.h"
# include "readline/history.h"
# include <sys/types.h>
# include <dirent.h>
# include <limits.h>

# define SHIFT_R   'A'
# define SHIFT_L   'B'
# define SHIFT_DR  'C'
# define SHIFT_DL  'D'

extern long int		g_return;

//STRUCT CORE DO MINISHELL
typedef struct s_shell
{
	char		**cmd;
	int			doc;
	int			i;
	int			fd_in;
	int			append;
	char		**heredoc_list;
	const char	*infilename;
	char		*outfile_name;
	char		*exp;
	int			rs;
	int			ctrl;
	int			qtd;
	char		*buf;
	char		**envp;
	char		*tmpdoc;
	int			stdin_backup;
	int			stdout_backup;
	char		*tmp;
	char		*aux;
	int			*pid;
	char		*pwd;
	char		*og;
}				t_shell;
//STRUCT DE INPUT
typedef struct s_input
{
	char	*cmd;
	char	*tmp;
	char	**args;
	char	**paths;
	char	**temp;
	char	*echo_print;
	char	*new_path;
	char	*ex_name;
	char	*ex_val;
	char	*un_name;
	int		exit_error;
	int		size;
}				t_input;

//Init
t_shell		*ft_blk_init(void);
t_input		*ft_input_init(void);

// LEXER
void		ft_lexer(t_shell *blk, t_input *inp);
int			ft_count_symbols(char *str);
void		ft_size_args(t_input *inp, t_shell *blk, int i, int j);
void		ft_redir_path(t_input *inp, t_shell *blk);

// PARSER
int			ft_has_input_next(char *str, char *sep);
char		**ft_hand_split(char *str, char *sep);
int			ft_i_next_input(char *str);
int			ft_find_str(char *str, char *sep, int i, int p);
int			ft_split_count(char *str, char *sep);
char		**ft_split_in_spaces(char *dirty, int i, int j, int quote);
char		*ft_space_clean(char *str);
char		*ft_remove_quotes(char *str);
void		uptick_str(int *mirror_flag, int *i, int val);
char		*ft_remove_quotes(char *str);

//Redirect

char		**ft_split_in_redirect(char *str);
int			ft_count_symbols(char *str);
int			ft_i_next_redir(char *str);
int			ft_count_redir_sep(char *str);
int			ft_is_redir_sep(char *str, int i);
char		*ft_red_stk(char *str);
void		ft_simple_redirect(t_shell *blk, t_input *inp, \
				char **splited, char *str);
char		**ft_compose_cmd(char **matrix);
int			ft_heredoc_open(t_shell *blk, char *str);
int			ft_infile_open(t_shell *blk, char *str);
int			ft_outfile_open(char **str, int j, int flag, t_shell *blk);
int			ft_split_inf(t_shell *blk, char **tmp, int j);
int			ft_split_hdoc(t_shell *blk, char **tmp, int j, int i);
char		*ft_redirect_clean(char *str);
int			ft_open_func(t_shell *blk, char *aux, int flag);

//Heredoc
void		ft_heredoc(t_shell *blk, char *hereword, int pos);
void		ft_create_docs(t_input *inp, t_shell *blk);

// Signal Handler
void		signal_handler(int signo);
void		ft_suppress_output(void);
void		ft_exit_d(t_shell *blk, t_input *inp);
void		ft_child_signal(void);

//EXECUTE
int			ft_exec(t_input *inp, t_shell *blk);
void		ft_access(t_shell *blk, t_input *inp);
void		ft_pipe_handle(t_shell *blk, t_input *inp);
int			ft_access_pipe(t_shell *blk, t_input *inp);
int			ft_build_path(t_input *inp);
int			ft_mid_exec(t_input *inp, t_shell *blk);
int			ft_beg_exec(t_input *inp, t_shell *blk);
int			ft_end_exec(t_input *inp, t_shell *blk);

//PARSER
int			ft_is_builtin(t_shell *blk, char **args);
int			ft_switch(t_shell *blk, t_input *inp, int i);
void		built_run(t_input *inp, t_shell *blk, char **args);
void		ft_cleanse(t_shell *blk, char **args);
char		**ft_hand_split(char *str, char *sep);

//BUILTINS
void		ft_echo(t_input *inp, char **args);

void		ft_exit(t_input *inp, t_shell *blk, char **args);
long int	*ft_a_rlylong_int(char *str, int i, unsigned long long out);

void		ft_cd(t_shell *blk, char *str, char **args);
void		ft_pwd(t_shell *blk, char **args);
void		ft_printenv(t_shell *blk, char **args);
void		ft_export(t_shell *blk, char *str, char *str2);
void		ft_unset(t_shell *blk, char **args);

//ENV CREATION; ENV MANIPULATION
char		**ft_build_env(char **envp);
char		*ft_search(char **env, char *str);
int			ft_new_pwd(t_shell *blk, char *str, char *str2);
int			ft_freeing(char	**matriz);
char		**ft_build_unset(t_shell *blk, char *str);
int			ft_valid_name(char *str, int flag);

//VAR EXPAND
int			ft_var_exist(char **env, char *str);
char		*ft_var_ret(t_shell *blk, char *str);
char		*ft_expand(t_shell *blk, char *str);
char		*ft_create_var(char *str, int i, int start, char *tmp);
int			ft_validate_quotes(char *str);
int			ft_update_quote(int *flag, char c);
int			ft_var_size(char *str);
char		*ft_chase(t_shell *blk, char *str, int i, int flag);
int			ft_var_isvalid(char *str);

//PIPES
void		ft_restore_fds(t_shell *blk);
void		ft_redirect_infile(t_shell *blk);
void		ft_pipe_handle(t_shell *blk, t_input *inp);
int			ft_is_dir(char *path);
void		ft_end_pipes(t_shell *blk, t_input *inp);
void		ft_pid_control(t_shell *blk, int pid);
void		ft_process_error(t_shell *blk, t_input *inp);

#endif
