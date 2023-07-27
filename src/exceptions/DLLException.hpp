/**
 * @file DLLException.hpp
 * @brief DLLException class declaration
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_DLLEXCEPTION_HPP
** File description
** DLLException
*/

#ifndef ARCADE_DLLEXCEPTION_HPP
#define ARCADE_DLLEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

namespace arcade {
    /**
    * @class DLLException
    * @brief The DLLException class is responsible for handling exceptions raised in the DLLoader class.
    */
    class DLLException {
    public:
        /**
        * @brief Constructor of the DLLException class.
        * @param message The error message to be displayed.
        */
        DLLException(const std::string &message) : _message(message) {}

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

#endif //ARCADE_DLLEXCEPTION_HPP