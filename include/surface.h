#ifndef SURFACE_H
#define SURFACE_H

#include <SDL.h>

class Surface
{
public:
    Surface();
    Surface(Surface& other);
    Surface(Surface&& other);
    virtual ~Surface();

    Surface& operator=(Surface& other);
    Surface& operator=(Surface&& other);

    // bool blit_surface(const Surface& other);
    // bool load_bitmap();

    // Accessors
    SDL_Surface* pointer() const;

    // Utility Functions
    bool is_valid() const;
    bool is_invalid() const;

private:
    void deallocate();
    void nullify();

private:
    SDL_Surface* m_surface_pointer;
};

#endif