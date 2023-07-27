/**
 * @file DLLoader.cpp
 * @brief DLLoader class implementation
*/

/*
** EPITECH PROJECT, 2023
** ARCADE_DLLOADER_CPP
** File description
** DLLoader
*/

#include "DLLoader.hpp"

namespace arcade {
    DLLoader::DLLoader() {
        _allLibraries = {
            "arcade_ncurses.so",
            "arcade_ndk++.so",
            "arcade_aalib.so",
            "arcade_libcaca.so",
            "arcade_allegro5.so",
            "arcade_xlib.so",
            "arcade_gtk.so",
            "arcade_sfml.so",
            "arcade_irrlicht.so",
            "arcade_opengl.so",
            "arcade_vulkan.so",
            "arcade_qt5.so",
            "arcade_sdl2.so"
        };

        _allGames = {
            "arcade_snake.so",
            "arcade_nibbler.so",
            "arcade_nibbler.so",
            "arcade_qix.so",
            "arcade_centipede.so",
            "arcade_solarfox.so"
        };
    }

    void *DLLoader::loadLibrary(const std::string &path) {
        void *handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!handle) {
            throw DLLException("Cannot open library: " + std::string(dlerror()));
        }
        return handle;
    }

    void DLLoader::closeLibrary(void *handle) {
        if (dlclose(handle) != 0)
            throw DLLException(dlerror());
    }

    std::vector<std::string> DLLoader::getLibraries(const std::string &path) {
        DIR *folder = opendir(path.c_str());
        struct dirent *fd;
        std::vector<std::string> libraries;

        while ((fd = readdir(folder)) != NULL) {
            if (fd->d_name[0] == '.')
                continue;
            if (std::find(_allLibraries.begin(), _allLibraries.end(), fd->d_name) != _allLibraries.end()) {
                if (std::find(path.begin(), path.end(), '/') != path.end())
                    libraries.push_back(path + fd->d_name);
                else
                    libraries.push_back(path + "/" + fd->d_name);
            }
        }
        closedir(folder);
        return libraries;   
    }

     std::vector<std::string> DLLoader::getGames(const std::string& path) {
         struct dirent *fd;
         DIR *folder = opendir(path.c_str());
         std::vector<std::string> games;

         while ((fd = readdir(folder)) != NULL) {
             if (fd->d_name[0] == '.')
                 continue;
             if (std::find(_allGames.begin(), _allGames.end(), fd->d_name) != _allGames.end()) {
                 if (std::find(path.begin(), path.end(), '/') != path.end())
                    games.push_back(path + fd->d_name);
                 else
                    games.push_back(path + "/" + fd->d_name);
             }
         }
         closedir(folder);
         return games;
     }
}
