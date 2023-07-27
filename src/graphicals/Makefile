##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
## File description:
## Makefile
##

all:
	make -C SFML/ arcade_sfml.so
	make -C SDL/ arcade_sdl2.so
	make -C ncurses/ arcade_ncurses.so

clean:
	make -C ncurses/ clean
	make -C SFML/ clean
	make -C SDL/ clean

fclean: clean
	make -C ncurses/ fclean
	make -C SFML/ fclean
	make -C SDL/ fclean

re: fclean all