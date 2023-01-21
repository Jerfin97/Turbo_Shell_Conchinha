/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_mini.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:26:18 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/20 11:44:56 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MINI_H
# define LIB_MINI_H

# include <stdio.h>
# include <errno.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>
# include <fcntl.h>
//# include <readline/readline.h>
//# include <readline/history.h>
# include "readline/readline.h"
# include "readline/history.h"

# define SHIFT_R   'A'
# define SHIFT_L   'B'
# define SHIFT_DR  'C'
# define SHIFT_DL  'D'

//STRUCT CORE DO MINISHELL
typedef struct s_shell
{
	char		**cmd;
	int			i;
	int			fd_in;
	int			append;
	char		*heredoc_name;
	const char	*infilename;
	char		*outfile_name;
	char		*exp;
	int			rs;
	char		*buf;
	char		**envp;
	char		*tmpdoc;
	int			stdin_backup;
	int			stdout_backup;
	char		*tmp;
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
void		ft_sonic(void);

// LEXER
void		ft_lexer(t_shell *blk, t_input *inp);
int			ft_count_symbols(char *str);

// PARSER
int			ft_has_input_next(char *str, char *sep);
char		**ft_hand_split(char *str, char *sep);
int			ft_i_next_input(char *str);
int			ft_find_str(char *str, char *sep);
int			ft_split_count(char *str, char *sep);
char		**ft_split_in_spaces(char *dirty, int i, int j, int quote);
char		*ft_space_clean(char *str);
void		ft_swapjoinchar(char **s1, char s2);

//Redirect

char		**ft_split_in_redirect(char *str);
int			ft_count_symbols(char *str);
int			ft_i_next_redir(char *str);
int			ft_count_redir_sep(char *str);
int			ft_is_redir_sep(char *str, int i);
char		*ft_red_stk(char *str);

//Heredoc
void		ft_heredoc(t_shell *blk, char *hereword);

// Signal Handler
void		signal_handler(int signo);
void		ft_suppress_output(void);
void		ft_exit_d(t_shell *blk);

//EXECUTE
int			ft_exec(t_input *inp, t_shell *blk);
void		ft_access(t_shell *blk, t_input *inp);
void		ft_pipe_handle(t_shell *blk, t_input *inp);
int			ft_access_pipe(t_shell *blk, t_input *inp, int i);
int			ft_build_path(t_shell *blk, t_input *inp);
int			ft_mid_exec(t_input *inp, t_shell *blk);
int			ft_beg_exec(t_input *inp, t_shell *blk);
int			ft_end_exec(t_input *inp, t_shell *blk);

//PARSER
int			ft_is_builtin(t_shell *blk, char **args);
int			ft_switch(t_shell *blk, t_input *inp, int i);
void		built_run(t_input *inp, t_shell *blk, char **args);
void		ft_cleanse(t_shell *blk, char **args);
char		**ft_hand_split(char *str, char *sep);
int			ft_find_str(char *str, char *sep);

//BUILTINS
void		ft_echo(t_shell *blk, t_input *inp, char **args);
void		ft_exit(t_input *inp, t_shell *blk, char **args);
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

//VAR EXPAND
int			ft_var_exist(char **env, char *str);
char		*ft_var_ret(t_shell *blk, char *str);
char		*ft_expand(t_shell *blk, char *str);
char		*ft_create_var(char *str, int i, int start, char *tmp);
int			ft_validate_quotes(char *str);
int			ft_update_quote(int *flag, char c);
int			ft_var_size(char *str);
void		ft_swapjoin(char **s1, char *s2);
char		*ft_chase(t_shell *blk, char *str);
int			ft_var_isvalid(char *str);

//PIPES
void		ft_restore_fds(t_shell *blk);
void		ft_redirect_infile(t_shell *blk);
void		ft_pipe_handle(t_shell *blk, t_input *inp);

#endif
