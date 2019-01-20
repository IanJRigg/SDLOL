#include "surface.h"

Surface::Surface() :
    m_surface_pointer(nullptr)
{

}

Surface::Surface(Surface& other) :
    m_surface_pointer(other.m_surface_pointer)
{
    other.nullify();
}

Surface::Surface(Surface&& other) :
    m_surface_pointer(other.m_surface_pointer)
{
    other.nullify();
}

Surface::~Surface()
{
    deallocate();
}

Surface& Surface::operator=(Surface& other)
{
    if(this != &other)
    {
        deallocate();

        m_surface_pointer = other.m_surface_pointer;

        other.nullify();
    }

    return *this;
}

Surface& Surface::operator=(Surface&& other)
{
    if(this != &other)
    {
        deallocate();

        m_surface_pointer = other.m_surface_pointer;

        other.nullify();
    }

    return *this;
}

// bool Surface::load_BMP()
// {
//     SDL_Surface* temp = SDL_LoadBMP("test.bmp");
//     bool success = false;

//     if(temp != nullptr)
//     {
//         success = this->blit_surface(temp);
//     }

//     SDL_FreeSurface(temp);
//     temp = nullptr;

//     return success;
// }

// bool Surface::blit_surface(const Surface& other)
// {
//     retrun (SDL_BlitSurface(other.pointer(), nullptr, m_surface_pointer, nullptr) == 0L);
// }

SDL_Surface* Surface::pointer() const
{
    return m_surface_pointer;
}

bool Surface::is_valid() const
{
    return (m_surface_pointer != nullptr);
}

bool Surface::is_invalid() const
{
    return !is_valid();
}

void Surface::deallocate()
{
    if(m_surface_pointer != nullptr)
    {
        SDL_FreeSurface(m_surface_pointer);
        nullify();
    }
}

void Surface::nullify()
{
    m_surface_pointer = nullptr;
}
