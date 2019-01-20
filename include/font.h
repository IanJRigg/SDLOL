#ifndef FONT_H
#define FONT_H

#include <SDL_ttf.h>
#include <cstdint>
#include <string>

class Font
{
public:
    Font() = delete;
    Font(const std::string& location, const uint32_t point_size);
    Font(Font& other);
    Font(Font&& other);
    virtual ~Font();

    Font& operator=(Font& other);
    Font& operator=(Font&& other);

    // Accessors
    TTF_Font* pointer() const;

    // Utility Functions
    bool is_valid() const;
    bool is_invalid() const;

private:
    void deallocate();
    void nullify();

private:
    TTF_Font* m_font_pointer;
};

#endif