/**
 * @file DLLoader.hpp
 * @brief DLLoader class declaration
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_DLLOADER_HPP
** File description
** DLLoader
*/

#ifndef ARCADE_DLLOADER_HPP
#define ARCADE_DLLOADER_HPP

#include "../graphicals/IDisplayModule.hpp"
#include "../games/IGameModule.hpp"
#include <dlfcn.h>
#include <iostream>
#include <dirent.h>

namespace arcade {
    /**
     * @class DLLoader
     * @brief The DLLoader class is responsible for loading libraries and games.
    */
    class DLLoader {
    public:
        /**
         * @brief The constructor of the DLLoader class.
        */
        DLLoader();

        /**
         * @brief Loads a library from a specified path.
         * @param path The path to the library to load.
         * @return A pointer to the loaded library.
         */
        void *loadLibrary(const std::string& path);

        /**
         * @brief Closes a library.
         * @param handle A pointer to the library to close.
         */
        void closeLibrary(void *handle);

        /**
         * @brief Returns the names of all available graphical libraries in the specified path.
         * @param path The path where the graphical libraries are located.
         * @return A vector of strings containing the names of the graphical libraries.
         */
        std::vector<std::string> getLibraries(const std::string& path);

        /**
         * @brief Returns the names of all available game libraries in the specified path.
         * @param path The path where the game libraries are located.
         * @return A vector of strings containing the names of the game libraries.
         */
        std::vector<std::string> getGames(const std::string& path);

        /**
         * @brief Returns the entry point of a library.
         * @tparam T Type of the entry point function.
         * @param handle A pointer to the library.
         * @return A pointer to the entry point function.
         */
        template <typename T>
        T *getEntryPoint(void *handle) {
            char *error = nullptr;
            T *(*entryPoint)();

            dlerror();
            entryPoint = (T *(*)())dlsym(handle, "entryPoint");

            if ((error = dlerror()) != nullptr)
                throw DLLException(error);
            return entryPoint();
        }

    private:
        std::vector<std::string> _allLibraries;
        std::vector<std::string> _allGames;
    };
}

#endif //ARCADE_DLLOADER_HPP
