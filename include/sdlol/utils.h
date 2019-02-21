#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <cstdint>
#include <stdexcept>
#include <string>

/**
 * \brief Returns true if the provided key code is reporting as pressed
 * \param keycode The numeric code for a pressable key
 * \return true if the key pressed, otherwise false
 */
inline bool KEY_IS_PRESSED(const uint32_t keycode)
{
    if(keycode < SDL_SCANCODE_A || keycode > SDL_NUM_SCANCODES)
    {
        return false;
    }

    const uint8_t* const key_states = SDL_GetKeyboardState(nullptr);

    return (key_states[keycode] == 1UL);
}

/**
 * \brief Calls the inialization functions for SDL, SDL_image, and SDL_ttf
 */
inline void INITIALIZE_SDL()
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

/**
 * \brief Calls the quit functions for SDL, SDL_image, and SDL_ttf
 */
inline void TEAR_DOWN_SDL()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}