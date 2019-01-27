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
    explicit Surface(SDL_Surface* const pointer);
    virtual ~Surface();

    Surface& operator=(SDL_Surface* pointer);

    bool set_color_key(const SDL_Color& color);

    bool blit(const Surface& other);
    void load_bitmap(const std::string& path);

    // Accessors
    SDL_Surface* pointer() const;

    uint32_t height() const;
    uint32_t width() const;

private:
    void deallocate();

private:
    SDL_Surface* m_surface_pointer;
};

#endif