# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 05:11:29 by sklaokli          #+#    #+#              #
#    Updated: 2025/09/18 19:19:44 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	zombie

HDRS	:=	Zombie.hpp
SRCS	:=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS	:=	$(SRCS:.cpp=.o)

RM		:=	rm -f
CPP		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -pedantic

%.o: 		%.cpp $(HDRS)
			$(CPP) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) Makefile
			$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
re:			fclean all

.PHONY:		all clean fclean re