#include <SDL.h>

#include <cstdint>

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
