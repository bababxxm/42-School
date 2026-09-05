# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 16:53:37 by sklaokli          #+#    #+#              #
#    Updated: 2025/09/16 18:31:58 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	megaphone

SRC		:=	megaphone.cpp
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