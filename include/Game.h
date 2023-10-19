#include <memory>
#include <iostream>
#include <SDL2/SDL.h>

class Game {
private:
    enum StateGame{Stopped, Uninitialized, Paused, Running, Exit};
    static StateGame gameState;
    static std::shared_ptr<SDL_Window> gameWindow;
    static std::shared_ptr<SDL_Renderer> gameRendrerer;
    static void ShowMenu();
public:
    void Init(int width = 640, int height = 360);
    void GameLoop();
    
};
