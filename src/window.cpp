#include <iostream>
#include <string>

#include "window.h"
#include "utilities/logging.h"
#include "utilities/sdl-helpers.h"

Window::Window()
{
    m_window_pointer = SDL_CreateWindow("SDL Tutorial",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH,
                                        SCREEN_HEIGHT,
                                        SDL_WINDOW_SHOWN);
}

Window::Window(Window& other) :
    m_window_pointer(other.m_window_pointer)
{
    other.nullify();
}

Window::Window(Window&& other) :
    m_window_pointer(other.m_window_pointer)
{
    other.nullify();
}

Window::~Window()
{
    deallocate();
}

Window& Window::operator=(Window& other)
{
    if(this != &other)
    {
        deallocate();

        m_window_pointer = other.m_window_pointer;

        other.nullify();
    }

    return *this;
}

Window& Window::operator=(Window&& other)
{
    if(this != &other)
    {
        deallocate();

        m_window_pointer = other.m_window_pointer;

        other.nullify();
    }

    return *this;
}

bool Window::update()
{
    return (SDL_UpdateWindowSurface(m_window_pointer) == 0L);
}

// SDL_Surface* loadSurface( std::string path )
// {
//     //The final optimized image
//     SDL_Surface* optimizedSurface = NULL;

//     //Load image at specified path
//     SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
//     if( loadedSurface == NULL )
//     {
//         LOG_ERROR("Unable to load: " << path << SDL_ERROR());
//     }
//     else
//     {
//         //Convert surface to screen format
//         optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
//         if( optimizedSurface == NULL )
//         {
//             LOG_ERROR("Unable to optimize image " << path << SDL_ERROR());
//         }

//         //Get rid of old loaded surface
//         SDL_FreeSurface( loadedSurface );
//     }

//     return optimizedSurface;
// }

SDL_Window* Window::pointer() const
{
    return m_window_pointer;
}

bool Window::is_valid() const
{
    return (m_window_pointer != nullptr);
}

bool Window::is_invalid() const
{
    return !(this->is_valid());
}

void Window::deallocate()
{
    if(m_window_pointer != nullptr)
    {
        SDL_DestroyWindow(m_window_pointer);
        nullify();
    }
}

void Window::nullify()
{
    m_window_pointer = nullptr;
}

