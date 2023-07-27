/*
** EPITECH PROJECT, 2023
** ARCADE_SDLMODULE_CPP
** File description
** SDLModule
*/

#include "SDLModule.hpp"

namespace arcade {
    SDLModule::SDLModule() {
        if (SDL_Init(SDL_INIT_VIDEO) == -1) {
            throw SDLException("SDL_Init: " + std::string(SDL_GetError()));
        }
        if (TTF_Init() == -1) {
            throw SDLException("TTF_Init: " + std::string(TTF_GetError()));
        }

        _window = SDL_CreateWindow("SDL - Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (!_window) {
            throw SDLException("SDL_CreateWindow: " + std::string(SDL_GetError()));
        }
        SDL_ShowCursor(SDL_DISABLE);

        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        if (!_renderer) {
            throw SDLException("SDL_CreateRenderer: " + std::string(SDL_GetError()));
        }

        _font = TTF_OpenFont("src/graphicals/assets/roboto.ttf", 20);
        if (!_font) {
            throw SDLException("TTF_OpenFont: " + std::string(TTF_GetError()));
        }

        _title = TTF_OpenFont("src/graphicals/assets/roboto.ttf", 100);

        _imgSurface = IMG_Load("src/graphicals/assets/menu/background.png");
        if (!_imgSurface) {
            throw SDLException("IMG_Load: " + std::string(IMG_GetError()));
        }
        _imgTexture = SDL_CreateTextureFromSurface(_renderer, _imgSurface);
        if (!_imgTexture) {
            throw SDLException("SDL_CreateTextureFromSurface: " + std::string(SDL_GetError()));
        }
    }

    SDLModule::~SDLModule() {
        SDL_Quit();
    }

    void SDLModule::displayWindow() {
        SDL_RenderPresent(_renderer);
    }

    void SDLModule::updateWindow() {
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
        SDL_RenderClear(_renderer);
    }

    void SDLModule::destroyWindow() {
        SDL_DestroyTexture(_textTexture);
        SDL_DestroyTexture(_imgTexture);

        SDL_FreeSurface(_textSurface);
        SDL_FreeSurface(_imgSurface);

        TTF_CloseFont(_font);
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);

