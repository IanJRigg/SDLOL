#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>

#include "renderer.h"
#include "font.h"

class Texture
{
public:
    Texture() = delete;
    Texture(Texture& other) = delete;
    Texture(Texture&& other) noexcept = delete;

    Texture& operator=(Texture& other) = delete;
    Texture& operator=(Texture&& other) noexcept = delete;

    Texture(Renderer& renderer, const std::string& path);
    Texture(Renderer& renderer,
            const Font& font,
            const std::string& text,
            const SDL_Color color);
    virtual ~Texture();

    void render_at(const uint32_t x, const uint32_t y) const;
    void render_at(const uint32_t x, const uint32_t y, const SDL_Rect& sprite) const;
    // void render_at(const uint32_t x,
    //                const uint32_t y,
    //                const double angle = 0.0,
    //                const SDL_RendererFlip flip = SDL_FLIP_NONE) const;
    void render_at(const uint32_t x,
                   const uint32_t y,
                   const SDL_Rect& sprite,
                   const SDL_Point& center,
                   const double angle = 0.0,
                   const SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    bool set_color_modulation(const SDL_Color& color) const;
    SDL_Color color_modulation() const;

    bool set_alpha_modulation(const uint8_t alpha) const;
    uint8_t alpha_modulation() const;

    void set_blend_mode(const SDL_BlendMode mode);

    SDL_Texture* pointer() const;

    uint32_t height() const; 
    uint32_t width() const;

private:
    void initialize(const std::string& path);
    bool load_rendered_text(const Font& font,
                            const std::string& text,
                            const SDL_Color color);

private:
    SDL_Texture* m_texture_pointer;

    Renderer& m_renderer;

    uint32_t m_height;
    uint32_t m_width;
};

#endif