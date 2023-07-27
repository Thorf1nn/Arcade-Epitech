/**
 * @file Core.cpp
 * @brief Core class implementation
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_CORE_CPP
** File description
** Core
*/

#include <list>
#include "Core.hpp"
#include <ncurses.h>
#include <regex>

namespace arcade {
    Core::Core(const std::string& filename) {
        DLLoader loader;

        _filename = filename;
        _isRunning = true;
        _isMenu = true;
        _libraries = loader.getLibraries("lib/");
        _games = loader.getGames("lib/");
        _currentPathGame = _games.at(0);
        _selectedGame = 0;
        _gameIndex = 0;
        _editMode = true;
        _saveHighscores = false;
    }

    void Core::loadText()
    {
        _currentLib->imageLib("src/graphicals/assets/menu/background.png", std::make_pair(0, 0));
        _currentLib->textLib("Available Games:", std::make_pair(30, 300));

        std::vector<std::string> tmpGames = _games;
        std::regex regex(R"(^.*_([^_]+)\.so$)");
        std::smatch match;
        std::size_t y = 330;

        for (auto& game : _games) {
            std::regex_search(game, match, regex);
            std::string gameName = match[1].str();
            std::transform(gameName.begin(), gameName.end(), gameName.begin(), [] (unsigned char c) { return std::toupper(c); });
            if (_currentGame->getName() == gameName)
                _currentLib->textLib("-> " + gameName, std::make_pair(50, y));
            else
                _currentLib->textLib(gameName, std::make_pair(50, y));
            y += 30;
        }

        _currentLib->textLib("Graphics Engines:", std::make_pair(30, 500));
        y = 530;
        for (auto& lib : _libraries) {
            std::regex_search(lib, match, regex);
            std::string libName = match[1].str();
            std::transform(libName.begin(), libName.end(), libName.begin(), [] (unsigned char c) { return std::toupper(c); });
            if (_currentLib->getLibName() == libName)
                _currentLib->textLib("-> " + libName, std::make_pair(50, y));
            else
                _currentLib->textLib(libName, std::make_pair(50, y));
            y += 30;
        }

        _currentLib->textLib("Control:", std::make_pair(30, 640));
        _currentLib->textLib("[F2] - Exit", std::make_pair(50, 670));
        _currentLib->textLib("[F3] - Precedent Window", std::make_pair(50, 700));
        _currentLib->textLib("[F4] - Next Window", std::make_pair(50, 730));
        _currentLib->textLib("[F5] - Precedent Game (in game only)", std::make_pair(50, 760));
        _currentLib->textLib("[F6] - Next Game (in game only)", std::make_pair(50, 790));
        _currentLib->textLib("[R] - Restart", std::make_pair(50, 820));
        _currentLib->textLib("[ENTER] - Start Game", std::make_pair(50, 880));
        _currentLib->textLib("[Z, Q, S, D] - Top, Left, Down, Right", std::make_pair(50, 850));
        _currentLib->textLib("[ESC] - Back to menu", std::make_pair(50, 910));
        _currentLib->textLib(std::to_string(_currentGame->getScore()), std::make_pair(1000, 1000));

        _currentLib->displayWindow();
    }

    void Core::launch() {
        _handleLib = _loaderLib->loadLibrary(_filename);
        _currentLib = _loaderLib->getEntryPoint<IDisplayModule>(_handleLib);

        _handleGame = _loaderGame->loadLibrary(_currentPathGame);
        _currentGame = _loaderGame->getEntryPoint<IGameModule>(_handleGame);

        _currentLib->setEditName(true);

        loadText();

        _currentGame->setMap();
        _currentGame->setMapPosition();

        while(_isRunning) {
            handleGlobalEvents();
            _currentLib->updateWindow();
            arcade();
        }
        _currentLib->destroyWindow();
        _loaderLib->closeLibrary(_handleLib);
        _loaderGame->closeLibrary(_handleGame);
    }

    void Core::handleGlobalEvents() {
        std::unordered_map<Keys, bool> inputs = _currentLib->getInputs();

        if (inputs[Keys::F2]) _isRunning = false;
        if (inputs[Keys::F3]) changeLibrary("previous");
        if (inputs[Keys::F4]) changeLibrary("next");
        if (inputs[Keys::F5]) changeGame("previous");
        if (inputs[Keys::F6]) changeGame("next");
        if (inputs[Keys::ENTER]) {
            _currentGame->setGameState(false, false);
            _currentGame->setPlayerPosition();
            _currentLib->setEditName(false);
            _editMode = false;
            _isMenu = false;
        }
        if (inputs[Keys::Z]) _currentGame->setPlayerDir(0);
        if (inputs[Keys::D]) _currentGame->setPlayerDir(1);
        if (inputs[Keys::S]) _currentGame->setPlayerDir(2);
        if (inputs[Keys::Q]) _currentGame->setPlayerDir(3);
    }

    void Core::changeLibrary(const std::string& direction) {
        std::size_t currentLibIndex = getCurrentIndex(_libraries, _currentLib);
        std::string futureLib;

        _currentLib->destroyWindow();
        _loaderLib->closeLibrary(_handleLib);

        if (direction == "previous") {
            if (currentLibIndex == 0)
                futureLib = _libraries[_libraries.size() - 1];
            else
                futureLib = _libraries[currentLibIndex - 1];
        } else {
            if (currentLibIndex == _libraries.size() - 1)
                futureLib = _libraries[0];
            else
                futureLib = _libraries[currentLibIndex + 1];
        }
        _handleLib = _loaderLib->loadLibrary(futureLib);
        _currentLib = _loaderLib->getEntryPoint<IDisplayModule>(_handleLib);
        _currentLib->setEditName(false);
        loadText();
    }

