/**
 * @file SFMLModule.hpp
 * @brief Header file for the SFMLModule class, which is a concrete implementation of the IDisplayModule interface
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_SFMLMODULE_HPP
** File description
** SFMLModule
*/

#ifndef ARCADE_SFMLMODULE_HPP
#define ARCADE_SFMLMODULE_HPP

#include "../IDisplayModule.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Config.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"

namespace arcade {
    /**
    * @class SFMLModule
    * @brief Concrete implementation of the IDisplayModule interface using the SFML library
    */
    class SFMLModule : public IDisplayModule {
    public:
        /**
        * @brief Default constructor for the SFMLModule class
        */
        SFMLModule();

        /**
         * @brief Default destructor for the SFMLModule class
         */
        ~SFMLModule();

        void displayWindow() override;
        void updateWindow() override;
        void destroyWindow() override;

        void textLib(const std::string& text, std::pair<std::size_t, std::size_t> pos) override;
        void drawText() override;

        void imageLib(const std::string &path, std::pair<std::size_t, std::size_t> pos) override;

        std::string getLibName() override;
        std::string getPath() override;
        std::string getPlayerName() override;
        bool getEditName() override;
        void setEditName(bool editName) override;

        std::unordered_map<Keys, bool> getInputs() override;

        void setMapShape(std::list<std::pair<int, int>> pos_player, std::list<std::pair<int, int>> pos_enemies,
        std::list<std::pair<int, int>> pos_walls) override;

        void drawPlayer(int x, int y, int width, int height) override;
        void drawEnemy(int x, int y, int width, int height) override;
        void drawWall(int x, int y, int width, int height) override;

        void drawScore(int score) override;
        void loadSimpleText(std::string text, int x, int y) override;
        void loadTitle(std::string text, int x, int y) override;

        void drawBox(int x, int y, int width, int height) override;

    private:
        sf::RenderWindow _window;
        std::unordered_map<Keys, bool> _keys;

        sf::Font _font;

        std::list<std::pair<std::pair<size_t, size_t>, std::string>> _textInfo;

        std::list<sf::Text> _sfTextList;

        std::string _playerName;
        bool _editName;
    };
}

extern "C" arcade::IDisplayModule *entryPoint();

#endif //ARCADE_SFMLMODULE_HPP