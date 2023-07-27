/**
 * @file IGameModule.hpp
 * @brief IGameModule class declaration
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_IGAMEMODULE_HPP
** File description
** IGameModule
*/

#ifndef ARCADE_IGAMEMODULE_HPP
#define ARCADE_IGAMEMODULE_HPP

#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "../utils/Timer.hpp"

namespace arcade {
    /**
     * @class IGameModule
     * @brief The IGameModule class is responsible for handling the game modules.
     */
    class IGameModule {
        public:
        /**
         * @brief Destructor of the IGameModule class.
         */
        virtual ~IGameModule() = default;

        /**
         * @brief Returns the score of the game.
         * @return int The score of the game.
         */
        virtual int getScore() = 0;

        /**
         * @brief Set the map of the game.
         */
        virtual void setMap() = 0;

        /**
         * @brief Returns the map of the game.
         * @return std::string The map of the game.
         */
        virtual std::string getMap() = 0;

        /**
         * @brief Returns the state of the game.
         * @return bool The state of the game.
         */
        virtual std::pair<bool, bool> getGameState() = 0;

        /**
         * @brief Set the state of the game.
         * @param isOver The state of the game.
         * @param isWin The state of the game.
         */
        virtual void setGameState(bool isOver, bool isWin) = 0;

        /**
         * @brief Set the player position of the game.
         */
        virtual void setPlayerPosition() = 0;

        /**
         * @brief Returns the timer of the game.
         * @return int The timer of the game.
         */
        virtual int getTimer() = 0;

        /**
         * @brief Set the map position of the game.
         */
        virtual void setMapPosition() = 0;

        /**
         * @brief Returns the player position of the game.
         * @return std::list<std::pair<int, int>> The player position of the game.
         */
        virtual std::list<std::pair<int, int>> getPlayerPosition() = 0;

        /**
         * @brief Returns the enemy position of the game.
         * @return std::list<std::pair<int, int>> The enemy position of the game.
         */
        virtual std::list<std::pair<int, int>> getEnemyPosition() = 0;

        /**
         * @brief Returns the walls position of the game.
         * @return std::list<std::pair<int, int>> The walls position of the game.
         */
        virtual std::list<std::pair<int, int>> getWallsPosition() = 0;

        /**
         * @brief Returns the name of the game.
         * @return std::string The name of the game.
         */
        virtual std::string getName() = 0;

        /**
         * @brief Returns the path of the game.
         * @return std::string The path of the game.
         */
        virtual std::string getPath() = 0;

        /**
         * @brief Set the player direction.
         */
        virtual void setPlayerDir(int update) = 0;

        /**
         * @brief Returns the player direction.
         * @return int The player direction.
         */
        virtual int getPlayerDir() = 0;

        /**
         * @brief Returns the player size.
         * @return int The player size.
         */
        virtual int getPlayerSize() = 0;

        /**
         * @brief Update the game.
         */
        virtual void gameUpdate() = 0;

        /**
         * @brief Update the entities of the game.
         */
        virtual void updateEntities() = 0;
    };

} // arcade

#endif //ARCADE_IGAMEMODULE_HPP