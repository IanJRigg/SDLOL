#ifndef EVENT_CONTROLLER_H
#define EVENT_CONTROLLER_H

#include <SDL.H>

class Event_Handler
{
public:
    Event_Handler() = default;
    Event_Handler(const Event_Handler& other) = default;
    Event_Handler(Event_Handler&& other) noexcept = default;

    Event_Handler& operator=(const Event_Handler& other) = default;
    Event_Handler& operator=(Event_Handler&& other) noexcept = default;

    virtual ~Event_Handler() = default;

    virtual void on_left_mouse_down(const SDL_Event& event) { };
    virtual void on_right_mouse_down(const SDL_Event& event) { };
    virtual void on_left_mouse_up(const SDL_Event& event) { };
    virtual void on_right_mouse_up(const SDL_Event& event) { };
    virtual void on_key_down(const SDL_Event& event) { };
    virtual void on_key_up(const SDL_Event& event) { };
};

#endif