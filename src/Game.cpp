#include "Game.h"

void Game::Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "System was initialized!" << std::endl;
	
        gameWindow = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0), SDL_DestroyWindow);
        if (gameWindow) {
            std::cout << "Game Window created..." << std::endl;
        } else {
            std::cerr << SDL_GetError() << std::endl;
            std::exit(1);
        }
        gameRendrerer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(gameWindow.get(),-1,0));
        if (gameRendrerer) {
            std::cout << "Game Renderer created..." << std::endl;
        } else {
            std::cerr << SDL_GetError() << std::endl;
            std::exit(1);
        }
        gameState = StateGame::Paused;
    } else {
        gameState = StateGame::Stopped;
    }

}

void Game::GameLoop() {
    while(gameState != StateGame::Stopped) {
        switch (gameState)
        {
        case StateGame::Paused:
            //Game::ShowMenu();
            break;
        case StateGame::Exit:
            break;
        default:
            break;
        }
    }
}

Game::StateGame Game::gameState = Uninitialized;
std::shared_ptr<SDL_Window> Game::gameWindow(nullptr);
std::shared_ptr<SDL_Renderer> Game::gameRendrerer(nullptr);