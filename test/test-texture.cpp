#include "catch.hpp"
#include "constants.h"

#include "texture.h"
#include "renderer.h"

TEST_CASE("Texture API")
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

    // SECTION("Self construction doesn't deallocate the SDL_Texture")
    // {
    //     Texture texture(renderer, TEST_PNG_200X200_WHITE);

    //     texture = texture.pointer();

    //     REQUIRE(texture.pointer() != nullptr);

    //     REQUIRE(texture.height() == TWO_HUNDRED_PIXELS);
    //     REQUIRE(texture.width()  == TWO_HUNDRED_PIXELS);
    // }
}