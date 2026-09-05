# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 01:09:03 by sklaokli          #+#    #+#              #
#    Updated: 2025/09/17 04:01:04 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	bank

SRC		:=	Account.cpp tests.cpp
OBJ		:=	$(SRC:.cpp=.o)

RM		:=	rm
CPP		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98

%.o: 		%.cpp
			$(CPP) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ) Makefile
			$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:
			$(RM) -r $(OBJ) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re