# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 09:10:42 by juancarlosp       #+#    #+#              #
#    Updated: 2022/03/22 20:29:10 by jpopa-po         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/so_long.c  srcs/create_map.c srcs/fill_map.c srcs/movements.c

OBJS =  ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

LIBFTDIR = libft/
NAME = so_long
CC = gcc
FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: 	${NAME}

${NAME}: ${OBJS}
	make -sC ${LIBFTDIR}
	cp ./libft/libft.a .
	${CC} ${FLAGS} libft.a ${OBJS} -I ${INCLUDES} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@


clean:
			make -sC ${LIBFTDIR} clean
			${RM} ${OBJS} libft.a

fclean: clean
		make -sC ${LIBFTDIR} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

