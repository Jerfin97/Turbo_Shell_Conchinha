# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 10:29:53 by jeluiz4           #+#    #+#              #
#    Updated: 2023/02/04 18:29:58 by jeluiz4          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	sources/main.c \
		sources/lexer.c \
		sources/builtin/signal.c \
		sources/utils/init.c \
		sources/heredoc/heredoc.c \
		sources/builtin/exit.c \
		sources/builtin/pwd.c \
		sources/builtin/echo.c \
		sources/builtin/exec.c \
		sources/builtin/env.c \
		sources/builtin/builtin_utils/env_utils.c \
		sources/builtin/cd.c \
		sources/utils/free.c \
		sources/parse/lexer_utils.c \
		sources/parse/expand.c \
		sources/parse/expand_utils.c \
		sources/parse/expand_utils2.c \
		sources/pipes/pipes.c \
		sources/pipes/pipes_utils.c \
		sources/pipes/pipes_utils2.c \
		sources/parse/parse_utils.c \
		sources/parse/parse.c \
		sources/builtin/export.c \
		sources/builtin/unset.c \
		sources/builtin/builtin_utils/clean_export_unset.c \
		sources/redirect/redirect.c \
		sources/redirect/redirect_op.c \
		sources/redirect/redirect_utils.c \
		sources/redirect/redirect_utils2.c \
		sources/builtin/builtin_utils/ft_a_rlylong_int.c \
		sources/heredoc/heredoc_utils.c 

FLAGS = -Wall -Wextra -Werror -g

RM = rm -f

NAME = minishell

LIBD = "./libft/"

LIBA = "./libft/libft.a"

LREADLINE = -lreadline

# RIBA = -I /Users/dvargas/.brew/Cellar/readline/8.2.1/include

# HIBA = -L /Users/dvargas/.brew/Cellar/readline/8.2.1/lib

CC = cc

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):	$(OBJS)
	@printf "\e[1;94m=======================\e[0m\n"
	@printf "Waves in the ocean\n"
	@printf "\e[1;32m=======================\n"
	@cd $(LIBD) && make
