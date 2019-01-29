#include "catch.hpp"
#include "constants.h"

#include "surface.h"
#include "exception.h"

TEST_CASE("Surface Contructors")
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

        surface = surface.pointer().get();

        REQUIRE(surface.pointer() != nullptr);

        REQUIRE(surface.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(surface.width()  == TWO_HUNDRED_PIXELS);
    }

    SECTION("Construction with a bad path results in a SDLOL Runtime Exception")
    {
        REQUIRE_THROWS(Surface(""));
    }

    SECTION("Copy Construction results in identical classes")
    {
        Surface first_surface(TEST_PNG_200X200_WHITE);
        Surface second_surface(first_surface);

        REQUIRE(first_surface.pointer() == second_surface.pointer());

        // Check for 3 becuase the call to pointer() makes a copy of the shared pointer
        REQUIRE(first_surface.pointer().use_count() == 3UL);
    }

    SECTION("Destroying a copy constructed surface doesn't destroy the original")
    {
        Surface first_surface(TEST_PNG_200X200_WHITE);

        {
            Surface second_surface(first_surface);
        }

        REQUIRE(first_surface.pointer().use_count() == 2UL);
    }
}
