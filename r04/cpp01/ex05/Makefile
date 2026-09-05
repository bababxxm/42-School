# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 01:47:49 by sklaokli          #+#    #+#              #
#    Updated: 2025/09/23 02:04:55 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	harl

SRCS	:=	main.cpp Harl.cpp
OBJS	:=	$(SRCS:.cpp=.o)

RM		:=	rm -f
CPP		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -pedantic

%.o: 	%.cpp
		$(CPP) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) Makefile
			$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re