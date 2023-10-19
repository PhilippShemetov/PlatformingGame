#ifndef HEADER_H_MENU
#define HEADER_H_MENU

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TypeAliases.h"
#include "Game.h"

class Menu {
public:
    enum StateMenu {EXIT,PLAY,RUNNING};
    StateMenu drawMenu(const SDLRendererSptr&);
private:
    void prepareMenu(const SDLRendererSptr&);
    void presentMenu(const SDLRendererSptr&);
    void createButtons();
    StateMenu handlerEvent();

};

#endif