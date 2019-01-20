#ifndef SURFACE_H
#define SURFACE_H

#include <SDL.h>
#include <string>

class Surface
{
public:
    Surface() = delete;
    explicit Surface(const std::string& path);
    Surface(Surface& other);
    Surface(Surface&& other);
    virtual ~Surface();

    Surface& operator=(Surface& other);
    Surface& operator=(Surface&& other);

    bool blit(const Surface& other);
    void load_bitmap(const std::string& path);

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