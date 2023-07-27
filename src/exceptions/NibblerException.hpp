/**
 * @file NibblerException.hpp
 * @brief NibblerException class declaration
*/

/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
** File description:
** nibblerException
*/

#ifndef PACMANEXCEPTION_HPP_
#define PACMANEXCEPTION_HPP_

#include <iostream>
#include <string>
#include <exception>

namespace arcade {
    /**
     * @class NibblerException
     * @brief The NibblerException class is responsible for handling exceptions raised in the Nibbler class.
    */
    class NibblerException : public std::exception {
    public:
        /**
         * @brief Constructor of the NibblerException class.
         * @param message The error message to be displayed.
        */
        NibblerException(const std::string &message) : _message(message) {}

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

#endif /* !PACMANEXCEPTION_HPP_ */
