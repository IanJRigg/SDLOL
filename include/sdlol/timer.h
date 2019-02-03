#ifndef TIMER_H
#define TIMER_H

#include <cstdint>

class Timer
{
public:
    Timer();

    Timer(const Timer& other) = delete;
    Timer(Timer&& other) noexcept = delete;

    Timer& operator=(const Timer& other) = delete;
    Timer& operator=(Timer&& other) = delete;

    virtual ~Timer() = default;

    void start();
    void stop();

    void pause();
    void unpause();

    uint32_t current_time();

    bool is_started();
    bool is_not_started();

    bool is_paused();
    bool is_not_paused();

private:
    uint32_t m_start_time;
    uint32_t m_pause_time;

    bool m_is_paused;
    bool m_is_started;

};

#endif