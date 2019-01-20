#include <cstdint>
#include <SDL.h>


inline bool key_is_pressed(const uint32_t keycode)
{
    if(keycode < SDL_SCANCODE_A || keycode > SDL_NUM_SCANCODES)
    {
        return false;
    }

    const uint8_t* const key_states = SDL_GetKeyboardState(nullptr);

    return (key_states[keycode] == 1UL);
}