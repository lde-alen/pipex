# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:27:53 by lde-alen          #+#    #+#              #
#    Updated: 2022/03/15 19:10:03 by lde-alen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		pipex

SRCS		=		./srcs/childs.c			\
					./srcs/pipex_utils.c	\
					./srcs/pipex_utils_2.c	\
					./srcs/error_check.c	\
					./srcs/pipex_2.c		\
					./srcs/pipex.c			\
					./srcs/main.c			\

OBJS		=		$(SRCS:.c=.o)

CFLAGS		=		-Wall -Wextra -Werror -g3

CC			=		gcc

$(NAME)		:		$(OBJS)
					$(CC) $(SRCS) -o $(NAME)

all			:		$(NAME)

clean		:
					rm -rf $(OBJS)

fclean		:		clean
					rm -rf $(NAME)

re			:		fclean all

.PHONY		:		all clean fclean re
