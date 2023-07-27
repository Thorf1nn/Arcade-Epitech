##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -W -Wall -Wextra -fno-gnu-unique -fPIC -I/usr/include/SDL2
LDFLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image 

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

LIB = arcade_sdl2.so

all: $(LIB)

$(LIB): $(OBJ)
	$(CXX) $(OBJ) -shared -o $(LIB) $(LDFLAGS)
	mv $(LIB) ../../../lib/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB)

re: fclean all

.SILENT: all
