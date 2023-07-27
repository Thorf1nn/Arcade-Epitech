/*
** EPITECH PROJECT, 2023
** ARCADE_NCURSESMODULE_CPP
** File description
** NcursesModule
*/

#include "NcursesModule.hpp"

namespace arcade {
    NcursesModule::NcursesModule() {
        _editName = true;
        initscr();
        keypad(stdscr, TRUE);
        noecho();
        cbreak();
        curs_set(0);
        start_color();
        nodelay(stdscr, TRUE);
        init_pair(1, COLOR_WHITE, init_color(COLOR_BLACK, 0, 0, 0));
        init_pair(2, COLOR_BLUE, init_color(COLOR_BLACK, 0, 0, 0));
        init_pair(3, COLOR_RED, init_color(COLOR_BLACK, 0, 0, 0));
        getmaxyx(stdscr, _windowSizeY, _windowSizeX);
    }

    NcursesModule::~NcursesModule() {
        endwin();
    }

    void NcursesModule::displayWindow() {
        wrefresh(stdscr);
        napms(50);
    }

    void NcursesModule::updateWindow() {
        wclear(stdscr);
    }

    void NcursesModule::destroyWindow() {
        attroff(COLOR_PAIR(1));
        attroff(COLOR_PAIR(2));
        attroff(COLOR_PAIR(3));
    }

    void NcursesModule::drawText() {
        for (auto it = _textInfo.begin(); it != std::prev(_textInfo.end()); ++it) {
            mvprintw((int)(it->first.second / (1080 / _windowSizeY)), it->first.first / (1920 / _windowSizeX), "%s", it->second.c_str());
        }
    }

    void NcursesModule::textLib(const std::string& text, std::pair<std::size_t, std::size_t> pos) {
        std::pair<std::pair<size_t, size_t>, std::string> info;
        info.first = pos;
        info.second = text;

        _textInfo.push_back(info);
    }

    void NcursesModule::imageLib(const std::string &path, std::pair<std::size_t, std::size_t> pos) {

    }

    void NcursesModule::drawPlayer(int x, int y, int width, int height) {
        attron(COLOR_PAIR(3));
        mvaddch(y, x, ' ' | A_REVERSE);
    }

    void NcursesModule::drawEnemy(int x, int y, int width, int height) {
        attron(COLOR_PAIR(2));
        mvaddch(y, x, ' ' | A_REVERSE);
    }

    void NcursesModule::drawWall(int x, int y, int width, int height) {
        attron(COLOR_PAIR(1));
        mvaddch(y, x, ' ' | A_REVERSE);
    }

    void NcursesModule::drawScore(int score) {
        std::pair<std::pair<size_t, size_t>, std::string> elem;

        elem = _textInfo.back();

        elem.second = std::to_string(score);

        mvprintw((int)(elem.first.second / (1080 / _windowSizeY)), elem.first.first / (1920 / _windowSizeX), "%s", elem.second.c_str());
    }

    void NcursesModule::drawBox(int x, int y, int width, int height) {
        _inner_window = newwin(height-2 / (1080 / _windowSizeY), width-2 / (1920 / _windowSizeX), y+1 / (1080 / _windowSizeY), x + 1/ (1920 / _windowSizeX));
        box(_inner_window, 0, 0);
        wrefresh(_inner_window);
    }

    void NcursesModule::loadSimpleText(std::string text, int x, int y) {
        mvprintw((int)(y / (1080 / _windowSizeY)), x / (1920 / _windowSizeX), "%s", text.c_str());
    }

    void NcursesModule::loadTitle(std::string text, int x, int y) {
        mvprintw((int)(y / (1080 / _windowSizeY)), x / (1920 / _windowSizeX), "%s", text.c_str());
    }

    void NcursesModule::setMapShape(std::list<std::pair<int, int>> pos_player, std::list<std::pair<int, int>> pos_enemies, 
        std::list<std::pair<int, int>> pos_walls) {
        int Size = 0;

        for (auto wall : pos_walls)
            drawWall((wall.first + 101), (wall.second + 8), Size, Size);

        for (auto enemy : pos_enemies)
            drawEnemy((enemy.first + 101), (enemy.second + 8), Size, Size);

        for (auto body : pos_player)
            drawPlayer((body.first + 101), (body.second + 8), Size, Size);
    }

    std::string NcursesModule::getLibName() {
        return std::string("NCURSES");
    }

    std::string NcursesModule::getPath() {
        return std::string("lib/arcade_ncurses.so");
    }

    std::string NcursesModule::getPlayerName() {
        return _playerName;
    }

    void NcursesModule::setEditName(bool editName) {
        _editName = editName;
    }

    bool NcursesModule::getEditName() {
        return _editName;
    }

    std::unordered_map<Keys, bool> NcursesModule::getInputs() {
        for (auto &key : _keys) {
            key.second = false;
        }
       int ch = getch();
        if (ch == 27) {
            _keys[Keys::ESCAPE] = true;
            return _keys;
        }
        if (_editName) {
            if (ch == '\n') {
                _editName = false;
            }
            // if ch == A or a
            if (ch == 65 || ch == 97) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 66 || ch == 98) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 67 || ch == 99) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 68 || ch == 100) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 69 || ch == 101) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 70 || ch == 102) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 71 || ch == 103) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 72 || ch == 104) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 73 || ch == 105) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 74 || ch == 106) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 75 || ch == 107) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 76 || ch == 108) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 77 || ch == 109) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 78 || ch == 110) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 79 || ch == 111) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 80 || ch == 112) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 81 || ch == 113) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 82 || ch == 114) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 83 || ch == 115) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 84 || ch == 116) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 85 || ch == 117) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 86 || ch == 118) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 87 || ch == 119) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 88 || ch == 120) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 89 || ch == 121) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == 90 || ch == 122) {
                _playerName += static_cast<char>(ch);
                return _keys;
            }
            if (ch == KEY_BACKSPACE || ch == KEY_DC || ch == 127) {
                if (!_playerName.empty()) {
                    _playerName.pop_back();
                     delch();
                }
            }
            if (ch == KEY_F(2)) {
                _keys[Keys::F2] = true;
                return _keys;
            }
        }
        if (ch == KEY_F(2)) {
            _keys[Keys::F2] = true;
            return _keys;
        }
        if (ch == KEY_F(3)) {
            _keys[Keys::F3] = true;
            return _keys;
        }
        if (ch == KEY_F(4)) {
            _keys[Keys::F4] = true;
            return _keys;
        }
        if (ch == KEY_F(5)) {
            _keys[Keys::F5] = true;
            return _keys;
        }
        if (ch == KEY_F(6)) {
            _keys[Keys::F6] = true;
            return _keys;
        }
        if (ch == 10) {
            _keys[Keys::ENTER] = true;
            return _keys;
        }
        if (ch == KEY_UP) {
            _keys[Keys::UP] = true;
            return _keys;
        }
        if (ch == KEY_DOWN) {
            _keys[Keys::DOWN] = true;
            return _keys;
        }

        //playermvt
        if (ch == 'z') {
            _keys[Keys::Z] = true;
            return _keys;
        }
        if (ch == 'q') {
            _keys[Keys::Q] = true;
            return _keys;
        }
        if (ch == 's') {
            _keys[Keys::S] = true;
            return _keys;
        }
        if (ch == 'd') {
            _keys[Keys::D] = true;
            return _keys;
        }
        return _keys;
    }
}

extern "C" arcade::IDisplayModule *entryPoint() {
    return new arcade::NcursesModule();
}
