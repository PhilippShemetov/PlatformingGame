#include <iostream>
#include <SDL2/SDL.h>
#include <Game.h>

int main(int argc, char* argv[]) {
    Game* gameObj = new Game();
    gameObj->Init(500,720);
    gameObj->GameLoop();
    return 0;

}