    void Core::changeGame(const std::string& direction) {
        std::size_t currentGameIndex = getCurrentIndex(_games, _currentGame);
        std::string futureGame;

        _loaderGame->closeLibrary(_handleGame);

        if (direction == "previous") {
            if (0 == currentGameIndex)
                futureGame = _games[_games.size() - 1];
            else
                futureGame = _games[currentGameIndex - 1];
        } else {
            if (currentGameIndex == _games.size() - 1)
                futureGame = _games[0];
            else
                futureGame = _games[currentGameIndex + 1];
        }
        _handleGame = _loaderGame->loadLibrary(futureGame);
        _currentGame = _loaderGame->getEntryPoint<IGameModule>(_handleGame);

        _currentGame->setMap();
        _currentGame->setMapPosition();
    }

    void Core::handleMenuEvents() {
        std::unordered_map<Keys, bool> inputs = _currentLib->getInputs();

        if (inputs[Keys::F2]) _isRunning = false;
        if (inputs[Keys::F3]) changeLibrary("previous");
        if (inputs[Keys::F4]) changeLibrary("next");
        if (inputs[Keys::ENTER]) {
            _currentGame->setGameState(false, false);
            _currentLib->setEditName(false);
            _editMode = false;
            _isMenu = false;
        }
        if (inputs[Keys::UP]) changeGame("previous");
        if (inputs[Keys::DOWN]) changeGame("next");
    }

    void Core::handleArcadeEvents() {
        std::unordered_map<Keys, bool> inputs = _currentLib->getInputs();

        if (inputs[Keys::F2]) _isRunning = false;
        if (inputs[Keys::ESCAPE]) _isMenu = true;
        if (inputs[Keys::F3]) changeLibrary("previous");
        if (inputs[Keys::F4]) changeLibrary("next");
        if (inputs[Keys::F5]) changeGame("previous");
        if (inputs[Keys::F6]) changeGame("next");
        if (inputs[Keys::Z]) _currentGame->setPlayerDir(0);
        if (inputs[Keys::D]) _currentGame->setPlayerDir(1);
        if (inputs[Keys::S]) _currentGame->setPlayerDir(2);
        if (inputs[Keys::Q]) _currentGame->setPlayerDir(3);
    }

    void Core::arcade() {
        handleMenuEvents();
        _currentLib->imageLib("src/graphicals/assets/menu/background.png", std::make_pair(0, 0));
        _currentLib->drawBox(185, 14, 20, 12);
        if (_editMode) {
            _playerName = _currentLib->getPlayerName();
        }
        if (!_playerName.empty()) {
            _currentLib->loadSimpleText(_playerName, 20, 200);
        }

        std::ifstream highscoreFile("highscore.txt");
        std::string line;
        int y = 300;
        _currentLib->loadSimpleText("Highscores:", 1700, 270);
        if (highscoreFile.is_open()) {
            while (std::getline(highscoreFile, line)) {
                _currentLib->loadSimpleText(line, 1700, y);
                y += 30;
            }
            highscoreFile.close();
        }
        _currentLib->drawText();

        if (!_isMenu) {
            handleArcadeEvents();
            _currentLib->setMapShape(
                _currentGame->getPlayerPosition(),
                _currentGame->getEnemyPosition(),
                _currentGame->getWallsPosition()
            );

            _currentLib->drawScore(_currentGame->getScore());

            _currentGame->gameUpdate();

            if (_currentGame->getTimer() > -1)
                _currentLib->loadSimpleText(std::to_string(_currentGame->getTimer()), 200, 500);
        
        }
        if(_currentGame->getGameState().first) {
            _isMenu = true;
            _currentLib->loadTitle("GAME OVER", 650, 500);

            if (!_saveHighscores)
                scoreboard();
        } else if (_currentGame->getGameState().second) {
            _isMenu = true;
            _currentLib->loadTitle("YOU WON", 750, 500);

            if (!_saveHighscores)
                scoreboard();
        }
        _currentLib->displayWindow();
    }

    void Core::scoreboard() {
        _saveHighscores = true;
        std::ifstream ifHighscore("highscore.txt", std::ios::in);

        std::string line;
        std::stringstream ss;
        unsigned short int numberLines = 0;
        if (ifHighscore.is_open()) {
            for (; std::getline(ifHighscore, line); numberLines++) {
                ss.clear();
                ss << line;
                std::string name;
                int score;
                ss >> name >> score;
                _scores.push_back(std::make_pair(name, score));
            }
            ifHighscore.close();
            if (numberLines <= 5) {
                std::ofstream ofHighscore("highscore.txt", std::ios::trunc);
                auto compare = [](const auto &a, const auto &b) {
                    return a.second > b.second;
                };
                std::sort(_scores.begin(), _scores.end(), compare);

                if (!_scores.empty() && _currentGame->getScore() > _scores.back().second) {
                    _scores.pop_back();
                }
                auto insert_pos = std::upper_bound(_scores.begin(),_scores.end(),std::make_pair(_playerName,_currentGame->getScore()),compare);
                if (numberLines <= 5 || (insert_pos != _scores.end() || _scores.empty())) {
                    _scores.insert(insert_pos,std::make_pair(_playerName,_currentGame->getScore()));
                }
                for (auto &[name, score] : _scores) {
                    ofHighscore << name << " " << score << '\n';
                }
                ofHighscore.close();
            }
        } else {
            throw std::runtime_error("enable to open file");
        }
    }
}
