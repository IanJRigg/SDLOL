#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <cstdint>

class Window
{
public:
    Window();
    Window(Window& other);
    Window(Window&& other);
    virtual ~Window();

    Window& operator=(Window& other);
    Window& operator=(Window&& other);

    bool update();

    // Accessors
    SDL_Window* pointer() const;

    // Utility Functions
    bool is_valid() const;
    bool is_invalid() const;

private:
    void deallocate();
    void nullify();

private:
    static constexpr uint32_t SCREEN_WIDTH  = 640UL;
    static constexpr uint32_t SCREEN_HEIGHT = 480UL;

    SDL_Window* m_window_pointer;
};

#endif