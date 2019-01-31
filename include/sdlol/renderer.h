#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

#include "window.h"

class Renderer
{
public:
    Renderer() = delete;
    Renderer(Renderer& other) = default;
    Renderer(Renderer&& other) noexcept = default;

    Renderer& operator=(Renderer& other) = default;
    Renderer& operator=(Renderer&& other) noexcept = default;

    virtual ~Renderer() = default;

    explicit Renderer(const Window& window);

    bool set_draw_color(const SDL_Color& color);
    bool clear_target();
    void render_present();

    // Accessors
    std::shared_ptr<SDL_Renderer> pointer() const;

public:
    static void Enable_VSYNC();
    static void Disable_VSYNC();

    static void Enable_Hardware_Acceleration();
    static void Disable_Hardware_Acceleration();

private:
    static constexpr int32_t FIRST_SUPPORTED_DRIVER = -1L;

    static uint32_t VSYNC_Flag;
    static uint32_t Hardware_Acceleration_Flag;

private:
    std::shared_ptr<SDL_Renderer> m_renderer_pointer;
};


#endif