/**
 * @file SnakeException.hpp
 * @brief SnakeException class declaration
*/

/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
** File description:
** snakeException
*/

#ifndef SNAKEEXCEPTION_HPP_
#define SNAKEEXCEPTION_HPP_

#include <iostream>
#include <string>
#include <exception>

namespace arcade {
    /**
     * @class SnakeException
     * @brief The SnakeException class is responsible for handling exceptions raised in the Snake class.
    */
    class SnakeException : public std::exception {
    public:
        /**
         * @brief Constructor of the SnakeException class.
         * @param message The error message to be displayed.
        */
        SnakeException(const std::string &message) : _message(message) {}

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


#endif /* !SNAKEEXCEPTION_HPP_ */
