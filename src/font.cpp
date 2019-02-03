#include "font.h"

#include <stdexcept>

static const auto DELETER_LAMBDA = [](TTF_Font* pointer) { TTF_CloseFont(pointer); };

Font::Font(const std::string& location, const uint32_t point_size) :
    m_font_pointer(nullptr)
{
    TTF_Font* font = TTF_OpenFont(location.c_str(), point_size);

    if(font == nullptr)
    {
        throw std::runtime_error("Error creating font: " + std::string(TTF_GetError()));
    }

    m_font_pointer.reset(font, DELETER_LAMBDA);
}

std::shared_ptr<TTF_Font> Font::pointer() const
{
    return m_font_pointer;
}