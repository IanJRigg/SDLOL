#ifndef TEXTURE_H
#define TEXTURE_H

#include <cstdint>
#include <string>
#include <SDL.h>

#include "renderer.h"
#include "font.h"

class Texture
{
public:
    Texture() = delete;
    Texture(Renderer& renderer, const std::string& path);
    Texture(Renderer& renderer,
            const Font& font,
            const std::string& text,
            const SDL_Color color);
    Texture(Texture& other);
    Texture(Texture&& other);
    virtual ~Texture();

    Texture& operator=(Texture& other);
    Texture& operator=(Texture&& other);

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

    void modulate_color(const SDL_Color& color) const;
    void set_alpha(const uint8_t alpha);
    void set_blend_mode(const SDL_BlendMode mode);

    bool load_rendered_text(const Font& font,
                            const std::string& text,
                            const SDL_Color color);

    SDL_Texture* pointer() const;

    uint32_t height() const;
    uint32_t width() const;

    bool is_valid() const;
    bool is_invalid() const;

private:
    void initialize(const std::string& path);
    void deallocate();
    void nullify();

private:
    SDL_Texture* m_texture_pointer;

    Renderer& m_renderer;

    uint32_t m_height;
    uint32_t m_width;
};

#endif