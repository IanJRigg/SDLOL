#include "texture.h"

class Sprite : public Texture
{
public:
    Sprite() = delete;
    Sprite(Sprite& other) = delete;
    Sprite(Sprite&& other) noexcept = delete;

    Sprite& operator=(Sprite& other) = delete;
    Sprite& operator=(Sprite&& other) noexcept = delete;

    Sprite(Renderer& renderer, const std::string& path_to_image);
    virtual ~Sprite();

    void load_image(const std::string& path_to_image);
};