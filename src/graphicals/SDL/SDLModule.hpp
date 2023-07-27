/**
 * @file SDLModule.hpp
 * @brief SDLModule class declaration
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_SDLMODULE_HPP
** File description
** SDLModule
*/

#ifndef ARCADE_SDLMODULE_HPP
#define ARCADE_SDLMODULE_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "../IDisplayModule.hpp"
#include "../../exceptions/SDLException.hpp"

namespace arcade {
    /**
     * @class SDLModule
     * @brief The SDLModule class is responsible for handling the SDL graphical library.
     */
    class SDLModule : public IDisplayModule {
    public:
        /**
         * @brief Constructor of the SDLModule class.
         */
        SDLModule();

        /**
         * @brief Destructor of the SDLModule class.
         */
        ~SDLModule();

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

    
        void drawPlayer(int x, int y, int width, int height) override;
        void drawEnemy(int x, int y, int width, int height) override;
        void drawWall(int x, int y, int width, int height) override;

        void setMapShape(std::list<std::pair<int, int>> pos_player, std::list<std::pair<int, int>> pos_enemies, 
            std::list<std::pair<int, int>> pos_walls) override;

        void drawScore(int score) override;
        void loadTitle(std::string text, int x, int y) override;
        void loadSimpleText(std::string text, int x, int y) override;

        void drawBox(int x, int y, int width, int height) override;
        
    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        std::unordered_map<Keys, bool> _keys;
        TTF_Font* _font;
        TTF_Font* _title;
        std::string _playerName;
        bool _editName;
//        bool _showCursor;
//        Uint32 _cursorTimer;


        SDL_Rect _textRect;
        SDL_Rect _imgRect;

        SDL_Texture* _textTexture;
        SDL_Texture* _imgTexture;

        SDL_Surface* _textSurface;
        SDL_Surface* _imgSurface;

        std::string _text;
        std::list<std::string> _str_text_list;

        std::list<std::pair<SDL_Texture *, SDL_Rect>> _text_list;

    };
}

extern "C" arcade::IDisplayModule *entryPoint();

#endif //ARCADE_SDLMODULE_HPP