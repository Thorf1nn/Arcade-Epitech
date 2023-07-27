/**
 * @file SFMLException.hpp
 * @brief SFMLException class declaration
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_SFMLEXCEPTION_HPP
** File description
** SFMLException
*/

#ifndef ARCADE_SFMLEXCEPTION_HPP
#define ARCADE_SFMLEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

namespace arcade {
    /**
     * @class SFMLException
     * @brief The SFMLException class is responsible for handling exceptions raised in the SFML class.
     */
    class SFMLException {
    public:
        /**
         * @brief Constructor of the SFMLException class.
         * @param message The error message to be displayed.
         */
        SFMLException(const std::string &message) : _message(message) {}

        /**
         * @brief Returns the error message.
         * @return The error message.
         */
        const char *what() const noexcept {
            return _message.c_str();
        }

    private:
        std::string _message;
    };
} // arcade

#endif //ARCADE_SFMLEXCEPTION_HPP