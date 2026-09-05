NAME		:=	btc

SRC_DIR		:=	src
OBJ_DIR		:=	bin
INC_DIR		:=	include

FILES		:=	main.cpp \
				BitcoinExchange.cpp

SRC			:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(FILES:%.cpp=%.o))
DEP			:=	$(OBJ:%.o=%.d)

CXX			:=	c++

CXXFLAGS	+=	-Wall -Wextra -Werror
CXXFLAGS	+=	-std=c++98 -pedantic
CXXFLAGS	+=	-MMD -MP
CXXFLAGS	+=	-I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
