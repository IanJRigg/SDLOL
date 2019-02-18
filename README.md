# SDL Object Library

SDLOL is intended to be a cross platform API for SDL, written for use in  C++.


## TODOS:
1. Test for all exceptions and see what happens
2. Find a better way to do the renderer flags (potentially in the SDL_Controller?)
3. Need to add world coordinates
4. Need to add a camera mechanism
5. Need to add a scene object class
6. Need to add a scene graph class
7. Need to find out if scaling textures is possible, and if it requires an alternative library to accomplish it.
8. Look into importing GLm for math functions

## Issues:
1. A bad path to the Texture constructor does nothing right now. Should be an exception.

## Ideas:
1. Window needs to be singleton-esque. Not ready to commit to a singleton though. Dependency injection may be just fine.
2. Renderer needs the same treatment as the window
