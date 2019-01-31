#include <iostream>

#include "renderer.h"

uint32_t Renderer::VSYNC_Flag = 0UL;
uint32_t Renderer::Hardware_Acceleration_Flag = 0UL;

static const auto DELETER_LAMBDA = [](SDL_Renderer* pointer) { SDL_DestroyRenderer(pointer); };

Renderer::Renderer(const Window& window) :
    m_renderer_pointer(nullptr)
{
    uint32_t options_mask = VSYNC_Flag | Hardware_Acceleration_Flag;

    SDL_Renderer* renderer = SDL_CreateRenderer(window.pointer(),
                                                FIRST_SUPPORTED_DRIVER,
                                                options_mask);

    m_renderer_pointer.reset(renderer, DELETER_LAMBDA);
}

bool Renderer::set_draw_color(const SDL_Color& color)
{
    return (SDL_SetRenderDrawColor(m_renderer_pointer.get(),
                                   color.r,
                                   color.g,
                                   color.b,
                                   color.a) == 0L);
}

bool Renderer::clear_target()
{
    return (SDL_RenderClear(m_renderer_pointer.get()) == 0L);
}

void Renderer::render_present()
{
    SDL_RenderPresent(m_renderer_pointer.get());
}

std::shared_ptr<SDL_Renderer> Renderer::pointer() const
{
    return m_renderer_pointer;
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
