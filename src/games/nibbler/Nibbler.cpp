/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

namespace arcade {
    Nibbler::Nibbler() {
        _nibblerDir = 1;
        _nibblerSize = 0;
        _isOver = false;
        _isWin = false;
        _score = 0;
        _elapsedTime = 0;
        _elapsedGameTime = 0;
        _timeValue = 990;
        _level = 1;
        _mapLevel = 1;
        srand(time(nullptr));
    }

    Nibbler::~Nibbler() {

    }

    int Nibbler::getTimer() {
        return _timeValue;
    }

    int Nibbler::getScore()  {
        return _score;
    }

    std::list<std::pair<int, int>> Nibbler::getPlayerPosition() {
        return _nibblerBody;
    }

    void Nibbler::setPlayerDir(int update) {
        if ((_nibblerDir == 0 && update == 2) || (_nibblerDir == 2 && update == 0) ||
            (_nibblerDir == 1 && update == 3) || (_nibblerDir == 3 && update == 1)) {
            return;
        }
        _nibblerDir = update;
    }

    int Nibbler::getPlayerDir() {
        return _nibblerDir;
    }

    int Nibbler::getPlayerSize() {
        return _nibblerSize;
    }

    std::list<std::pair<int, int>> Nibbler::getEnemyPosition() {
        return _mob.posList;
    }

    std::list<std::pair<int, int>> Nibbler::getWallsPosition() {
        return _walls.posList;
    }

    void Nibbler::setMapPosition() {
        unsigned short int x = 0;
        unsigned short int y = 0;
        _mobCount = 0;
        _mob.posList.clear();
        _walls.posList.clear();
        _nibblerBody.clear();
        _nibblerSize = 4;

        for (char c : _currentMap) {
            if (c == 'O') {
                _mobCount += 1;
                _mob.pos.first = x;
                _mob.pos.second = y;
                _mob.posList.push_back(_mob.pos);
            } else if (c == '#') {
                _walls.pos.first = x;
                _walls.pos.second = y;
                _walls.posList.push_back(_walls.pos);
            } else if (c == 'P') {
                _player.pos.first = x;
                _player.pos.second = y;
            } else if (c == '\n') {
                y++;
                x = -1;
            }
            x++;
        }
    }

    void Nibbler::setMap() {
        std::list<std::string> path = {
            "src/games/maps/nibbler_maps/map1.txt",
            "src/games/maps/nibbler_maps/map2.txt",
            "src/games/maps/nibbler_maps/map3.txt",
            "src/games/maps/nibbler_maps/map4.txt",
        };

        std::ifstream file;
        std::string map;

        for (auto txt : path) {
            file.open(txt);
            if (!file.is_open()) {
                throw NibblerException("map not found");
            }
            map = std::string((std::istreambuf_iterator<char>(file)), 
                (std::istreambuf_iterator<char>()));
            _maps.push_back(map);
            file.close();
        }
        _currentMap = _maps.at(0);

    }

    void Nibbler::updateMap() {
        _nibblerDir = 1;
        _nibblerSize = 2;
        _score = 0;
        _elapsedTime = 0;
        _elapsedGameTime = 0;
        _timeValue = 990;
        _mobCount = 0;
        _mob.pos.first = 0;
        _mob.pos.second = 0;
        _walls.pos.first = 0;
        _walls.pos.second = 0;
        _player.pos.first = 0;
        _player.pos.second = 0;
        if (_level == 2) _currentMap = _maps.at(1);
        if (_level == 3) _currentMap = _maps.at(2);
        if (_level == 4) _currentMap = _maps.at(3);
        setMapPosition();
    }

