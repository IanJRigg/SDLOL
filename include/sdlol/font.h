#ifndef FONT_H
#define FONT_H

#include <SDL_ttf.h>
#include <cstdint>
#include <string>
#include <memory>

class Font
{
public:
    Font() = delete;
    Font(const Font& other) = default;
    Font(Font&& other) noexcept = default;

    Font& operator=(const Font& other) = default;
    Font& operator=(Font&& other) noexcept = default;

    virtual ~Font() = default;

    Font(const std::string& location, const uint32_t point_size);

    // Accessors
    std::shared_ptr<TTF_Font> pointer() const;

private:
    std::shared_ptr<TTF_Font> m_font_pointer;
};

#endif