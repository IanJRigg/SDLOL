#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <cstdint>
#include <string>

class Window
{
public:
    Window() = delete;
    Window(const Window& other) = delete;
    Window(const Window&& other) noexcept = delete;

    Window& operator=(Window& other) = delete;
    Window& operator=(Window&& other) noexcept = delete;

    Window(const std::string& title, const uint32_t width, const uint32_t height);
    virtual ~Window();

    bool update();

    // Accessors
    SDL_Window* pointer() const;

    std::string title() const;
    uint32_t height() const;
    uint32_t width() const;

private:
    SDL_Window* m_window_pointer;
    const std::string m_title;
    const uint32_t m_width;
    const uint32_t m_height;
};

#endif