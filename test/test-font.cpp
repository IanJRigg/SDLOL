#include "catch.hpp"
#include "constants.h"

#include "font.h"
#include "sdl-controller.h"

SDL_Controller sdl_controller;

TEST_CASE("Font Location + size constructor")
{
    SECTION("Font's default constructor creates a font pointer")
    {
        Font font(TEST_FONT, 32UL);

        REQUIRE(font.pointer() != nullptr);
    }

    SECTION("Construction with a bad path results in a SDLOL Exception")
    {
        REQUIRE_THROWS(Font("", 0UL));
    }
}

TEST_CASE("Font Copy Constructor")
{
    SECTION("Copy Construction results in identical classes")
    {
        Font first_font(TEST_FONT, 32UL);
        Font second_font(first_font);

        REQUIRE(first_font.pointer() == second_font.pointer());

        // Check for 3 becuase to pointer() makes a copy of the shared pointer
        REQUIRE(first_font.pointer().use_count() == 3UL);
    }

    SECTION("Destroying a copy constructed font doesn't destroy the original")
    {
        Font first_font(TEST_FONT, 32UL);

        // Create a new scoped block ensure that the font destructor is called once
        {
            Font second_font(first_font);
        }

        // Check for 2 because pointer() makes a copy of the shared pointer
        REQUIRE(first_font.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Font Move Constructor")
{
    SECTION("Move Construction with rvalue reference results in a valid Font")
    {
        Font source_font(TEST_FONT, 32UL);
        Font destination_font(std::move(source_font));

        // Ownership of the pointer should be moved away from source_font
        REQUIRE(source_font.pointer().use_count() == 0UL);


        // Owner of the pointer should be destination_font
        REQUIRE(destination_font.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Font assignment operator")
{
    SECTION("Use of the assignment operator results in identical objects")
    {
        Font first_font(TEST_FONT, 32UL);
        Font second_font(TEST_FONT, 32UL);

        REQUIRE(first_font.pointer() != second_font.pointer());
        std::shared_ptr<TTF_Font> pointer = first_font.pointer();

        // One for the copy here, and the one that belongs to first_font
        REQUIRE(pointer.use_count() == 2UL);

        first_font = second_font;

        REQUIRE(first_font.pointer() == second_font.pointer());

        // One for the copy only, the one in first font be destroyed
        REQUIRE(pointer.use_count() == 1UL);
    }
}

TEST_CASE("Font move assignment operator")
{
    SECTION("Use of move assignment operator results in identical objects")
    {
        Font source_font(TEST_FONT, 32UL);
        Font destination_font(TEST_FONT, 32UL);

        destination_font = std::move(source_font);

        // Ownership of the pointer should be moved away from source_font
        REQUIRE(source_font.pointer().use_count() == 0UL);

        // Owner of the pointer should be destination_font
        REQUIRE(destination_font.pointer().use_count() == 2UL);
    }
}