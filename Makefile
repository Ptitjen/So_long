# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:12:49 by jeulliot          #+#    #+#              #
#    Updated: 2022/03/28 11:16:03 by jeulliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/anim.c srcs/enemy.c srcs/errors.c srcs/exit.c \
			srcs/food.c srcs/ft_itoa.c srcs/ft_split.c \
			srcs/get_next_line_utils.c \
			srcs/get_next_line.c srcs/landscape.c srcs/launch_game.c \
			srcs/load_images.c srcs/main.c 	srcs/manage_map.c \
			srcs/screens.c srcs/unicorn.c srcs/utils.c srcs/utils2.c \
			srcs/utils3.c

NAME	= so_long

CC	= gcc

RM	= rm -f

all:	$(NAME)		

$(NAME):	${SRCS}
			@gcc -I /usr/local/include ${SRCS}  -L /usr/local/lib -lmlx \
			-framework OpenGL -framework AppKit -o ${NAME}
			
clean:

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
