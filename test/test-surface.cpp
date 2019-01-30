#include "catch.hpp"
#include "constants.h"

#include "surface.h"
#include "exception.h"

#include <SDL_image.h>
#include <iostream>

TEST_CASE("Surface Single Argument String Constructor")
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

    SECTION("Construction with a bad path results in a SDLOL Runtime Exception")
    {
        REQUIRE_THROWS(Surface(""));
    }
}

TEST_CASE("Surface Single argument pointer constructor")
{
    SECTION("Construction with a valid pointer results in a valid object")
    {
        Surface original_surface(TEST_PNG_200X200_WHITE);
        Surface copied_surface(IMG_Load(TEST_PNG_200X200_WHITE.c_str()));

        REQUIRE(copied_surface.pointer() != nullptr);

        REQUIRE(copied_surface.height() == original_surface.height());
        REQUIRE(copied_surface.width()  == original_surface.width());

        std::cout << "Finished with the valid pointer test" << std::endl;
    }

    SECTION("Construction with nullptr results a dimmensions of 0x0")
    {
        Surface surface(nullptr);

        REQUIRE(surface.pointer().get() == nullptr);

        REQUIRE(surface.height() == ZERO_PIXELS);
        REQUIRE(surface.width()  == ZERO_PIXELS);
    }
}

TEST_CASE("Surface Copy Constructor")
{
    SECTION("Copy Construction results in identical classes")
    {
        Surface first_surface(TEST_PNG_200X200_WHITE);
        Surface second_surface(first_surface);

        REQUIRE(first_surface.pointer() == second_surface.pointer());

        REQUIRE(first_surface.height() == second_surface.height());
        REQUIRE(first_surface.width()  == second_surface.width());

        // Check for 3 becuase the call to pointer() makes a copy of the shared pointer
        REQUIRE(first_surface.pointer().use_count() == 3UL);
    }

    SECTION("Destroying a copy constructed surface doesn't destroy the original")
    {
        Surface first_surface(TEST_PNG_200X200_WHITE);

        // Create a new scoped block ensure that the surface destructor is called once
        {
            Surface second_surface(first_surface);
        }

        // Check for 2 becuase the call to pointer() makes a copy of the shared pointer
        REQUIRE(first_surface.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Surface assignment operator")
{
    SECTION("Use of the assignment operator results in identical objects")
    {
        Surface first_surface(TEST_BMP_200X200_WHITE);
        Surface second_surface(TEST_PNG_200X200_WHITE);

        REQUIRE(first_surface.pointer() != second_surface.pointer());
        auto pointer = first_surface.pointer();

        // One for the copy here, and the one that belongs to first_surface
        REQUIRE(pointer.use_count() == 2UL);

        first_surface = second_surface;

        REQUIRE(first_surface.pointer() == second_surface.pointer());

        // One for the copy only, the one in first surface be destroyed
        REQUIRE(pointer.use_count() == 1UL);
    }
}

TEST_CASE("Surface API")
{
    SECTION("Bounds check: load_image()")
    {

    }

    SECTION("Bounds check: set_color_key()")
    {

    }

    SECTION("Bounds check: blit()")
    {

    }
}
