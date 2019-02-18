/** \file texture.cpp
    \brief RAII wrapper around the SDL Texture
*/

#include "texture.h"

#include <SDL_image.h>
#include <stdexcept>

static const auto DELETER_LAMBDA = [](SDL_Texture* pointer) { SDL_DestroyTexture(pointer); };

/**
 * \brief 
 * \param 
 * \return 
 */
Texture::Texture(Renderer& renderer) :
    m_texture_pointer(nullptr),
    m_renderer(renderer)
{

}

/**
 * \brief 
 * \param 
 * \param 
 * \return 
 */
Texture::Texture(Renderer& renderer, const std::string& path_to_image) :
    Texture(renderer)
{
    this->load_image(path_to_image);
}

/**
 * \brief 
 * \param 
 * \param 
 * \return 
 */
Texture::Texture(Renderer& renderer, const Surface& surface) :
    Texture(renderer)
{
    this->load_surface(surface);
}

/**
 * \brief 
 * \param 
 * \param 
 * \param 
 * \return 
 */
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
                   nullptr);
}

/**
 * \brief 
 * \param 
 * \param 
 * \param 
 * \param 
 * \return 
 */
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

/**
 * \brief 
 * \param 
 * \param 
 * \param 
 * \param 
 * \param 
 * \param 
 * \return 
 */
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

/**
 * \brief 
 * \param 
 * \return 
 */
bool Texture::set_color_modulation(const SDL_Color& color) const
{
    int result = SDL_SetTextureColorMod(m_texture_pointer.get(),
                                        color.r,
                                        color.b,
                                        color.g);
    return (result == 0L);
}

// Need to check for errors?
/**
 * \brief 
 * \return 
 */
SDL_Color Texture::color_modulation() const
{
    SDL_Color color = { 0U, 0U, 0U, 0U };

    SDL_GetTextureColorMod(m_texture_pointer.get(),
                           &(color.r),
                           &(color.g),
                           &(color.b));

    return color;
}

/**
 * \brief 
 * \param 
 * \return 
 */
bool Texture::set_alpha_modulation(const uint8_t alpha) const
{
    int result = SDL_SetTextureAlphaMod(m_texture_pointer.get(), alpha);
    return (result == 0L);
}

/**
 * \brief 
 * \return 
 */
uint8_t Texture::alpha_modulation() const
{
    // Need to check for errors?
    uint8_t alpha = 0U;

    SDL_GetTextureAlphaMod(m_texture_pointer.get(), &alpha);

    return alpha;
}

/**
 * \brief 
 * \param 
 * \return 
 */
bool Texture::set_blend_mode(const SDL_BlendMode mode)
{
    return (SDL_SetTextureBlendMode(m_texture_pointer.get(), mode) == 0L);
}

/**
 * \brief 
 * \return 
 */
SDL_BlendMode Texture::blend_mode() const
{
    // Need to check for errors?
    SDL_BlendMode mode = SDL_BLENDMODE_NONE;

    SDL_GetTextureBlendMode(m_texture_pointer.get(), &mode);

    return mode;
}

/**
 * \brief 
 * \param 
 * \return 
 */
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

/**
 * \brief 
 * \param 
 * \return 
 */
void Texture::load_image(const std::string& path_to_image)
{
    Surface surface(path_to_image);
    load_surface(surface);
}

/**
 * \brief 
 * \return 
 */
std::shared_ptr<SDL_Texture> Texture::pointer() const
{
    return m_texture_pointer;
}

/**
 * \brief 
 * \return 
 */
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

/**
 * \brief 
 * \return 
 */
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