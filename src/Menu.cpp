#include "Menu.h"

Menu::StateMenu Menu::drawMenu(const std::shared_ptr<SDL_Renderer>& _gameRenderer) {
    Menu::StateMenu menuState = RUNNING;
    while (menuState == RUNNING) {
        prepareMenu(_gameRenderer);
        handlerEvent();
        presentMenu(_gameRenderer);
        SDL_Delay(16);
    }
    

    return Menu::RUNNING;
}

void Menu::prepareMenu(const SDLRendererSptr& _gameRenderer) {
    SDL_SetRenderDrawColor(_gameRenderer.get(), 96, 128, 255, 255);
    createButtons();
    SDL_RenderClear(_gameRenderer.get());
}

void Menu::presentMenu(const SDLRendererSptr& _gameRenderer) {
    SDL_RenderPresent(_gameRenderer.get());
}

void Menu::createButtons() {
    
}

Menu::StateMenu Menu::handlerEvent() {
    SDL_Event event;
    MouseCord mousePos;
    SDL_GetMouseState(&mousePos.x,&mousePos.y);
    SDL_PollEvent(&event);
    std::cout << "Xpos: " << mousePos.x << "Ypos: "  << mousePos.y << std::endl;


    return Menu::RUNNING;
}
