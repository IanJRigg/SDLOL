#include "surface.h"
#include "exception.h"

#include <SDL_image.h>

static const auto DELETER_LAMBDA = [](SDL_Surface* pointer){ SDL_FreeSurface(pointer); };

Surface::Surface(const std::string& path_to_image) :
    m_surface_pointer(nullptr, DELETER_LAMBDA)
{
    load_image(path_to_image);
}

Surface::Surface(SDL_Surface* const pointer) :
    m_surface_pointer(pointer)
{

}

Surface& Surface::operator=(SDL_Surface* const pointer)
{
    // Make sure self assignment doesn't deallocate anything
    if(m_surface_pointer.get() != pointer)
    {
        m_surface_pointer.reset(pointer, DELETER_LAMBDA);
    }

    return *this;
}

void Surface::load_image(const std::string& path_to_image)
{
    SDL_Surface* surface = IMG_Load(path_to_image.c_str());
    if(surface == nullptr)
    {
        throw new SDLOL_Runtime_Exception("Unable to find resource at: " + path_to_image);
    }

    m_surface_pointer.reset(surface, DELETER_LAMBDA);
}

bool Surface::set_color_key(const SDL_Color& color)
{
    uint32_t key = SDL_MapRGB(m_surface_pointer.get()->format,
                              color.r,
                              color.g,
                              color.b);

    return (SDL_SetColorKey(m_surface_pointer.get(), SDL_TRUE, key) == 0L);
}

bool Surface::blit(const Surface& source)
{
    return (SDL_BlitSurface(source.pointer().get(),  nullptr,
                            m_surface_pointer.get(), nullptr) == 0L);
}

std::shared_ptr<SDL_Surface> Surface::pointer() const
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