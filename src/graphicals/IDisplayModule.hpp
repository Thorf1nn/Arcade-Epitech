/**
 * @file IDisplayModule.hpp
 * @brief IDisplayModule class declaration
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_IDISPLAYMODULE_HPP
** File description
** IDisplayModule
*/

#ifndef ARCADE_IDISPLAYMODULE_HPP
#define ARCADE_IDISPLAYMODULE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <dlfcn.h>
#include <unordered_map>
#include <list>

#include "../exceptions/DLLException.hpp"

namespace arcade {
    /**
     * @enum Keys
     * @brief The Keys enum is responsible for handling the keys of the game.
     */
    enum Keys {
        ESCAPE,
        ENTER,
        UP,
        DOWN,
        Z,
        Q,
        S,
        D,
        SPACE,
        F2,
        F3,
        F4,
        F5,
        F6,
    };

    /**
    * @class IDisplayModule
    * @brief The IDisplayModule class is responsible for handling the display of the game.
    */
    class IDisplayModule {
    public:
        /**
         * @brief Constructor of the IDisplayModule class.
         */
        virtual ~IDisplayModule() = default;

        /**
         * @brief Display the window.
         */
        virtual void displayWindow() = 0;

        /**
         * @brief Update the window.
         */
        virtual void updateWindow() = 0;

        /**
         * @brief Destroy the window.
         */
        virtual void destroyWindow() = 0;

        /**
         * @brief Load the text
         * @param text The text to be displayed.
         * @param pos The position of the text.
         */
        virtual void textLib(const std::string &text, std::pair<std::size_t, std::size_t> pos) = 0;

        /**
         * @brief Draw the text.
         */
        virtual void drawText() = 0;

        /**
         * @brief Load the image.
         * @param path The path of the image.
         * @param pos The position of the image.
         */
        virtual void imageLib(const std::string &path, std::pair<std::size_t, std::size_t> pos) = 0; // create and display the image

        /**
         * @brief Get the name of the library.
         * @return The name of the library.
         */
        virtual std::string getLibName() = 0;

        /**
         * @brief Get the path of the library.
         * @return The path of the library.
         */
        virtual std::string getPath() = 0;

        /**
         * @brief Get the name of the player.
         * @return The name of the player.
         */
        virtual std::string getPlayerName() = 0;

        /**
         * @brief Get the state of the game.
         * @return The state of the game.
         */
        virtual bool getEditName() = 0;

        /**
         * @brief Set the state.
         * @param editName The state.
         */
        virtual void setEditName(bool editName) = 0;

        /**
         * @brief Get the inputs.
         * @return The inputs.
         */
        virtual std::unordered_map<Keys, bool> getInputs() = 0;

        /**
         * @brief Set the map shape.
         * @param pos_player The position of the player.
         * @param pos_enemies The position of the enemies.
         * @param pos_walls The position of the walls.
         */
        virtual void setMapShape(std::list<std::pair<int, int>> pos_player, std::list<std::pair<int, int>> pos_enemies, 
        std::list<std::pair<int, int>> pos_walls) = 0;
        // virtual void setupdateEntities() = 0;

        /**
         * @brief Draw the player.
         * @param x The x position of the player.
         * @param y The y position of the player.
         * @param width The width of the player.
         * @param height The height of the player.
         */
        virtual void drawPlayer(int x, int y, int width, int height) = 0;

        /**
         * @brief Draw the enemy.
         * @param x The x position of the enemy.
         * @param y The y position of the enemy.
         * @param width The width of the enemy.
         * @param height The height of the enemy.
         */
        virtual void drawEnemy(int x, int y, int width, int height) = 0;

        /**
         * @brief Draw the wall.
         * @param x The x position of the wall.
         * @param y The y position of the wall.
         * @param width The width of the wall.
         * @param height The height of the wall.
         */
        virtual void drawWall(int x, int y, int width, int height) = 0;

        /**
         * @brief Draw the box.
         * @param x The x position of the box.
         * @param y The y position of the box.
         * @param width The width of the box.
         * @param height The height of the box.
         */
        virtual void drawBox(int x, int y, int width, int height) = 0;

        /**
         * @brief Draw the score.
         * @param score The score.
         */
        virtual void drawScore(int score) = 0;

        /**
         * @brief Load and display the text in 20 pixels.
         * @param text Text to be displayed.
         * @param x Position x of the text.
         * @param y Position y of the text.
         */
        virtual void loadSimpleText(std::string text, int x, int y) = 0;

        /**
         * @brief Load and display the text in 100 pixels.
         * @param text Text to be displayed.
         * @param x Position x of the text.
         * @param y Position y of the text.
         */
        virtual void loadTitle(std::string text, int x, int y) = 0;
    };
} // arcade

#endif //ARCADE_IDISPLAYMODULE_HPP