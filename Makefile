# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 10:29:53 by jeluiz4           #+#    #+#              #
#    Updated: 2023/01/08 10:25:41 by dvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		signal.c \
		init.c \
		heredoc.c \
		exit.c \
		pwd.c \
		echo.c \
		exec.c \
		env.c \
		env_utils.c \
		cd.c \
		free.c \
		lexer.c \
		expand.c \
		expand_utils.c \
		pipes.c \
		pipes_utils.c \
		parse_utils.c

FLAGS = cc -Wall -Wextra -Werror -g

RM = rm -f

NAME = minishell

LIBD = "libft/"
LIBA = "libft/libft.a"
LREADLINE = -lreadline
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME):
	@echo "\e[1;94m======================="
	@echo "Waves in the ocean"
	@echo "======================="
	@ cd $(LIBD) && make
	@$(FLAGS) -c $(SRCS) 
	@$(FLAGS) $(OBJS) $(LIBA) -o $(NAME) $(LREADLINE)
	@echo "======================="
	@echo "\e[1;93mThe shell is ready\e[0m"
	@echo "\e[1;94m======================="

clean:
	@echo 'clean rule'
	@cd $(LIBD) && make clean
	@$(RM) $(OBJS)

fclean:
	@echo 'fclean rule'
	@ cd $(LIBD) && make fclean
	@$(RM) $(OBJS) $(NAME)

re: fclean all
