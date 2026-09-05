# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:44:55 by sklaokli          #+#    #+#              #
#    Updated: 2025/09/16 18:32:09 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	phonebook

SRC		:=	Main.cpp Contact.cpp PhoneBook.cpp
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