/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
** File description:
** Snake
*/

#include "Snake.hpp"

namespace arcade {
    Snake::Snake() {
        _snakeDir = 1;
        _snakeSize = 4;
        _mapSize = 18;
        _isOver = false;
        _isWin = false;
        _elapsedTime = 0;
        _score = 0;
        srand(time(nullptr));
    }

    Snake::~Snake() {

    }

    int Snake::getScore() {
        return _score;
    }

    int Snake::getTimer() {
        return -1;
    }

    void Snake::setMapPosition() {
        int x = 0;
        int y = 0;


        for (auto it = std::begin(_map); it != std::end(_map); it++, x++) {
            if (*it == '#') {
                _walls.pos.first = x;
                _walls.pos.second = y;
                _walls.posList.push_back(_walls.pos);
            } else if (*it == 'P') {
                _player.pos.first = x;
                _player.pos.second = y;
            } else if (*it == '\n') {
                y++;
                x = -1;
            }
        }
        _apple.pos.first = rand()%(_mapSize) + 1;
        _apple.pos.second = rand()%(_mapSize) + 1;
        _apple.posList.push_back(_apple.pos);
    }

    std::list<std::pair<int, int>> Snake::getWallsPosition() {
        return _walls.posList;
    }

    std::list<std::pair<int, int>> Snake::getEnemyPosition() {
        return _apple.posList;
    }

    std::list<std::pair<int, int>> Snake::getPlayerPosition() {
        return _snakeBody;
    }

    void Snake::setPlayerDir(int update) {
        if ((_snakeDir == 0 && update == 2) || (_snakeDir == 2 && update == 0) ||
            (_snakeDir == 1 && update == 3) || (_snakeDir == 3 && update == 1)) {
            return;
        }
        _snakeDir = update;
    }

    int Snake::getPlayerDir() {
        return _snakeDir;
    }

    int Snake::getPlayerSize() {
        return _snakeSize;
    }

    void Snake::setGameState(bool isOver, bool isWin) {
        _isOver = isOver;
        _isWin = isWin;
    }

    std::pair<bool, bool> Snake::getGameState() {
        return std::make_pair(_isOver, _isWin);
    }

    void Snake::updateEntities() {
        int x = _player.pos.first;
        int y = _player.pos.second;

        if (_snakeDir == 0) y -= 1;
        if (_snakeDir == 1) x += 1;
        if (_snakeDir == 2) y += 1;
        if (_snakeDir == 3) x -= 1;

        for (auto& wall : _walls.posList) {
            if (x == wall.first && y == wall.second) {
                _isOver = true;
                return;
            }
        }
        for (auto snake = std::next(std::begin(_snakeBody)); snake != std::end(_snakeBody); ++snake) {
            if (x == snake->first && y == snake->second) {
                _isOver = true;
                return;
            }
        }

        _snakeBody.insert(_snakeBody.begin(), std::make_pair(x, y));

        if (_snakeBody.size() > (std::size_t)_snakeSize)
            _snakeBody.pop_back();

        if (_snakeBody.front().first == _apple.posList.front().first && _snakeBody.front().second == _apple.posList.front().second) {
            _score += 1;
            _snakeSize += 1;
            _apple.posList.front().first = rand()%(_mapSize) + 1;
            _apple.posList.front().second = rand()%(_mapSize) + 1;
        }

        _apple.pos = _apple.posList.front();

        _player.pos = _snakeBody.front();

    }

    void Snake::setPlayerPosition() {
        unsigned short int x = 0;
        unsigned short int y = 0;

        _snakeBody.clear();
        _snakeSize = 4;
        _score = 0;

        for (char c : _map) {
            if (c == 'P') {
                _player.pos.first = x;
                _player.pos.second = y;
            } else if (c == '\n') {
                y++;
                x = -1;
            }
            x++;
        }
    }
    
    void Snake::gameUpdate() {
        _elapsedTime = _timer.getElapsedTime();

        if (_elapsedTime > 200.0) {
            updateEntities();
            _timer.restart();
        }
    }

    void Snake::setMap() {
        std::ifstream file("src/games/maps/snake.txt");

        if (!file.is_open())
            throw SnakeException("Failed to open file: src/games/maps/snake.txt");

        _map = std::string((std::istreambuf_iterator<char>(file)), 
        (std::istreambuf_iterator<char>()));

        file.close();
    }

    std::string Snake::getMap() {
        return _map;
    }

    std::string Snake::getName() {
        return std::string("SNAKE");
    }

    std::string Snake::getPath() {
        return std::string("lib/arcade_snake.so");
    }
}

extern "C" arcade::IGameModule *entryPoint() {
    return new arcade::Snake();
}