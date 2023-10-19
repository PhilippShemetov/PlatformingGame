#include <iostream>
#include <SDL2/SDL.h>

class Menu {
public:
    enum StateMenu {EXIT,PLAY,RUNNING};
    StateMenu drawMenu(const std::shared_ptr<SDL_Renderer>&);
private:
    StateMenu handlerEvent();

};