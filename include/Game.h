#ifndef HEADER_H_GAME
#define HEADER_H_GAME

#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include "TypeAliases.h"

struct MouseCord {
    int x;
    int y;
};

class Game {
private:
    enum StateGame{Stopped, Uninitialized, Paused, Running, Exit};
    static StateGame gameState;
    static SDLWindowSptr gameWindow;
    static SDLRendererSptr gameRendrerer;
    static void ShowMenu();
public:
    void Init(int width = 640, int height = 360);
    void GameLoop();
    
};

#endif