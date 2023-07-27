##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
## File description:
## Makefile
##

CXX = g++
LDFLAGS = -ldl -fno-gnu-unique
CXXFLAGS = -W -Wall -Wextra -std=c++17

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

BIN = arcade

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $(BIN) $(OBJ) $(LDFLAGS)
	mv $(BIN) ../../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)

re: fclean all

.SILENT:
