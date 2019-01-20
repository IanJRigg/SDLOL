#include "font.h"

Font::Font(const std::string& location, const uint32_t point_size) :
    m_font_pointer(nullptr)
{
    m_font_pointer = TTF_OpenFont(location.c_str(), point_size);
}

Font::Font(Font& other) :
    m_font_pointer(other.pointer())
{
    other.nullify();
}

Font::Font(Font&& other) :
    m_font_pointer(other.pointer())
{
    other.nullify();
}

Font::~Font()
{
    deallocate();
}

Font& Font::operator=(Font& other)
{
    if(this != &other)
    {
        deallocate();

        m_font_pointer = other.m_font_pointer;

        other.nullify();
    }

    return *this;
}

Font& Font::operator=(Font&& other)
{
    if(this != &other)
    {
        deallocate();

        m_font_pointer = other.m_font_pointer;

        other.nullify();
    }

    return *this;
}

TTF_Font* Font::pointer() const
{
    return m_font_pointer;
}

bool Font::is_valid() const
{
    return (m_font_pointer != nullptr);
}

bool Font::is_invalid() const
{
    return !is_valid();
}

void Font::deallocate()
{
    if(m_font_pointer != nullptr)
    {
        TTF_CloseFont(m_font_pointer);
        nullify();
    }
}

void Font::nullify()
{
    m_font_pointer = nullptr;
}