    void Nibbler::updateEntities() {
        int x = _player.pos.first;
        int y = _player.pos.second;

        bool upClear = true;
        bool downClear = true;
        bool leftClear = true;
        bool rightClear = true;
    
        for (auto& wall : _walls.posList) {
            if (x == wall.first && y - 1 == wall.second) upClear = false;
            if (x == wall.first && y + 1 == wall.second) downClear = false;
            if (x - 1 == wall.first && y == wall.second) leftClear = false;
            if (x + 1 == wall.first && y == wall.second) rightClear = false;
        }
        for (auto& body : _nibblerBody) {
            if (x == body.first && y - 1 == body.second) upClear = false;
            if (x == body.first && y + 1 == body.second) downClear = false;
            if (x - 1 == body.first && y == body.second) leftClear = false;
            if (x + 1 == body.first && y == body.second) rightClear = false;
        }

        if (upClear && (downClear + leftClear + rightClear) == 0) _nibblerDir = 0;
        if (rightClear && (upClear + downClear + leftClear) == 0) _nibblerDir = 1;
        if (downClear && (upClear + leftClear + rightClear) == 0) _nibblerDir = 2;
        if (leftClear && (upClear + downClear + rightClear) == 0) _nibblerDir = 3;

        if (_nibblerDir == 0) y -= 1;
        if (_nibblerDir == 1) x += 1;
        if (_nibblerDir == 2) y += 1;
        if (_nibblerDir == 3) x -= 1;

        for (auto& wall : _walls.posList)
            if (x == wall.first && y == wall.second) return;
        _nibblerBody.insert(_nibblerBody.begin(), { x, y });

        for (auto nibbler = std::next(std::begin(_nibblerBody)); nibbler != std::end(_nibblerBody); ++nibbler) {
            if (x == nibbler->first && y == nibbler->second) {
                _isOver = true;
                return;
            }
        }

        if (_nibblerBody.size() > (std::size_t)_nibblerSize)
            _nibblerBody.pop_back();

        for (auto it = _mob.posList.begin(); it != _mob.posList.end(); ++it) {
            if (it->first == _player.pos.first && it->second == _player.pos.second) {
                _score += 10;
                _nibblerSize++;
                _mob.posList.erase(it);
                break;
            }
        }
        if (_currentMap == _maps.at(3) && _mob.posList.empty())
            _isWin = true;
        if (_mob.posList.empty())
            _level += 1;
        _player.pos = _nibblerBody.front();
    }

    void Nibbler::gameUpdate() {
        _elapsedTime = _timer.getElapsedTime();
        _elapsedGameTime = _gameTimer.getElapsedTime();

        if (_elapsedTime > 200.0) {
            updateEntities();
            _timer.restart();
        }
        if (_elapsedGameTime >= 1000.0) {
            if (_timeValue >= 0)
                _timeValue -= 10;
            else
                _timeValue = 0;
            if (_timeValue == 0)
                _isOver = true;
            _gameTimer.restart();
        }

        if (_mapLevel == 1 && _level == 2) {
            updateMap();
            _mapLevel = 2;
        }
        if (_mapLevel == 2 && _level == 3) {
            updateMap();
            _mapLevel = 3;
        }
        if (_mapLevel == 3 && _level == 4) {
            updateMap();
            _mapLevel = 4;
        }
    }

    std::string Nibbler::getMap() {
        return _currentMap;
    }

    std::pair<bool, bool> Nibbler::getGameState() {
        return std::make_pair(_isOver, _isWin);
    }

    void Nibbler::setPlayerPosition() {
        unsigned short int x = 0;
        unsigned short int y = 0;
        _score = 0;
        _timeValue = 990;
        _nibblerBody.clear();
        _nibblerSize = 4;

        for (char c : _currentMap) {
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

    void Nibbler::setGameState(bool isOver, bool isWin) {
        _isOver = isOver;
        _isWin = isWin;
    }

    std::string Nibbler::getName() {
        return std::string("NIBBLER");
    }

    std::string Nibbler::getPath() {
        return std::string("lib/arcade_nibbler.so");
    }
}

extern "C" arcade::IGameModule *entryPoint() {
    return new arcade::Nibbler();
}