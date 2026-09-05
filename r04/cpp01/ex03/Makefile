# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 04:16:43 by sklaokli          #+#    #+#              #
#    Updated: 2025/09/22 22:24:02 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	humanBattle

SRCS	:=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS	:=	$(SRCS:.cpp=.o)

RM		:=	rm -f
CPP		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -pedantic

%.o: 		%.cpp
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