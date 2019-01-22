#include "font.h"

Font::Font(const std::string& location, const uint32_t point_size) :
    m_font_pointer(nullptr)
{
    m_font_pointer = TTF_OpenFont(location.c_str(), point_size);
}

Font::~Font()
{
    if(m_font_pointer != nullptr)
    {
        TTF_CloseFont(m_font_pointer);
        m_font_pointer = nullptr;
    }
}

TTF_Font* Font::pointer() const
{
    return m_font_pointer;
}
