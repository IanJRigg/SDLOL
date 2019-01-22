#ifndef SDL_CONTROLLER_H
#define SDL_CONTROLLER_H

class SDL_Controller final
{
public:
    SDL_Controller();
    SDL_Controller(SDL_Controller& other) = delete;
    SDL_Controller(SDL_Controller&& other) = delete;
    ~SDL_Controller();

    SDL_Controller& operator=(SDL_Controller& other) = delete;
    SDL_Controller& operator=(SDL_Controller&& other) = delete;
};

#endif