#include "surface.h"
#include "exception.h"

Surface::Surface(const std::string& path) :
    m_surface_pointer(nullptr)
{
    load_bitmap(path);
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
    deallocate();
    m_surface_pointer = pointer;
    return *this;
}

bool Surface::set_color_key(const SDL_Color& color)
{
    uint32_t key = SDL_MapRGB(m_surface_pointer->format, color.r, color.g, color.b);
    return (SDL_SetColorKey(m_surface_pointer, SDL_TRUE, key) == 0L);
}

bool Surface::blit(const Surface& other)
{
    return (SDL_BlitSurface(other.pointer(), nullptr, m_surface_pointer, nullptr) == 0L);
}

void Surface::load_bitmap(const std::string& path)
{
    SDL_Surface* temp = SDL_LoadBMP(path.c_str());
    if(temp == nullptr)
    {
        throw SDLOL_Runtime_Exception("File not found at: " + path);
    }

    if(SDL_BlitSurface(temp, nullptr, m_surface_pointer, nullptr) == 0L)
    {
        throw SDLOL_Runtime_Exception("Unable to blit surface");
    }

    SDL_FreeSurface(temp);
    temp = nullptr;
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