#include <iostream>

#include "renderer.h"
#include "utilities/logging.h"
#include "utilities/sdl-helpers.h"

uint32_t Renderer::VSYNC_Flag = 0UL;
uint32_t Renderer::Hardware_Acceleration_Flag = 0UL;

Renderer::Renderer(const Window& window)
{
    uint32_t render_flags = VSYNC_Flag | Hardware_Acceleration_Flag;

    m_renderer_pointer = SDL_CreateRenderer(window.pointer(),
                                            FIRST_SUPPORTED_DRIVER,
                                            render_flags);
}

Renderer::Renderer(Renderer& other) :
    m_renderer_pointer(other.m_renderer_pointer)
{
    other.nullify();
}

Renderer::Renderer(Renderer&& other) :
    m_renderer_pointer(other.m_renderer_pointer)
{
    other.nullify();
}

Renderer::~Renderer()
{
    deallocate();
}

Renderer& Renderer::operator=(Renderer& other)
{
    if(this != &other)
    {
        deallocate();

        m_renderer_pointer = other.m_renderer_pointer;

        other.nullify();
    }

    return *this;
}

Renderer& Renderer::operator=(Renderer&& other)
{
    if(this != &other)
    {
        deallocate();

        m_renderer_pointer = other.m_renderer_pointer;

        other.nullify();
    }

    return *this;
}

void Renderer::set_draw_color(const SDL_Color& color)
{
    SDL_SetRenderDrawColor(m_renderer_pointer, color.r, color.g, color.b, color.a);
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

bool Renderer::is_valid() const
{
    return (m_renderer_pointer != nullptr);
}

bool Renderer::is_invalid() const
{
    return !(this->is_valid());
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

void Renderer::deallocate()
{
    if(m_renderer_pointer != nullptr)
    {
        SDL_DestroyRenderer(m_renderer_pointer);
        nullify();
    }
}

void Renderer::nullify()
{
    m_renderer_pointer = nullptr;
}