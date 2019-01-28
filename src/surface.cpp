#include "surface.h"
#include "exception.h"

#include <SDL_image.h>

Surface::Surface(const std::string& path_to_image) :
    m_surface_pointer(nullptr)
{
    load_image(path_to_image);
}

Surface::Surface(SDL_Surface* const pointer) :
    m_surface_pointer(pointer)
{

}

Surface::~Surface()
{
    deallocate();
}

Surface& Surface::operator=(SDL_Surface* const pointer)
{
    // Make sure self assignment doesn't deallocate anything
    if(pointer == m_surface_pointer)
    {
        return *this;
    }

    deallocate();
    m_surface_pointer = pointer;
    return *this;
}

bool Surface::load_image(const std::string& path_to_image)
{
    m_surface_pointer = IMG_Load(path_to_image.c_str());
}

bool Surface::set_color_key(const SDL_Color& color)
{
    uint32_t key = SDL_MapRGB(m_surface_pointer->format,
                              color.r,
                              color.g,
                              color.b);

    return (SDL_SetColorKey(m_surface_pointer, SDL_TRUE, key) == 0L);
}

bool Surface::blit(const Surface& source)
{
    return (SDL_BlitSurface(source.pointer(),  nullptr,
                            m_surface_pointer, nullptr) == 0L);
}

SDL_Surface* Surface::pointer() const
{
    return m_surface_pointer;
}

uint32_t Surface::height() const
{
    return (m_surface_pointer != nullptr) ? m_surface_pointer->h : 0UL;
}

uint32_t Surface::width() const
{
    return (m_surface_pointer != nullptr) ? m_surface_pointer->w : 0UL;
}

void Surface::deallocate()
{
    if(m_surface_pointer == nullptr)
    {
        SDL_FreeSurface(m_surface_pointer);
        m_surface_pointer = nullptr;
    }
}