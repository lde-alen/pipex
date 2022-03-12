# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:27:53 by lde-alen          #+#    #+#              #
#    Updated: 2022/03/12 14:41:02 by lde-alen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		pipex

SRCS		=		./srcs/childs.c			\
					./srcs/pipex.c			\
					./srcs/main.c			\
					./srcs/error_check.c	\

OBJS		=		$(SRCS:.c=.o)

CFLAGS		=		-Wall -Wextra -Werror

CC			=		gcc

$(NAME)		:		$(OBJS)
					$(MAKE) -C ./libft
					$(CC) $(SRCS) ./libft/libft.a -o $(NAME)

all			:		$(NAME)

clean		:
					$(MAKE) clean -C ./libft
					rm -rf $(OBJS)

fclean		:		clean
					$(MAKE) fclean -C ./libft
					rm -rf $(NAME)

re			:		fclean all

.PHONY		:		all clean fclean re
