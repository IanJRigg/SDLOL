#include <iostream>
#include <string>

#include "window.h"

Window::Window(const std::string& title, const uint32_t width, const uint32_t height) :
    m_window_pointer(nullptr),
    m_title(title),
    m_width(width),
    m_height(height)
{
    m_window_pointer = SDL_CreateWindow(m_title.c_str(),
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        m_width,
                                        m_width,
                                        SDL_WINDOW_SHOWN);
}

Window::~Window()
{
    if(m_window_pointer != nullptr)
    {
        SDL_DestroyWindow(m_window_pointer);
        nullptr;
    }
}

bool Window::update()
{
    return (SDL_UpdateWindowSurface(m_window_pointer) == 0L);
}

// SDL_Surface* loadSurface(std::string path)
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

std::string Window::title() const
{
    return m_title;
}

uint32_t Window::height() const
{
    return m_height;
}

uint32_t Window::width() const
{
    return m_width;
}
