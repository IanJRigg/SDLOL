#include "texture.h"

#include <SDL_image.h>
#include <stdexcept>

static const auto DELETER_LAMBDA = [](SDL_Texture* pointer) { SDL_DestroyTexture(pointer); };


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

void Texture::render_at(const uint32_t x,
                        const uint32_t y,
                        const SDL_Rect& sprite_box) const
{
    SDL_Rect quad
    {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(sprite_box.w),
        static_cast<int>(sprite_box.h)
    };

    SDL_RenderCopy(m_renderer.pointer().get(),
                   m_texture_pointer.get(),
                   &sprite_box,
                   &quad);
}

void Texture::render_at(const uint32_t x,
                        const uint32_t y,
                        const double angle,
                        const SDL_RendererFlip flip) const
{
    SDL_Rect quad
    {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(this->width()),
        static_cast<int>(this->height())
    };

    SDL_RenderCopyEx(m_renderer.pointer().get(),
                     m_texture_pointer.get(),
                     nullptr,
                     &quad,
                     angle,
                     nullptr,
                     flip);
}

void Texture::render_at(const uint32_t x,
                        const uint32_t y,
                        const SDL_Rect& sprite_box,
                        const SDL_Point& center,
                        const double angle,
                        const SDL_RendererFlip flip) const
{
    SDL_Rect quad
    {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(sprite_box.w),
        static_cast<int>(sprite_box.h)
    };

    SDL_RenderCopyEx(m_renderer.pointer().get(),
                     m_texture_pointer.get(),
                     &sprite_box,
                     &quad,
                     angle,
                     &center,
                     flip);
}

bool Texture::set_color_modulation(const SDL_Color& color) const
{
    int result = SDL_SetTextureColorMod(m_texture_pointer.get(),
                                        color.r,
                                        color.b,
                                        color.g);
    return (result == 0L);
}

// Need to check for errors?
SDL_Color Texture::color_modulation() const
{
    SDL_Color color = { 0U, 0U, 0U, 0U };

    SDL_GetTextureColorMod(m_texture_pointer.get(),
                           &(color.r),
                           &(color.g),
                           &(color.b));

    return color;
}

bool Texture::set_alpha_modulation(const uint8_t alpha) const
{
    int result = SDL_SetTextureAlphaMod(m_texture_pointer.get(), alpha);
    return (result == 0L);
}

// Need to check for errors?
uint8_t Texture::alpha_modulation() const
{
    uint8_t alpha = 0U;

    SDL_GetTextureAlphaMod(m_texture_pointer.get(), &alpha);

    return alpha;
}

void Texture::load_surface(const Surface& surface)
{
    // Create texture from surface pixels
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer.pointer().get(),
                                                        surface.pointer().get());
    if(texture == nullptr)
    {
        throw std::runtime_error("Error creating texture, " + std::string(SDL_GetError()));
    }

    m_texture_pointer.reset(texture, DELETER_LAMBDA);
}

void Texture::load_image(const std::string& path_to_image)
{
    Surface surface(path_to_image);
    load_surface(surface);
}

std::shared_ptr<SDL_Texture> Texture::pointer() const
{
    return m_texture_pointer;
}

uint32_t Texture::height() const
{
    if(m_texture_pointer == nullptr)
    {
        return 0UL;
    }

    int h = 0UL;
    int result = SDL_QueryTexture(m_texture_pointer.get(),
                                  nullptr,
                                  nullptr,
                                  nullptr,
                                  &h);

    return (result == 0L) ? static_cast<uint32_t>(h) : 0L;
}

uint32_t Texture::width() const
{
    if(m_texture_pointer == nullptr)
    {
        return 0UL;
    }

    int w = 0UL;
    int result = SDL_QueryTexture(m_texture_pointer.get(),
                        nullptr,
                        nullptr,
                        &w,
                        nullptr);

    return (result == 0L) ? static_cast<uint32_t>(w) : 0L;
}