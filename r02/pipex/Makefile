# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:44:55 by sklaokli          #+#    #+#              #
#    Updated: 2025/06/02 13:04:18 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pipex
LIBFT		:=	libft/libft.a

SRC_DIR		:=	src
OBJ_DIR		:=	obj
INC_DIR		:=	inc

INC			:=	-I$(INC_DIR) -Ilibft/inc
DEPS		:=	$(INC_DIR)/$(NAME).h

FILES		:=	main.c \
				utils.c

SRC			:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

COMPILED	:=	0
TOTAL_FILES	:=	$(words $(OBJ))

CYAN		:=	\033[1;36m
GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
BLUE		:=	\033[1;34m
YELLOW		:=	\033[1;33m
RESET		:=	\033[0m

CC			:=	cc
RM			:=	rm -f
AR			:=	ar rcs
WFLAGS		:=	-Wall -Wextra -Werror
VFLAGS		:=	--tool=helgrind
FDFLAGS		:=	--track-fds=yes --trace-children=yes

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(DEPS)
				@ mkdir -p $(dir $@)
				@ $(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
				@ PERCENT=$$(($(COMPILED)*100/$(TOTAL_FILES))); \
				echo "$(BLUE)[$(COMPILED)/$(TOTAL_FILES)] Compiling $< ($$PERCENT%)$(RESET)\r"; \
				$(CC) $(WFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

$(NAME):	Makefile $(LIBFT) $(OBJ)
			@ $(CC) $(WFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@ echo "$(GREEN)[OK] $(NAME) built succesfully.$(RESET)"

$(LIBFT):
			@ $(MAKE) -sC libft

clean:		Makefile
			@ $(RM) -rf $(OBJ_DIR)
			@ $(MAKE) -sC libft clean
			@ echo "$(CYAN)$(NAME) object files cleaned.$(RESET)"

fclean:		Makefile clean
			@ $(RM) -rf $(OBJ_DIR) $(NAME)
			@ $(MAKE) -sC libft fclean
			@ echo "$(CYAN)$(NAME) executable files cleaned.$(RESET)"

valgrind:	Makefile
			valgrind $(VFLAGS) ./$(NAME)

re:			Makefile fclean all

.PHONY:		all clean fclean re