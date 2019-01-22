#ifndef FONT_H
#define FONT_H

#include <SDL_ttf.h>
#include <cstdint>
#include <string>

class Font
{
public:
    Font() = delete;
    Font(const Font& other) = delete;
    Font(Font&& other) noexcept = delete;

    Font& operator=(const Font& other) = delete;
    Font& operator=(Font&& other) noexcept = delete;

    Font(const std::string& location, const uint32_t point_size);
    virtual ~Font();

    // Accessors
    TTF_Font* pointer() const;

private:
    TTF_Font* m_font_pointer;
};

#endif