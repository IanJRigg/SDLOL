#include "catch.hpp"
#include "font.h"

TEST_CASE("Font satisifies the Rule of 5")
{
    SECTION("Font's default constructor creates a font pointer")
    {
        // Font font;

        // REQUIRE(font.pointer() != nullptr);
        // REQUIRE(font.is_valid() == true);
    }

    SECTION("Font's copy constructor populates the new font, and nullifies the old font")
    {
        // Font old_font;
        // SDL_Font* old_font_pointer = old_font.pointer();

        // Font new_font(old_font);

        // REQUIRE(new_font.pointer() == old_font_pointer);
        // REQUIRE(new_font.is_valid() == true);

        // REQUIRE(old_font.pointer() == nullptr);
        // REQUIRE(old_font.is_valid() == false);
        // REQUIRE(old_font.is_invalid() == true);
    }

    SECTION("Font's move contructor populates the new font, and nullifies the old font")
    {

    }

    SECTION("Font's copy assignment operator populates the new font, and nullifies the old font")
    {
        // Font old_font;
        // Font new_font;

        // SDL_Font* old_font_pointer = old_font.pointer();

        // new_font = old_font;

        // REQUIRE(new_font.pointer() == old_font_pointer);
        // REQUIRE(new_font.is_valid() == true);

        // REQUIRE(old_font.pointer() == nullptr);
        // REQUIRE(old_font.is_valid() == false);
        // REQUIRE(old_font.is_invalid() == true);
    }

    SECTION("Font's move assignment operator populates the new font, and nullifies the old font")
    {

    }
}
