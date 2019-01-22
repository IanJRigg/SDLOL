#include "surface.h"
#include "sdlol-exception.h"

Surface::Surface(const std::string& path) :
    m_surface_pointer(nullptr)
{
    load_bitmap(path);
}

Surface::~Surface()
{
    if(m_surface_pointer == nullptr)
    {
        SDL_FreeSurface(m_surface_pointer);
        m_surface_pointer = nullptr;
    }
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
