#include "sprite.h"

#include <SDL_image.h>

Sprite::Sprite(Renderer& renderer, const std::string& path_to_image) :
    Texture(renderer)
{
    load_image(path_to_image);
}

Sprite::~Sprite()
{

}

void Sprite::load_image(const std::string& path_to_image)
{
    Surface surface(IMG_Load(path_to_image.c_str()));

    SDL_Color color = { 0x00U, 0xFFU, 0xFFU, 0x00U};
    surface.set_color_key(color);

    load_surface(surface);
}