#	$(CC) $(FLAGS) $(RIBA) -c $(SRCS)
# $(CC) $(OBJS) $(FLAGS) $(LREADLINE) $(LIBA) -o $(NAME) $(HIBA) $(RIBA)
	$(CC) $(OBJS) $(FLAGS) $(LREADLINE) $(LIBA) -o $(NAME)
	@printf "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⠤⠐⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡌⡦⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⣼⡊⢀⠔⠀⠀⣄⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣄⣀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣶⠃⠉⠡⡠⠤⠊⠀⠠⣀⣀⡠⠔⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⢟⠿⠛⠛⠁\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡇⠀⠀⠀⠀⠑⠶⠖⠊⠁⠀⠀⠀⡀⠀⠀⠀⢀⣠⣤⣤⡀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣿⣿⠟⡱⠁⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣾⣿⡇⠀⢀⡠⠀⠀⠀⠈⠑⢦⣄⣀⣀⣽⣦⣤⣾⣿⠿⠿⠿⣿⡆⠀⠀⢀⠺⣿⣿⣿⣿⡿⠁⡰⠁⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣧⣠⠊⣠⣶⣾⣿⣿⣶⣶⣿⣿⠿⠛⢿⣿⣫⢕⡠⢥⣈⠀⠙⠀⠰⣷⣿⣿⣿⡿⠋⢀⠜⠁⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢿⣿⣿⣿⣿⣰⣿⣿⠿⣛⡛⢛⣿⣿⣟⢅⠀⠀⢿⣿⠕⢺⣿⡇⠩⠓⠂⢀⠛⠛⠋⢁⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠘⢶⡶⢶⣶⣦⣤⣤⣤⣤⣤⣀⣀⣀⣀⡀⠀⠘⣿⣿⣿⠟⠁⡡⣒⣬⢭⢠⠝⢿⡡⠂⠀⠈⠻⣯⣖⣒⣺⡭⠂⢀⠈⣶⣶⣾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠙⠳⣌⡛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣵⣨⣿⣿⡏⢀⠪⠎⠙⠿⣋⠴⡃⢸⣷⣤⣶⡾⠋⠈⠻⣶⣶⣶⣷⣶⣷⣿⣟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠈⠛⢦⣌⡙⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠩⠭⡭⠴⠊⢀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⡇⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠈⠙⠓⠦⣄⡉⠛⠛⠻⢿⣿⣿⣿⣷⡀⠀⠀⠀⠀⢀⣰⠋⠀⠀⠀⠀⠀⣀⣰⠤⣳⣿⣿⣿⣿⣟⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠒⠒⠶⢺⣿⣿⣿⣿⣦⣄⣀⣴⣿⣯⣤⣔⠒⠚⣒⣉⣉⣴⣾⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠹⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣉⣉⣤⣿⣿⣿⣿⣿⣿⡿⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⡁⡆⠙⢶⣀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣴⣶⣾⣿⣟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢛⣩⣴⣿⠇⡇⠸⡆⠙⢷⣄⠻⣿⣦⡄⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣎⢻⣿⣿⣿⣿⣿⣿⣿⣭⣭⣭⣵⣶⣾⣿⣿⣿⠟⢰⢣⠀⠈⠀⠀⠙⢷⡎⠙⣿⣦⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⡆⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠟⠛⠋⠁⢀⠇⢸⡇⠀⠀⠀⠀⠈⠁⠀⢸⣿⡆⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡜⡿⡘⣿⣿⣿⣿⣿⣶⣶⣤⣤⣤⣤⣤⣤⣤⣴⡎⠖⢹⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⡄⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠛⠋⡟⠀⠀⣸⣷⣀⣤⣀⣀⣀⣤⣤⣾⣿⣿⣿⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣓⡲⠬⢭⣙⡛⠿⣿⣿⣶⣦⣀⠀⡜⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣛⣓⠶⠦⠥⣀⠙⠋⠉⠉⠻⣄⣀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣆⠐⣦⣠⣷⠊⠁⠀⠀⡭⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢉⣛⡛⢻⡗⠂⠀⢀⣷⣄⠈⢆⠉⠙⠻⢿⣿⣿⣿⣿⣿⠇⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡟⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣉⢁⣴⣿⣿⣿⣾⡇⢀⣀⣼⡿⣿⣷⡌⢻⣦⡀⠀⠈⠙⠛⠿⠏⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⡄⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠛⢯⡉⠉⠉⠉⠉⠛⢼⣿⠿⠿⠦⡙⣿⡆⢹⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠿⠄⠈⠻⠿⠿⠿⠿⠿⠿⠛⠛⠿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠻⠿⠿⠿⠿⠟⠉⠀⠀⠤⠴⠶⠌⠿⠘⠿⠿⠿⠿⠶⠤⠀⠀⠀⠀\n"
	@printf "\e[1;31m⡖⠒⠲⣄⡖⠒⡆⡖⢒⠒⡆⢖⠒⣤⠖⢲⠆⠀⢰⠒⠒⠒⢲⠒⡆⡖⢲⡖⠒⣒⣒⡆⠀⠀⢠⠒⠒⣒⡖⢲⢰⠒⢲⠒⢒⣒⣒⡖⢲⠀⠀⡖⢲⠀⠀⠀⠀⢰⣒⠒⢒⣒⠒⢶⡖⢒⣒⣒⡆⠀⢰⠒⠲⣴⠒⢲⡖⡖⢲⡖⠒⠒⢒⡖⢲⢰⠒⡆⠀⠀⢰⡒⠲⣤⠒⣲⡠⠒⠒⠒⢄⡖⢲⠀⡖⢲\e[0m\n"
	@printf "\e[1;31m⠉⡇⢀⠉⢀⠀⣿⠁⣾⡆⢳⡈⢆⠀⣠⠃⠀⠀⠈⢹⠀⡏⢹⠀⣉⡁⢸⡇⢘⣳⡆⠀⠀⠀⠈⢦⠈⢦⡇⠈⣉⠀⢸⠀⣛⣲⠀⡇⢸⠀⠀⡇⢸⠀⠀⠀⠀⠀⢹⠀⣙⣛⠠⢾⡇⢘⣻⡏⠀⠀⠈⠹⡀⠃⢀⠘⢁⡇⢸⠉⡇⢸⠉⡇⢈⣉⠀⡇⠀⠀⠀⠙⣆⠀⡴⢹⠀⢞⠉⡇⠈⡇⢸⠀⡇⢸\e[0m\n"
	@printf "\e[1;31m⠀⣇⣸⢷⢿⣀⣏⣠⠖⢦⣀⡇⢸⣀⡇⠀⠀⠀⠀⢸⣀⡇⢸⣀⡏⣇⣸⣇⣈⣉⣉⣹⢸⣉⣉⣉⣀⡸⣇⣸⢹⣀⣸⣀⣉⣉⣉⣇⣈⣉⣉⣇⣈⣉⣉⡇⠀⠀⢸⣀⣙⣚⣁⣼⣇⣈⣉⣉⣷⠀⠀⠀⢧⣀⣿⣄⣸⣇⣸⠀⣇⣸⠀⣇⣸⢸⣀⡇⠀⠀⠀⠀⢸⣀⡇⠈⠣⣈⣉⣡⠜⠳⣌⣙⣡⠞\e[0m\n"
	@printf "\n\n\n\n\n\n\n\n\n\n\n"

clean:
	@echo 'clean rule'
	@cd $(LIBD) && make clean
	@$(RM) $(OBJS)

fclean:
	@echo 'fclean rule'
	@cd $(LIBD) && make fclean
	@$(RM) $(OBJS) $(NAME)

re: fclean all