        TTF_Quit();
        SDL_Quit();
    }

    void SDLModule::drawText()
    {
        for (auto it = _text_list.begin(); it != std::prev(_text_list.end()); ++it) {
            SDL_RenderCopy(_renderer, it->first, NULL, &it->second);
        }
    }

    void SDLModule::loadSimpleText(std::string text, int x, int y)
    {
    
        SDL_Color textColor = { 255, 255, 255, 255 };
        SDL_Surface* textSurface = TTF_RenderText_Blended(_font, text.c_str(), textColor);

        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
        SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};

        SDL_RenderCopy(_renderer, textTexture, NULL, &textRect);
    }

    void SDLModule::loadTitle(std::string text, int x, int y)
    {
    
        SDL_Color textColor = { 255, 255, 255, 255 };
        SDL_Surface* textSurface = TTF_RenderText_Blended(_title, text.c_str(), textColor);

        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
        SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};

        SDL_RenderCopy(_renderer, textTexture, NULL, &textRect);
    }

    void SDLModule::textLib(const std::string &text, std::pair<std::size_t, std::size_t> pos) {
        SDL_Color textColor = { 255, 255, 255, 255 };
        _textSurface = TTF_RenderText_Blended(_font, text.c_str(), textColor);

        _textTexture = SDL_CreateTextureFromSurface(_renderer, _textSurface);
        _textRect = {(int)pos.first, (int)pos.second, _textSurface->w, _textSurface->h};

        std::pair<SDL_Texture *, SDL_Rect> text_rect;
        text_rect.first = _textTexture;
        text_rect.second = _textRect;

        _text_list.push_back(text_rect);
    }

    void SDLModule::imageLib(const std::string &path, std::pair<std::size_t, std::size_t> pos)
    {
        if (!_imgTexture) {
            throw SDLException("SDL_CreateTextureFromSurface: " + std::string(SDL_GetError()));
        }

        _imgRect = {(int)pos.first, (int)pos.second, _imgSurface->w, _imgSurface->h};

        SDL_RenderCopy(_renderer, _imgTexture, NULL, &_imgRect);
    }
    
    void SDLModule::drawPlayer(int x, int y, int width, int height)
    {
        SDL_Rect rect = {x, y, width, height};
        SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
        // Fill a square at (x=100, y=100) with width=50 and height=50        SDL_Rect rect = {x, y, width, height  pd
        SDL_RenderFillRect(_renderer, &rect);
    }

    void SDLModule::drawBox(int x, int y, int width, int height)
    {
        SDL_Rect rect = {x, y, width, height};
        SDL_Color white = { 255, 255, 255, 255 };
        SDL_SetRenderDrawColor(_renderer, white.r, white.g, white.b, white.a);
        SDL_RenderFillRect(_renderer, &rect);
        SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
    }

    void SDLModule::drawWall(int x, int y, int width, int height)
    {
        SDL_Rect rect = {x, y, width, height};
        SDL_Color white = { 255, 255, 255, 255 };
        SDL_SetRenderDrawColor(_renderer, white.r, white.g, white.b, white.a);
        SDL_RenderFillRect(_renderer, &rect);
    }

    void SDLModule::drawEnemy(int x, int y, int width, int height)
    {
        SDL_Rect rect = {x, y, width, height};
        SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
        // Fill a square at (x=100, y=100) with width=50 and height=50        SDL_Rect rect = {x, y, width, height  pd
        SDL_RenderFillRect(_renderer, &rect);
    }

    void SDLModule::drawScore(int score) {
        SDL_Surface* scoreSurface = TTF_RenderText_Solid(_font, std::to_string(score).c_str(), 
        SDL_Color{ 255, 255, 255, 255 });
        SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(_renderer, scoreSurface);
        SDL_Rect scoreRect = _text_list.back().second;
        SDL_RenderCopy(_renderer, scoreTexture, NULL, &scoreRect);
        SDL_FreeSurface(scoreSurface);
        SDL_DestroyTexture(scoreTexture);
    }

    void SDLModule::setMapShape(std::list<std::pair<int, int>> pos_player, std::list<std::pair<int, int>> pos_enemies, 
        std::list<std::pair<int, int>> pos_walls)
    {

        int Size = 32;

        for (auto wall : pos_walls)
            drawWall((wall.first + 21) * Size, (wall.second + 8) * Size, Size, Size);

        for (auto enemy : pos_enemies)
            drawEnemy((enemy.first + 21) * Size, (enemy.second + 8) * Size, Size, Size);

        for (auto body : pos_player)
            drawPlayer((body.first + 21) * Size, (body.second + 8) * Size, Size, Size);
    }

    std::string SDLModule::getLibName() {
        return std::string("SDL2");
    }

    std::string SDLModule::getPath() {
        return std::string("lib/arcade_sdl2.so");
    }

    std::string SDLModule::getPlayerName() {
        return _playerName;
    }

    void SDLModule::setEditName(bool editName) {
        _editName = editName;
    }

    bool SDLModule::getEditName() {
        return _editName;
    }

    std::unordered_map<Keys, bool> SDLModule::getInputs() {
        for (auto &key : _keys) {
            key.second = false;
        }
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (_editName) {
                SDL_StartTextInput();
                if (event.type == SDL_TEXTINPUT && event.text.text[0] < 128) {
                    _playerName += static_cast<char>(event.text.text[0]);
                }
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                    _keys[Keys::ESCAPE] = true;
                    return _keys;
                }
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE) {
                    if (!_playerName.empty()) {
                        _playerName.pop_back();
                    }
                }
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                    _editName = false;
                    _keys[Keys::ENTER] = true;
                    return _keys;
                }
//                if (SDL_GetTicks() - _cursorTimer >= 500) {
//                    _showCursor = false;
//                    _cursorTimer = SDL_GetTicks();
//                }
                return static_cast<std::unordered_map<Keys, bool>>(event.text.text[0]);
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                _keys[Keys::ESCAPE] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F2) {
                _keys[Keys::F2] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F3) {
                _keys[Keys::F3] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F4) {
                _keys[Keys::F4] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F5) {
                _keys[Keys::F5] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F6) {
                _keys[Keys::F6] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                _editName = false;
                _keys[Keys::ENTER] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP) {
                _keys[Keys::UP] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN) {
                _keys[Keys::DOWN] = true;
                return _keys;
            }

            //player mvt
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z) {
                _keys[Keys::Z] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) {
                _keys[Keys::Q] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s) {
                _keys[Keys::S] = true;
                return _keys;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d) {
                _keys[Keys::D] = true;
                return _keys;
            }


        }
        return _keys;
    }
}

extern "C" arcade::IDisplayModule *entryPoint() {
    return new arcade::SDLModule();
}
