# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 20:07:04 by sklaokli          #+#    #+#              #
#    Updated: 2025/12/10 17:04:14 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	test

INC_DIR		:=	include
SRC_DIR		:=	src
OBJ_DIR		:=	bin

FILES		:=	main.cpp \
				AAnimal.cpp \
				Brain.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \

SRC			:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(FILES:%.cpp=%.o))

CXX			:=	c++
WFLAGS		:=	-Wall -Wextra -Werror
STDFLAGS	:=	-std=c++98 -pedantic
INCLUDE		:=	-I$(INC_DIR)

COMPILE		:=	$(CXX) $(WFLAGS) $(STDFLAGS) $(INCLUDE)

all:	$(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(COMPILE) -c $< -o $@

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re