#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <cstdint>
#include <string>
#include <memory>

class Window
{
public:
    Window() = delete;
    Window(const Window& other) = default;
    Window(Window&& other) noexcept = default;

    Window& operator=(const Window& other) = default;
    Window& operator=(Window&& other) noexcept = default;

    virtual ~Window() = default;

    Window(const std::string& title, const uint32_t width, const uint32_t height);

    bool update();

    // Accessors
    std::shared_ptr<SDL_Window> pointer() const;

    std::string title() const;
    uint32_t height() const;
    uint32_t width() const;

private:
    std::shared_ptr<SDL_Window> m_window_pointer;
};

#endif