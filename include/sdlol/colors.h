#ifndef RGBA_H
#define RGBA_H

#include <SDL.h>

static constexpr SDL_Color COLOR_WHITE = { 0xFFU, 0xFFU, 0xFFU, 0xFFU };
static constexpr SDL_Color COLOR_BLACK = { 0x00U, 0x00U, 0x00U, 0xFFU };
static constexpr SDL_Color COLOR_RED   = { 0xFFU, 0x00U, 0x00U, 0xFFU };
static constexpr SDL_Color COLOR_GREEN = { 0x00U, 0xFFU, 0x00U, 0xFFU };
static constexpr SDL_Color COLOR_BLUE  = { 0x00U, 0x00U, 0xFFU, 0xFFU };

#endif