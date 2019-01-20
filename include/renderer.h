#ifndef RENDERER_H
#define RENDERER_H

#include <cstdint>

#include "window.h"
#include "colors.h"

class Renderer
{
public:
    Renderer() = delete;
    explicit Renderer(const Window& window);
    Renderer(Renderer& other);
    Renderer(Renderer&& other);
    virtual ~Renderer();

    Renderer& operator=(Renderer& other);
    Renderer& operator=(Renderer&& other);

    void set_draw_color(const SDL_Color& color);
    bool clear_target();
    void render_present();

    // Accessors
    SDL_Renderer* pointer() const;

    // Utility Functions
    bool is_valid() const;
    bool is_invalid() const;

public:
    static void Enable_VSYNC();
    static void Disable_VSYNC();

    static void Enable_Hardware_Acceleration();
    static void Disable_Hardware_Acceleration();

private:
    void deallocate();
    void nullify();

    static constexpr int32_t FIRST_SUPPORTED_DRIVER = -1L;

    static uint32_t VSYNC_Flag;
    static uint32_t Hardware_Acceleration_Flag;

private:
    SDL_Renderer* m_renderer_pointer;
};


#endif