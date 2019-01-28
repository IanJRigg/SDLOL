#include "catch.hpp"
#include "constants.h"

#include "surface.h"

TEST_CASE("Surface API")
{
    SECTION("Surface can be constructed with a bitmap")
    {
        Surface surface(TEST_BMP_200X200_WHITE);

        REQUIRE(surface.pointer() != nullptr);

        REQUIRE(surface.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(surface.width()  == TWO_HUNDRED_PIXELS);
    }

    SECTION("Surface can be constructed with a PNG")
    {
        Surface surface(TEST_PNG_200X200_WHITE);

        REQUIRE(surface.pointer() != nullptr);

        REQUIRE(surface.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(surface.width()  == TWO_HUNDRED_PIXELS);
    }

    SECTION("Self construction doesn't deallocate the SDL_Surface")
    {
        Surface surface(TEST_PNG_200X200_WHITE);

        surface = surface.pointer();

        REQUIRE(surface.pointer() != nullptr);

        REQUIRE(surface.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(surface.width()  == TWO_HUNDRED_PIXELS);
    }
}
