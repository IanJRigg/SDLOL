#include "label.h"

Label::Label(Renderer& renderer,
             Font& font,
             const std::string& text,
             const SDL_Color& color) :
    Texture(renderer),
    m_font(font),
    m_color(color)
{
    load(text);
}

Label::~Label()
{

}

void Label::load(const std::string& text)
{
    Surface surface(TTF_RenderText_Solid(m_font.pointer(), text.c_str(), m_color));

    SDL_Color color = { 0x00U, 0xFFU, 0xFFU, 0x00U};
    surface.set_color_key(color);

    load_surface(surface);
}

// void Label::set_font(const Font& font)
// {
//     m_font = font;
// }

// void Label::set_color(const SDL_Color& color)
// {
//     color = color;
// }
