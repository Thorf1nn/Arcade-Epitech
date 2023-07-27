# 🕹️ Arcade

Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of player scores. To be able to deal with the elements of your gaming plateform at run-time, your graphics libraries and your games must be implemented as dynamic libraries, loaded at runtime. Each GUI available for the program must be used as a shared library that will be loaded and used dynamically by the main program.

## 👥 Authors

- [thibault.bernuz@epitech.eu](https://github.com/Haaycee)
- [hugo.eschlimann@epitech.eu](https://github.com/HugoEschlimann)
- [luca.orelli@epitech.eu](https://github.com/Thorf1nn)


## 🎨 Graphics Libraries

- [nCurses](https://invisible-island.net/ncurses/ncurses.html) (arcade_ncurses.so)
- [SDL2](https://wiki.libsdl.org/SDL2/FrontPage) (arcade_sdl2.so)
- [SFML](https://www.sfml-dev.org/documentation/2.5.1/) (arcade_sfml.so)


## 🎮 Games Libraries

- [Snake](https://en.wikipedia.org/wiki/Snake_(video_game_genre)) (arcade_snake.so)
- [Nibbler](https://en.wikipedia.org/wiki/Nibbler_(video_game)) (arcade_nibbler.so)

## 📖 Usage

- To add a graphic library, you will find in the `src/graphicals/` folder, an `IDisplayModule.hpp` interface in which you will find the methods to implement in your class.
  Then create a folder with the name of your library in the `src/graphicals/` folder and add your class to this folder. You can now implement your class and add your graphic library.


- To add a game library, you will find in the `src/games/` folder, an `IGameModule.hpp` interface in which you will find the methods to implement in your class.
  Then create a folder with the name of your library in the `src/games/` folder and add your class to this folder. You can now implement your class and add your game library.

  
## 🔗 Interface Sharing

The group with whom the graphical interfaces and game libraries have been shared is the following:

- [armand.faux@epitech.eu](https://github.com/armandfaux)
- [maceo.gerbaud@epitech.eu](https://github.com/MaceoGrd)
- [yoann1.godard@epitech.eu](https://github.com/Yoyotaa)
