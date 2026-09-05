# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 04:16:43 by sklaokli          #+#    #+#              #
#    Updated: 2025/09/18 13:25:16 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombieHorde

HDRS	=	Zombie.hpp
SRCS	=	main.cpp Zombie.cpp zombieHorde.cpp
OBJS	=	$(SRCS:.cpp=.o)

RM		=	rm -f
CPP		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic

%.o: 		%.cpp $(HEADERS)
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