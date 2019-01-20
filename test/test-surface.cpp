#include "catch.hpp"
#include "surface.h"

TEST_CASE("Surface satisifies the Rule of 5")
{
    SECTION("Surface's default constructor creates a surface pointer")
    {
        // Surface surface;

        // REQUIRE(surface.pointer() != nullptr);
        // REQUIRE(surface.is_valid() == true);
    }

    SECTION("Surface's copy constructor populates the new surface, and nullifies the old surface")
    {
        // Surface old_surface;
        // SDL_Surface* old_surface_pointer = old_surface.pointer();

        // Surface new_surface(old_surface);

        // REQUIRE(new_surface.pointer() == old_surface_pointer);
        // REQUIRE(new_surface.is_valid() == true);

        // REQUIRE(old_surface.pointer() == nullptr);
        // REQUIRE(old_surface.is_valid() == false);
        // REQUIRE(old_surface.is_invalid() == true);
    }

    SECTION("Surface's move contructor populates the new surface, and nullifies the old surface")
    {

    }

    SECTION("Surface's copy assignment operator populates the new surface, and nullifies the old surface")
    {
        // Surface old_surface;
        // Surface new_surface;

        // SDL_Surface* old_surface_pointer = old_surface.pointer();

        // new_surface = old_surface;

        // REQUIRE(new_surface.pointer() == old_surface_pointer);
        // REQUIRE(new_surface.is_valid() == true);

        // REQUIRE(old_surface.pointer() == nullptr);
        // REQUIRE(old_surface.is_valid() == false);
        // REQUIRE(old_surface.is_invalid() == true);
    }

    SECTION("Surface's move assignment operator populates the new surface, and nullifies the old surface")
    {

    }
}
