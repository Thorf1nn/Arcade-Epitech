/**
 * @file Core.hpp
 * @brief The Core class declaration.
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_CORE_HPP
** File description
** Core
*/

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include "DLLoader.hpp"
#include "../exceptions/SDLException.hpp"
#include "../exceptions/NcursesException.hpp"
#include "../exceptions/SFMLException.hpp"
#include "../utils/Timer.hpp"
#include <unordered_map>
#include <chrono>

namespace arcade {
    /**
     * @class Core
     * @brief The main class of the program,
     * responsible for loading libraries and games,
     * handling events and updating the display.
    */
    class Core {
    public:
        /**
         * @brief The constructor of the Core class.
         * @param filename The name of the file containing the high scores.
        */
        Core(const std::string& filename);
        ~Core() {}

        /**
         * @brief The main loop of the program.
        */
        void launch();
        void handleGlobalEvents();
        void handleMenuEvents();
        void handleArcadeEvents();
        void arcade();
        void arcadeGame();
        void changeLibrary(const std::string& direction);
        void changeGame(const std::string& direction);
        void scoreboard();

    private:
        /**
         * @brief Get the current index of an element in a given array.
         * This function takes an array and an instance and returns the index of the instance in the array.
         * If the instance is not found in the array, it returns the index of the last element in the array.
         * @tparam T Type of the array.
         * @tparam U Type of the instance.
         * @param array Array to search for the instance.
         * @param instance Instance to search for in the array.
         * @return std::size_t Index of the instance in the array or the index of the last element if the instance is not found.
        */
        template <typename T, typename U>
        std::size_t getCurrentIndex(const T& array, const U& instance) {
            std::size_t currentIndex = 0;

            for (auto &elem : array) {
                if (instance->getPath() == elem) {
                    break;
                }
                currentIndex++;
            }
            return currentIndex;
        }

        /**
          * @brief Loads the text to be displayed in the menu.
        */
        void loadText();

        std::string _filename;
        DLLoader *_loaderLib;
        void *_handleLib;
        std::vector<std::string>  _libraries;
        IDisplayModule *_currentLib;

        void *_handleGame;
        DLLoader *_loaderGame;
        IGameModule *_currentGame;
        std::string _currentPathGame;
        std::vector<std::string> _games;
        short _selectedGame;
        short _gameIndex;

        bool _isRunning;
        bool _isMenu;
        bool _editMode;
        bool _saveHighscores;
        bool _name;
        std::string _playerName;
        std::vector<std::pair<std::string, int>> _scores;
    };
} // arcade

#endif //ARCADE_CORE_HPP