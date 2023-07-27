/**
 * @file main.cpp
 * @brief Main function
*/

/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Main
*/

#include <iostream>
#include "Core.hpp"
#include <csignal>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./arcade <lib_graphic.so>" << std::endl;
        return 84;
    }

    try {
        arcade::Core arcade(av[1]);
        arcade.launch();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
