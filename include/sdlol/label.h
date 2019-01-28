#include "texture.h"
#include "font.h"

class Label : public Texture
{
public:
    Label() = delete;
    Label(Label& other) = delete;
    Label(Label&& other) noexcept = delete;

    Label& operator=(Label& other) = delete;
    Label& operator=(Label&& other) noexcept = delete;

    Label(Renderer& renderer,
          Font& font,
          const std::string& text,
          const SDL_Color& color);
    virtual ~Label();

    void load(const std::string& text);

    void set_font(Font& font);
    void set_color(SDL_Color& color);

private:

private:
    Font& m_font;
    SDL_Color m_color;
};