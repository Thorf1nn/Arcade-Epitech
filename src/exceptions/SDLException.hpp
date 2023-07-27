/**
 * @file SDLException.hpp
 * @brief SDLException class declaration
 */

/*
** EPITECH PROJECT, 2023
** ARCADE_SDLEXCEPTION_HPP
** File description
** SDLException
*/

#ifndef ARCADE_SDLEXCEPTION_HPP
#define ARCADE_SDLEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

namespace arcade {
    /**
     * @class SDLException
     * @brief The SDLException class is responsible for handling exceptions raised in the SDL class.
     */
    class SDLException {
    public:
        /**
         * @brief Constructor of the SDLException class.
         * @param message The error message to be displayed.
         */
        SDLException(const std::string &message) : _message(message) {}

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

#endif //ARCADE_SDLEXCEPTION_HPP