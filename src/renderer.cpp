#include <iostream>

#include "renderer.h"

uint32_t Renderer::VSYNC_Flag = 0UL;
uint32_t Renderer::Hardware_Acceleration_Flag = 0UL;

Renderer::Renderer(const Window& window) :
    m_renderer_pointer(nullptr),
    m_options_mask(VSYNC_Flag | Hardware_Acceleration_Flag)
{
    m_renderer_pointer = SDL_CreateRenderer(window.pointer(),
                                            FIRST_SUPPORTED_DRIVER,
                                            m_options_mask);
}

Renderer::~Renderer()
{
    if(m_renderer_pointer != nullptr)
    {
        SDL_DestroyRenderer(m_renderer_pointer);
        m_renderer_pointer = nullptr;
    }
}

bool Renderer::set_draw_color(const SDL_Color& color)
{
    return (SDL_SetRenderDrawColor(m_renderer_pointer, color.r, color.g, color.b, color.a) == 0L);
}

bool Renderer::clear_target()
{
    return (SDL_RenderClear(this->m_renderer_pointer) == 0L);
}

void Renderer::render_present()
{
    SDL_RenderPresent(this->m_renderer_pointer);
}

SDL_Renderer* Renderer::pointer() const
{
    return m_renderer_pointer;
}

uint32_t Renderer::options_mask() const
{
    return m_options_mask;
}

void Renderer::Enable_VSYNC()
{
    VSYNC_Flag = SDL_RENDERER_PRESENTVSYNC;
}

void Renderer::Disable_VSYNC()
{
    VSYNC_Flag = 0UL;
}

void Renderer::Enable_Hardware_Acceleration()
{
    Hardware_Acceleration_Flag = SDL_RENDERER_ACCELERATED;
}

void Renderer::Disable_Hardware_Acceleration()
{
    Hardware_Acceleration_Flag = 0UL;
}
