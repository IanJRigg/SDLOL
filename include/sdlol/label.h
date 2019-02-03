#include "texture.h"
#include "font.h"

class Label : public Texture
{
public:
    Label() = delete;
    Label(const Label& other) = default;
    Label(Label&& other) noexcept = default;

    Label& operator=(const Label& other) = delete;
    Label& operator=(Label&& other) noexcept = delete;

    virtual ~Label() = default;

    Label(Renderer& renderer,
          Font& font,
          const std::string& text,
          const SDL_Color& color);

    void set_text(const std::string& text);
    void set_color(const SDL_Color& color);

private:
    Font& m_font;
    SDL_Color m_color;
};
