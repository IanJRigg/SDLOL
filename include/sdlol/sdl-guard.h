#ifndef SDL_GUARD_H
#define SDL_GUARD_H

class SDL_Guard final
{
public:
    SDL_Guard();
    SDL_Guard(SDL_Guard& other) = delete;
    SDL_Guard(SDL_Guard&& other) = delete;
    virtual ~SDL_Guard();

    SDL_Guard& operator=(SDL_Guard& other) = delete;
    SDL_Guard& operator=(SDL_Guard&& other) = delete;
};

#endif