##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -W -Wall -Wextra -fno-gnu-unique -fPIC
LDFLAGS = -lncurses -lSDL2 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

LIB = arcade_nibbler.so

all: $(LIB)

$(LIB): $(OBJ)
	$(CXX) $(OBJ) -shared -o $(LIB) $(LDFLAGS)
	mv $(LIB) ../../../lib/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB)

re: fclean all

.PHONY: clean fclean
.SILENT: all
