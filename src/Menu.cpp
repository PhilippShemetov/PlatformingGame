#include "Menu.h"

Menu::StateMenu Menu::drawMenu(const std::shared_ptr<SDL_Renderer>& _gameRenderer) {
    Menu::StateMenu menuState = RUNNING;
    while (menuState == RUNNING) {
        SDL_SetRenderDrawColor(_gameRenderer.get(), 96, 128, 255, 255);
        SDL_RenderClear(_gameRenderer.get());
        SDL_RenderPresent(_gameRenderer.get());
        SDL_Delay(16);
    
    }
    

    return Menu::RUNNING;
}

Menu::StateMenu Menu::handlerEvent()
{
    return Menu::RUNNING;
}
