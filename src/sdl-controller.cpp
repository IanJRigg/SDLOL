#include "sdl-controller.h"

#include "utilities/sdl-helpers.h"
#include "utilities/logging.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

SDL_Controller::SDL_Controller()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0L)
    {
        LOG_ERROR("SDL could not initialize: " + SDL_ERROR());
    }

    if(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") == SDL_FALSE)
    {
        LOG_ERROR("Unable to enable linear texture filtering.");
    }

    // Initialize PNG loading
    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        LOG_ERROR("SDL_image could not initialize: " + SDL_ERROR());
    }

    // Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        LOG_ERROR("SDL_ttf could not initialize: " + TTF_ERROR());
    }
}

SDL_Controller::~SDL_Controller()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}