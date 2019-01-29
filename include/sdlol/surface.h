#ifndef SURFACE_H
#define SURFACE_H

#include <SDL.h>
#include <string>

class Surface
{
public:
    Surface() = delete;
    Surface(Surface& other) = default;
    Surface(Surface&& other) noexcept = delete;

    Surface& operator=(Surface& other) = delete;
    Surface& operator=(Surface&& other) noexcept = delete;

    explicit Surface(const std::string& path);
    explicit Surface(SDL_Surface* const pointer);
    virtual ~Surface() = default;

    Surface& operator=(SDL_Surface* pointer);

    void load_image(const std::string& path_to_image);

    bool set_color_key(const SDL_Color& color);

    bool blit(const Surface& other);

    // Accessors
    std::shared_ptr<SDL_Surface> pointer() const;

    uint32_t height() const;
    uint32_t width() const;

private:
    std::shared_ptr<SDL_Surface> m_surface_pointer;
};

#endif