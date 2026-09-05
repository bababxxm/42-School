# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 22:10:21 by sklaokli          #+#    #+#              #
#    Updated: 2024/09/17 11:10:45 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= src/ft_printf.c src/format_c_pcnt.c src/format_s.c src/format_u.c src/format_p.c \
			src/format_d_i.c src/format_x_X.c src/additonal.c

OBJS	= ${SRCS:%.c=%.o}

AR		= ar -rcs

CC		= cc

FLAGS	= -Wall -Wextra -Werror

RM = rm -f

%.c%.o:
	${CC} %{FLAGS} -c $< -o ${<:%.c=%.o} I .

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re