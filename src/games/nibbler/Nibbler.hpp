/**
 * @file Nibbler.hpp
 * @brief Nibbler game class declaration
 */

/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-hugo.eschlimann
** File description:
** Nibbler
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../IGameModule.hpp"
#include <iostream>
#include <list>
#include <vector>
#include "../../exceptions/NibblerException.hpp"

namespace arcade {
    /**
     * @class Nibbler
     * @brief The Nibbler class is responsible for handling the Nibbler game.
    */
    class Nibbler : public IGameModule {
        public:
            /**
             * @brief Constructor of the Nibbler class.
            */
            Nibbler();

            /**
             * @brief Destructor of the Nibbler class.
            */
            ~Nibbler();

            int getScore() override;

            int getTimer() override;

            void updateMap();

            void setMap() override;
            std::string getMap() override;
            void setPlayerPosition() override;

            void setMapPosition() override;
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

            struct _Mob { 
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
            _Mob _mob;
            _Walls _walls;

            int _nibblerSize;
            int _nibblerDir;

            int _score;
            unsigned short int _mobCount = 0;
            unsigned short int _fruits = 0;

            bool _isOver;
            bool _isWin;
            Timer _timer;
            Timer _gameTimer;

            double _elapsedTime;
            double _elapsedGameTime;

            int _timeValue;

            int _level;
            int _mapLevel;
            
            std::vector<std::string> _maps;
            std::string _currentMap;
            
            std::list<std::pair<int, int>> _nibblerBody;
    };
}
extern "C" arcade::IGameModule *entryPoint();

#endif /* !PACMAN_HPP_ */
