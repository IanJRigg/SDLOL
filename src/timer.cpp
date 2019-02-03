#include "timer.h"

#include <SDL.h>

Timer::Timer() :
    m_start_time(0UL),
    m_pause_time(0UL),
    m_is_paused(false),
    m_is_started(false)
{

}

void Timer::start()
{
    m_is_started = true;
    m_is_paused = false;

    m_start_time = 0UL;
    m_pause_time = 0UL;
}

void Timer::stop()
{
   m_is_started = false;
   m_is_paused = false;

   m_start_time = 0UL;
   m_pause_time = 0UL;
}

void Timer::pause()
{
    if(this->is_started() && this->is_not_paused())
    {
        m_is_paused = true;

        m_pause_time = SDL_GetTicks() - m_start_time;
        m_start_time = 0UL;
    }
}

void Timer::unpause()
{
    if(this->is_started() && this->is_paused())
    {
        m_is_paused = false;

        m_start_time = SDL_GetTicks() - m_pause_time;
        m_pause_time = 0UL;
    }
}

uint32_t Timer::current_time()
{
    uint32_t time = 0UL;

    if(this->is_started())
    {
        time = (this->is_not_paused())
            ? (SDL_GetTicks() - m_start_time)
            : m_pause_time;
    }

    return time;
}

bool Timer::is_started()
{
    return m_is_started;
}

bool Timer::is_not_started()
{
    return !(this->is_started());
}

bool Timer::is_paused()
{
    return m_is_started && m_is_paused;
}

bool Timer::is_not_paused()
{
    return !(this->is_paused());
}
