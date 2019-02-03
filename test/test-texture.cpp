#include "catch.hpp"
#include "constants.h"

#include "texture.h"
#include "renderer.h"

#include <stdexcept>

TEST_CASE("Texture's Renderer + String Constructor")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);

    SECTION("Texture can be constructed with a bitmap")
    {
        Texture texture(renderer, TEST_BMP_200X200_WHITE);

        REQUIRE(texture.pointer() != nullptr);

        REQUIRE(texture.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(texture.width()  == TWO_HUNDRED_PIXELS);
    }

    SECTION("Texture can be constructed with a PNG")
    {
        Texture texture(renderer, TEST_PNG_200X200_WHITE);

        REQUIRE(texture.pointer() != nullptr);

        REQUIRE(texture.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(texture.width()  == TWO_HUNDRED_PIXELS);
    }

    SECTION("Construction with a bad path results in SDLOL_Exception")
    {
        REQUIRE_THROWS_AS(Texture(renderer, ""), std::runtime_error);
    }
}

TEST_CASE("Texture's Renderer + Surface Constructor")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);

    SECTION("Texture can be constructed with a surface loaded with a bitmap")
    {
        Surface surface(TEST_BMP_200X200_WHITE);
        Texture texture(renderer, surface);

        REQUIRE(texture.pointer() != nullptr);

        REQUIRE(texture.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(texture.width()  == TWO_HUNDRED_PIXELS);
    }

    SECTION("Texture can be constructed with a surface loaded with a PNG")
    {
        Surface surface(TEST_PNG_200X200_WHITE);
        Texture texture(renderer, surface);

        REQUIRE(texture.pointer() != nullptr);

        REQUIRE(texture.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(texture.width()  == TWO_HUNDRED_PIXELS);
    }
}

TEST_CASE("Texture Copy Constructor")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);

    SECTION("Copy construction results in identical classes")
    {
        Texture first_texture(renderer, TEST_PNG_200X200_WHITE);
        Texture second_texture(first_texture);

        REQUIRE(first_texture.pointer() == second_texture.pointer());

        REQUIRE(first_texture.height() == second_texture.height());
        REQUIRE(first_texture.width() == second_texture.width());

        // Check for 3 becuase pointer() makes a copy of the shared pointer
        REQUIRE(first_texture.pointer().use_count() == 3UL);

    }

    SECTION("Destroying a copy constructed texture doesn't destroy the original")
    {
        Texture first_texture(renderer, TEST_PNG_200X200_WHITE);

        // Create a new scoped block ensure that the texture destructor is called once
        {
            Texture second_texture(first_texture);
        }

        // Check for 2 because pointer() makes a copy of the shared pointer
        REQUIRE(first_texture.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Texture Move Constructor")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);

    SECTION("Move Construction with rvalue reference results in a valid Texture")
    {
        Texture source_texture(renderer, TEST_PNG_200X200_WHITE);
        Texture destination_texture(std::move(source_texture));

        REQUIRE(source_texture.height() == ZERO_PIXELS);
        REQUIRE(source_texture.width()  == ZERO_PIXELS);

        // Ownership of the pointer should be moved away from source_texture
        REQUIRE(source_texture.pointer().use_count() == 0UL);

        REQUIRE(destination_texture.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(destination_texture.width()  == TWO_HUNDRED_PIXELS);

        // Owner of the pointer should be destination_texture
        REQUIRE(destination_texture.pointer().use_count() == 2UL);
    }
}

TEST_CASE("set_color_modulation() and color_modulation()")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);
    Texture texture(renderer, TEST_PNG_200X200_WHITE);

    SECTION("Set RGB to { 0, 0, 0 }")
    {
        SDL_Color input = { 0, 0, 0 };
        texture.set_color_modulation(input);

        SDL_Color result = texture.color_modulation();

        REQUIRE(result.r == input.r);
        REQUIRE(result.g == input.g);
        REQUIRE(result.b == input.b);
    }

    SECTION("Set RGB to { 255, 255, 255 }")
    {
        SDL_Color input = { 255, 255, 255 };
        texture.set_color_modulation(input);

        SDL_Color result = texture.color_modulation();

        REQUIRE(result.r == input.r);
        REQUIRE(result.g == input.g);
        REQUIRE(result.b == input.b);
    }
}

TEST_CASE("set_alpha_modulation() and alpha_modulation()")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);
    Texture texture(renderer, TEST_PNG_200X200_WHITE);

    SECTION("Set alpha of 0")
    {
        uint8_t test_alpha = 0x00U;

        texture.set_alpha_modulation(test_alpha);
        REQUIRE(texture.alpha_modulation() == test_alpha);
    }

    SECTION("Set alpha of 128")
    {
        uint8_t test_alpha = 0x80U;

        texture.set_alpha_modulation(test_alpha);
        REQUIRE(texture.alpha_modulation() == test_alpha);
    }

    SECTION("Set alpha of 255")
    {
        uint8_t test_alpha = 0xFFU;

        texture.set_alpha_modulation(test_alpha);
        REQUIRE(texture.alpha_modulation() == test_alpha);
    }
}
