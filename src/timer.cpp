#include "timer.h"

#include <SDL.h>

Timer::Timer() :
    m_start_time(0UL),
    m_is_started(false)
{

}

void Timer::start()
{
    m_is_started = true;
    m_start_time = SDL_GetTicks();
}

void Timer::stop()
{
   m_is_started = false;
   m_start_time = 0UL;
}

uint32_t Timer::current_time()
{
    return (this->is_started()) ? (SDL_GetTicks() - m_start_time) : 0UL;
}

bool Timer::is_started()
{
    return m_is_started;
}

bool Timer::is_not_started()
{
    return !(this->is_started());
}
