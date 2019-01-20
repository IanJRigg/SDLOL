#ifndef SDL_UTILITIES_H
#define SDL_UTILITIES_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdint>

#define SDL_ERROR() std::string(SDL_GetError())
#define TTF_ERROR() std::string(TTF_GetError())

static constexpr int32_t FIRST_SUPPORTED_DRIVER = -1L;

#endif