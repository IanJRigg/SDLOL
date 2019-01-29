#include <SDL_image.h>
#include <iostream>

#include "texture.h"
#include "surface.h"
#include "exception.h"

Texture::Texture(Renderer& renderer) :
    m_texture_pointer(nullptr),
    m_renderer(renderer)
{

}

Texture::Texture(Renderer& renderer, const std::string& path_to_image) :
    Texture(renderer)
{
    this->load_image(path_to_image);
}

Texture::Texture(Renderer& renderer, const Surface& surface) :
    Texture(renderer)
{
    this->load_surface(surface);
}

Texture::~Texture()
{
    this->deallocate();
}

void Texture::render_at(const uint32_t x, const uint32_t y) const
{
    SDL_Rect quad
    {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(this->width()),
        static_cast<int>(this->height())
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
//         static_cast<int>(this->width()),
//         static_cast<int>(this->height())
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

void Texture::load_surface(const Surface& surface)
{
    // If this function is called, the user has intended to destroy the current contents.
    deallocate();

    // Create texture from surface pixels
    m_texture_pointer = SDL_CreateTextureFromSurface(m_renderer.pointer(), surface.pointer().get());
    if(m_texture_pointer == nullptr)
    {
        throw SDLOL_Runtime_Exception("Error creating texture, " + std::string(SDL_GetError()));
    }
}

void Texture::load_image(const std::string& path_to_image)
{
    Surface surface(path_to_image);
    load_surface(surface);
}

SDL_Texture* Texture::pointer() const
{
    return m_texture_pointer;
}

uint32_t Texture::height() const
{
    if(m_texture_pointer != nullptr)
    {
        return 0UL;
    }

    int texture_height = 0UL;

    if(SDL_QueryTexture(m_texture_pointer, nullptr, nullptr, nullptr, &texture_height) != 0L)
    {
        return 0UL;
    }

    return static_cast<uint32_t>(texture_height);
}

uint32_t Texture::width() const
{
    if(m_texture_pointer != nullptr)
    {
        return 0UL;
    }

    int texture_width = 0UL;

    if(SDL_QueryTexture(m_texture_pointer, nullptr, nullptr, &texture_width, nullptr) != 0L)
    {
        return 0UL;
    }

    return static_cast<uint32_t>(texture_width);
}

void Texture::deallocate()
{
    if(m_texture_pointer != nullptr)
    {
        SDL_DestroyTexture(m_texture_pointer);
        m_texture_pointer = nullptr;
    }
}