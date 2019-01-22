#ifndef SURFACE_H
#define SURFACE_H

#include <SDL.h>
#include <string>

class Surface
{
public:
    Surface() = delete;
    Surface(Surface& other) = delete;
    Surface(Surface&& other) noexcept = delete;

    Surface& operator=(Surface& other) = delete;
    Surface& operator=(Surface&& other) noexcept = delete;

    explicit Surface(const std::string& path);
    virtual ~Surface();

    bool blit(const Surface& other);
    void load_bitmap(const std::string& path);

    // Accessors
    SDL_Surface* pointer() const;

private:
    SDL_Surface* m_surface_pointer;
};

#endif