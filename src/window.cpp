#include "window.h"

static const auto DELETER_LAMBDA = [](SDL_Window* pointer) { SDL_DestroyWindow(pointer); };

Window::Window(const std::string& title, const uint32_t width, const uint32_t height) :
    m_window_pointer(nullptr)
{
    SDL_Window* window = SDL_CreateWindow(title.c_str(),
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          width,
                                          height,
                                          SDL_WINDOW_SHOWN);

    m_window_pointer.reset(window, DELETER_LAMBDA);
}

bool Window::update()
{
    return (SDL_UpdateWindowSurface(m_window_pointer.get()) == 0L);
}

std::shared_ptr<SDL_Window> Window::pointer() const
{
    return m_window_pointer;
}

std::string Window::title() const
{
    return std::string(SDL_GetWindowTitle(m_window_pointer.get()));
}

uint32_t Window::height() const
{
    int h = 0L;
    SDL_GetWindowSize(m_window_pointer.get(), nullptr, &h);

    return static_cast<uint32_t>(h);
}

uint32_t Window::width() const
{
    int w = 0L;
    SDL_GetWindowSize(m_window_pointer.get(), &w, nullptr);

    return static_cast<uint32_t>(w);
}
