NAME        = longest_word
SRC_DIR     = src
SRC         = $(SRC_DIR)/main.cpp         \
							$(SRC_DIR)/dictionnary.cpp  \
							$(SRC_DIR)/longest_word.cpp
INCLUDE_DIR = include
OBJ         = $(SRC:.cpp=.o)
CXX         = g++
CXXFLAGS    = -W -Wall -Wextra -std=c++11 -I $(INCLUDE_DIR)
RM          = rm -vf

all:      $(NAME)
$(NAME):  $(OBJ)
					$(CXX) -o $(NAME) $(OBJ)
					@echo "\033[33;01mCompilation terminée\033[00m"

clean:
					$(RM) $(OBJ)
					@echo "\033[34;01mFichiers .o effacés\033[00m"

fclean:   clean
					$(RM) $(NAME)
					@echo "\033[35;01mBinaire effacé\033[00m"

re:       fclean all