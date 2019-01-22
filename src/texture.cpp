#include <SDL_image.h>
#include <iostream>

#include "texture.h"
#include "surface.h"
#include "sdlol-exception.h"

Texture::Texture(Renderer& renderer, const std::string& path) :
    m_texture_pointer(nullptr),
    m_renderer(renderer),
    m_height(0UL),
    m_width(0UL)
{
    load_image(path);
}

Texture::Texture(Renderer& renderer,
                 const Font& font,
                 const std::string& text,
                 const SDL_Color color) :
    m_texture_pointer(nullptr),
    m_renderer(renderer),
    m_height(0UL),
    m_width(0UL)
{
    load_text(font, text, color);
}

Texture::~Texture()
{
    deallocate_texture();
}

void Texture::load_image(const std::string& path)
{
    // If this function is called, the user has intended to destroy the current
    //   contents. The severity of this should be addressed later.
    deallocate_texture();

    SDL_Surface* surface = IMG_Load( path.c_str() );
    if( surface == nullptr )
    {
        throw SDLOL_Runtime_Exception("Error loading image, " + std::string(SDL_GetError()));
    }

    // Color key image
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0x00UL, 0xFFUL, 0xFFUL));

    // Create texture from surface pixels
    m_texture_pointer = SDL_CreateTextureFromSurface(m_renderer.pointer(), surface);
    if(m_texture_pointer == nullptr)
    {
        throw SDLOL_Runtime_Exception("Error creating texture, " + std::string(SDL_GetError()));
    }

    m_height = static_cast<uint32_t>(surface->h);
    m_width  = static_cast<uint32_t>(surface->w);

    SDL_FreeSurface(surface);
}

void Texture::load_text(const Font& font, const std::string& text, const SDL_Color color)
{
    // If this function is called, the user has intended to destroy the current
    //   contents. The severity of this should be addressed later.
    deallocate_texture();

    SDL_Surface* surface = TTF_RenderText_Solid(font.pointer(), text.c_str(), color);
    if(surface == nullptr)
    {
        throw SDLOL_Runtime_Exception("Error loading font, " + std::string(TTF_GetError()));
    }

    //Create texture from surface pixels
    m_texture_pointer = SDL_CreateTextureFromSurface(m_renderer.pointer(), surface);
    if(m_texture_pointer == nullptr)
    {
        throw SDLOL_Runtime_Exception("Error creating texture, " + std::string(SDL_GetError()));
    }

    m_width = surface->w;
    m_height = surface->h;

    SDL_FreeSurface(surface);
}

void Texture::render_at(const uint32_t x, const uint32_t y) const
{
    SDL_Rect quad
    {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(m_width),
        static_cast<int>(m_height)
    };

    SDL_RenderCopy(m_renderer.pointer(), m_texture_pointer, nullptr, &quad);
}

void Texture::render_at(const uint32_t x, const uint32_t y, const SDL_Rect& sprite) const
{
    SDL_Rect quad
    {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(sprite.w),
        static_cast<int>(sprite.h)
    };

    SDL_RenderCopy(m_renderer.pointer(), m_texture_pointer, &sprite, &quad);
}

// void Texture::render_at(const uint32_t x,
//                         const uint32_t y,
//                         const double angle,
//                         const SDL_RendererFlip flip) const
// {
//     SDL_Rect quad
//     {
//         static_cast<int>(x),
//         static_cast<int>(y),
//         static_cast<int>(m_width),
//         static_cast<int>(m_height)
//     };

//     SDL_RenderCopyEx(m_renderer.pointer(),
//                      m_texture_pointer,
//                      nullptr,
//                      &quad,
//                      angle,
//                      nullptr,
//                      flip);
// }

void Texture::render_at(const uint32_t x,
                        const uint32_t y,
                        const SDL_Rect& sprite,
                        const SDL_Point& center,
                        const double angle,
                        const SDL_RendererFlip flip) const
{
    SDL_Rect quad
    {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(sprite.w),
        static_cast<int>(sprite.h)
    };

    SDL_RenderCopyEx(m_renderer.pointer(),
                     m_texture_pointer,
                     &sprite,
                     &quad,
                     angle,
                     &center,
                     flip);
}

bool Texture::set_color_modulation(const SDL_Color& color) const
{
    return (SDL_SetTextureColorMod(m_texture_pointer, color.r, color.b, color.g) == 0L);
}

// Need to check for errors?
SDL_Color Texture::color_modulation() const
{
    SDL_Color color = { 0U, 0U, 0U, 0U };

    SDL_GetTextureColorMod(m_texture_pointer, &(color.r), &(color.g), &(color.b));

    return color;
}

bool Texture::set_alpha_modulation(const uint8_t alpha) const
{
    return (SDL_SetTextureAlphaMod(m_texture_pointer, alpha) == 0L);
}

// Need to check for errors?
uint8_t Texture::alpha_modulation() const
{
    uint8_t alpha = 0U;

    SDL_GetTextureAlphaMod(m_texture_pointer, &alpha);

    return alpha;
}

SDL_Texture* Texture::pointer() const
{
    return m_texture_pointer;
}

uint32_t Texture::height() const
{
    return m_height;
}

uint32_t Texture::width() const
{
    return m_width;
}

void Texture::deallocate_texture()
{
    if(m_texture_pointer != nullptr)
    {
        SDL_DestroyTexture(m_texture_pointer);
        m_texture_pointer = nullptr;
        m_height  = 0UL;
        m_width   = 0UL;
    }
}