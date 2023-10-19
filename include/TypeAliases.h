#ifndef HEADER_H_TypeAliases
#define HEADER_H_TypeAliases

#include <SDL2/SDL.h>
#include <memory>

using SDLRendererSptr = std::shared_ptr<SDL_Renderer>;
using SDLWindowSptr = std::shared_ptr<SDL_Window>;

#endif