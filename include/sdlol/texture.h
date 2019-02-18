#ifndef TEXTURE_H
#define TEXTURE_H

#include "renderer.h"
#include "surface.h"

class Texture
{
public:
    Texture() = delete;
    Texture(const Texture& other) = default;
    Texture(Texture&& other) noexcept = default;

    // Deleted because the reference can't be transferred after construction
    Texture& operator=(const Texture& other) = delete;
    Texture& operator=(Texture&& other) noexcept = delete;

    virtual ~Texture() = default;

    Texture(Renderer& renderer, const std::string& path_to_image);
    Texture(Renderer& renderer, const Surface& surface);

    // Rendering functions
    void render_at(const uint32_t x,
                   const uint32_t y,
                   const SDL_Rect& source_box) const;

    void render_at(const uint32_t x,
                   const uint32_t y,
                   const SDL_Rect& source_box,
                   const SDL_Rect& destination_box) const;

    void render_at(const uint32_t x,
                   const uint32_t y,
                   const double angle = 0.0,
                   const SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    void render_at(const uint32_t x,
                   const uint32_t y,
                   const SDL_Rect& sprite,
                   const SDL_Point& center,
                   const double angle = 0.0,
                   const SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    // Color modulation
    bool set_color_modulation(const SDL_Color& color) const;
    SDL_Color color_modulation() const;

    // Alpha Modulation
    bool set_alpha_modulation(const uint8_t alpha) const;
    uint8_t alpha_modulation() const;

    // Blend Mode
    bool set_blend_mode(const SDL_BlendMode mode);
    SDL_BlendMode blend_mode() const;

    // Conversion utilities
    void load_surface(const Surface& surface);
    void load_image(const std::string& path_to_image);

    std::shared_ptr<SDL_Texture> pointer() const;

    uint32_t height() const;
    uint32_t width() const;

protected:
    // Constructor for all children
    explicit Texture(Renderer& renderer);

private:
    std::shared_ptr<SDL_Texture> m_texture_pointer;

    Renderer& m_renderer;
};

#endif