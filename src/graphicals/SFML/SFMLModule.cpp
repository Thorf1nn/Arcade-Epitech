/*
** EPITECH PROJECT, 2023
** ARCADE_SFMLMODULE_CPP
** File description
** SFMLModule
*/

#include "SFMLModule.hpp"

namespace arcade {
    SFMLModule::SFMLModule() {
        _window.create(sf::VideoMode::getDesktopMode(), "Arcade", sf::Style::Fullscreen);
        _window.setFramerateLimit(60);
        _window.setMouseCursorVisible(false);
    }

    SFMLModule::~SFMLModule() {
        _window.close();
    }

    void SFMLModule::updateWindow() {
        _window.clear();
    }

    void SFMLModule::displayWindow() {
        _window.display();
    }

    void SFMLModule::destroyWindow() {
        _window.close();
    }

    void SFMLModule::drawScore(int score) {
        sf::Text textScore;

        textScore.setFont(_font);
        textScore.setString(std::to_string(score));
        textScore.setCharacterSize(20);
        textScore.setFillColor(sf::Color::White);

        textScore.setPosition(_textInfo.back().first.first, _textInfo.back().first.second);
        _window.draw(textScore);
    } 

    void SFMLModule::drawText() {
        std::list<sf::Text> sfTextList;
        sf::Text textSFML;

        for (auto it = _textInfo.begin(); it != std::prev(_textInfo.end()); ++it) {
            textSFML.setFont(_font);
            textSFML.setString(it->second);
            textSFML.setCharacterSize(20);
            textSFML.setFillColor(sf::Color::White);
            textSFML.setPosition(it->first.first, it->first.second);
            sfTextList.push_back(textSFML);
        }
    
        for (auto elem : sfTextList)
            _window.draw(elem);
    }

    void SFMLModule::textLib(const std::string &text, std::pair<std::size_t, std::size_t> pos) {
        _font.loadFromFile("src/graphicals/assets/roboto.ttf");

        std::pair<std::pair<size_t, size_t>, std::string> info;
        info.first = pos;
        info.second = text;

        _textInfo.push_back(info);
    }

    void SFMLModule::imageLib(const std::string &path, std::pair<std::size_t, std::size_t> pos) {
        sf::Texture backgroundTexture;
        backgroundTexture.loadFromFile(path);
        sf::Vector2f windowSize(_window.getSize().x, _window.getSize().y);
        sf::Vector2f imageSize(backgroundTexture.getSize().x, backgroundTexture.getSize().y);
        sf::Sprite backgroundSprite(backgroundTexture);
        backgroundSprite.setScale(windowSize.x / imageSize.x, windowSize.y / imageSize.y);
        backgroundSprite.setPosition(pos.first, pos.second);

        _window.draw(backgroundSprite);
    }

    void SFMLModule::drawEnemy(int x, int y, int width, int height) {
        sf::RectangleShape square(sf::Vector2f((float)width, (float)height));
        
        square.setPosition(sf::Vector2f((float)x, (float)y));
        square.setFillColor(sf::Color::Blue);
        _window.draw(square);
    }

    void SFMLModule::drawBox(int x, int y, int width, int height)
    {
        
    }

    void SFMLModule::drawPlayer(int x, int y, int width, int height) {
        sf::RectangleShape square(sf::Vector2f((float)width, (float)height));
        
        square.setPosition(sf::Vector2f((float)x, (float)y));
        square.setFillColor(sf::Color::Red);
        _window.draw(square);
    }

    void SFMLModule::drawWall(int x, int y, int width, int height) {
        sf::RectangleShape square(sf::Vector2f((float)width, (float)height));
        
        square.setPosition(sf::Vector2f((float)x, (float)y));
        square.setFillColor(sf::Color::White);
        _window.draw(square);
        
    }

    void SFMLModule::setMapShape(std::list<std::pair<int, int>> pos_player, std::list<std::pair<int, int>> pos_enemies, 
        std::list<std::pair<int, int>> pos_walls) {
        
        int size = 32;
        for (auto wall : pos_walls)
            drawWall((wall.first + 21) * size, (wall.second + 8) * size, size, size);

        for (auto enemy : pos_enemies)
            drawEnemy((enemy.first + 21) * size, (enemy.second + 8) * size, size, size);

        for (auto body : pos_player)
            drawPlayer((body.first + 21) * size, (body.second + 8) * size, size, size);
    }

    void SFMLModule::loadSimpleText(std::string text, int x, int y) {
        sf::Text textSFML;

        textSFML.setFont(_font);
        textSFML.setString(text);
        textSFML.setCharacterSize(20);
        textSFML.setFillColor(sf::Color::White);

        textSFML.setPosition(x, y);
        _window.draw(textSFML);
    }

    void SFMLModule::loadTitle(std::string text, int x, int y) {
        sf::Text textSFML;

        textSFML.setFont(_font);
        textSFML.setString(text);
        textSFML.setCharacterSize(100);
        textSFML.setFillColor(sf::Color::White);

        textSFML.setPosition(x, y);
        _window.draw(textSFML);
    }

    std::string SFMLModule::getLibName() {
        return std::string("SFML");
    }

    std::string SFMLModule::getPath() {
        return std::string("lib/arcade_sfml.so");
    }

    std::string SFMLModule::getPlayerName() {
        return _playerName;
    }

    void SFMLModule::setEditName(bool editName) {
        _editName = editName;
    }

    bool SFMLModule::getEditName() {
        return _editName;
    }

    std::unordered_map<Keys, bool> SFMLModule::getInputs() {
        for (auto &key : _keys) {
            key.second = false;
        }
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (_editName) {
                if (event.type == sf::Event::TextEntered && event.text.unicode < 128) {
                    if (event.text.unicode == 8 || event.text.unicode == 127) {
                        if (!_playerName.empty()) {
                            _playerName.pop_back();
                        }
                    } else {
                        _playerName += static_cast<char>(event.text.unicode);
                    }
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                        _editName = false;
                    }
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2) {
                        _keys[Keys::F2] = true;
                        return _keys;
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                _keys[Keys::ESCAPE] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2) {
                _keys[Keys::F2] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F3) {
                _keys[Keys::F3] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4) {
                _keys[Keys::F4] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
                _keys[Keys::F5] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F6) {
                _keys[Keys::F6] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                _editName = false;
                _keys[Keys::ENTER] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                _keys[Keys::UP] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                _keys[Keys::DOWN] = true;
                return _keys;
            }

            //player mvt
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z) {
                _keys[Keys::Z] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
                _keys[Keys::Q] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                _keys[Keys::D] = true;
                return _keys;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                _keys[Keys::S] = true;
                return _keys;
            }
        }
        return _keys;
    }
}

extern "C" arcade::IDisplayModule *entryPoint() {
    return new arcade::SFMLModule();
}