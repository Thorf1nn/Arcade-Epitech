##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
## File description:
## Makefile
##

all:
	make -C src/core/ arcade
	make -C src/graphicals/
	make -C src/games/

core:
	make -C src/core/ arcade

graphicals:
	make -C src/graphicals/

games:
	make -C src/games/

clean:
	make -C src/core/ clean
	make -C src/graphicals/ clean
	make -C src/games/ clean

fclean: clean
	$(RM) arcade
	$(RM) lib/*.so
	make -C src/graphicals/ fclean
	make -C src/games/ fclean

re: fclean all
