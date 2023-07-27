/**
 * @file NcursesModule.hpp
 * @brief Ncurses graphical library
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_NCURSESMODULE_HPP
** File description
** NcursesModule
*/

#ifndef ARCADE_NCURSESMODULE_HPP
#define ARCADE_NCURSESMODULE_HPP

#include <ncurses.h>
#include "../IDisplayModule.hpp"
#include <string.h>
#include <cstring>
#include <time.h> // Inclure pour la fonction clock(
#include "../../exceptions/NcursesException.hpp"

namespace arcade {
    /**
     * @class NcursesModule
     * @brief The NcursesModule class is responsible for handling the Ncurses graphical library.
     */
    class NcursesModule : public IDisplayModule {
    public:
        /**
         * @brief Constructor of the NcursesModule class.
         */
        NcursesModule();

        /**
         * @brief Destructor of the NcursesModule class.
         */
        ~NcursesModule();

        void displayWindow() override;
        void updateWindow() override;
        void destroyWindow() override;

        void textLib(const std::string& text, std::pair<std::size_t, std::size_t> pos) override;
        void drawText() override;

        void imageLib(const std::string &path, std::pair<std::size_t, std::size_t> pos) override;

        std::string getLibName() override;
        std::string getPath() override;
        std::string getPlayerName() override;
        void setEditName(bool editName) override;
        bool getEditName() override;

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
        std::unordered_map<Keys, bool> _keys;
        int _windowSizeX;
        int _windowSizeY;
        std::string _playerName;
        bool _editName;

        WINDOW* _inner_window;

        std::list<std::pair<std::pair<size_t, size_t>, std::string>> _textInfo;
    };
}

extern "C" arcade::IDisplayModule *entryPoint();

#endif //ARCADE_NCURSESMODULE_HPP