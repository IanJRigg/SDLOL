#include "sdl-controller.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <stdexcept>
#include <string>

SDL_Controller::SDL_Controller()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0L)
    {
        throw std::runtime_error("SDL could not initialize: " + std::string(SDL_GetError()));
    }

    if(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") == SDL_FALSE)
    {
        throw std::runtime_error("Unable to enable linear texture filtering.");
    }

    // Initialize PNG loading
    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        throw std::runtime_error("SDL_image could not initialize: " + std::string(SDL_GetError()));
    }

    // Initialize SDL_ttf
    if(TTF_Init() == -1L)
    {
        throw std::runtime_error("SDL_ttf could not initialize: " + std::string(TTF_GetError()));
    }
}

SDL_Controller::~SDL_Controller()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}