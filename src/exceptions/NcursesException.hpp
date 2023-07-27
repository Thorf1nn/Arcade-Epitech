/**
 * @file NcursesException.hpp
 * @brief NcursesException class declaration
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_NCURSESEXCEPTION_HPP
** File description
** NcursesException
*/

#ifndef ARCADE_NCURSESEXCEPTION_HPP
#define ARCADE_NCURSESEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

namespace arcade {
    /**
     * @class NcursesException
     * @brief The NcursesException class is responsible for handling exceptions raised in the Ncurses class.
     */
    class NcursesException {
    public:
        /**
         * @brief Constructor of the NcursesException class.
         * @param message The error message to be displayed.
         */
        NcursesException(const std::string &message) : _message(message) {}

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

#endif //ARCADE_NCURSESEXCEPTION_HPP