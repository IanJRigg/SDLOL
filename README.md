# SDL Object Library

SDLOL is intended to be a cross platform API for SDL, written for use in  C++.


## TODOS:
1. Test for all exceptions and see what happens
2. Find a better way to do the renderer flags (potentially in the SDL_Controller?)
3. Move the render to be a private member of the window

## Issues:
1. A bad path to the Texture constructor does nothing right now. Should be an exception.

## Ideas:
1. Window needs to be singleton-esque. Not ready to commit to a singleton though. Dependency injection may be just fine.
2. Renderer needs the same treatment as the window
