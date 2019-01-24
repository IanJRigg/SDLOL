#ifndef RENDERER_H
#define RENDERER_H

#include "window.h"

class Renderer
{
public:
    Renderer() = delete;
    Renderer(Renderer& other) = delete;
    Renderer(Renderer&& other) noexcept = delete;

    Renderer& operator=(Renderer& other) = delete;
    Renderer& operator=(Renderer&& other) noexcept = delete;

    explicit Renderer(const Window& window);
    virtual ~Renderer();

    bool set_draw_color(const SDL_Color& color);
    bool clear_target();
    void render_present();

    // Accessors
    SDL_Renderer* pointer() const;
    uint32_t options_mask() const;

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
    SDL_Renderer* m_renderer_pointer;
    const uint32_t m_options_mask;
};


#endif