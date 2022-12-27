# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 10:29:53 by jeluiz4           #+#    #+#              #
#    Updated: 2022/12/27 11:25:45 by jeluiz4          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c 

FLAGS = cc -Wall -Wextra -Werror -lreadline -g

RM = rm -f

NAME = minishell

LIBD = "libft/"
LIBA = "libft/libft.a"

all: minishell

$(NAME):
	cd $(LIBD) && make
	$(FLAGS) $(SRCS) $(LIBA) -o $(NAME)

clean:
	cd $(LIBD) && make clean
	$(RM) $(NAME)

fclean:
	cd $(LIBD) && make fclean
	$(RM) $(NAME)

re: fclean all
