/**
 * @file Snake.hpp
 * @brief Snake game class declaration
*/

/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../IGameModule.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../../exceptions/SnakeException.hpp"
#include <iterator>
#include <algorithm>

namespace arcade {
    /**
     * @class Snake
     * @brief The Snake class is responsible for handling the Snake game.
    */
    class Snake : public IGameModule {
        public:
            /**
             * @brief Constructor of the Snake class.
            */
            Snake();

            /**
             * @brief Destructor of the Snake class.
            */
            ~Snake();

            int getScore() override;

            void setMap() override;
            std::string getMap() override;

            int getTimer() override;

            void setMapPosition() override;
            void setPlayerPosition() override;

            std::list<std::pair<int, int>> getPlayerPosition() override;
            int getPlayerSize() override;

            std::list<std::pair<int, int>> getEnemyPosition() override;
            std::list<std::pair<int, int>> getWallsPosition() override;

            std::string getName() override;
            std::string getPath() override;

            void setPlayerDir(int update) override;
            int getPlayerDir() override;

            struct _Player {
                std::pair<int, int> pos;
            };

            struct _Apple {
                std::pair<int, int> pos;
                std::list<std::pair<int, int>> posList;
            };

            struct _Walls {
                std::pair<int, int> pos;
                std::list<std::pair<int, int>> posList;
            };

            void gameUpdate() override;

            std::pair<bool, bool> getGameState() override;
            void setGameState(bool isOver, bool isWin) override;

            void updateEntities() override;
            
        private:
            _Player _player;
            _Apple _apple;
            _Walls _walls;

            int _snakeSize;
            int _snakeDir;

            std::string _map;

            int _score;
            bool _isOver;
            bool _isWin;
            // std::vector<std::pair<bool, bool>> _gameState;
            int _mapSize;

            Timer _timer;
            double _elapsedTime;

            std::list<std::pair<int, int>> _snakeBody;
    };
}

extern "C" arcade::IGameModule *entryPoint();

#endif /* !SNAKE_HPP_ */
