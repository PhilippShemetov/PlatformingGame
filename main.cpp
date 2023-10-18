#include <iostream>
#include <SDL2/SDL.h>
#include <Game.h>

int main(int argc, char* argv[]) {
    Game* gameObj = new Game();
    gameObj->Init();
    gameObj->GameLoop();
    return 0;

}