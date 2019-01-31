#include "catch.hpp"
#include "constants.h"

#include "surface.h"
#include "exception.h"

#include <SDL_image.h>

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

    SECTION("Construction with a bad path results in a SDLOL Exception")
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

TEST_CASE("Surface Move Constructor")
{
    SECTION("Move Construction with rvalue reference results in a valid Surface")
    {
        Surface source_surface(TEST_PNG_200X200_WHITE);
        Surface destination_surface(std::move(source_surface));

        REQUIRE(source_surface.height() == ZERO_PIXELS);
        REQUIRE(source_surface.width()  == ZERO_PIXELS);

        // Ownership of the pointer should be moved away from source_surface
        REQUIRE(source_surface.pointer().use_count() == 0UL);

        REQUIRE(destination_surface.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(destination_surface.width()  == TWO_HUNDRED_PIXELS);

        // Owner of the pointer should be destination_surface
        REQUIRE(destination_surface.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Surface assignment operator")
{
    SECTION("Use of the assignment operator results in identical objects")
    {
        Surface first_surface(TEST_BMP_200X200_WHITE);
        Surface second_surface(TEST_PNG_200X200_WHITE);

        REQUIRE(first_surface.pointer() != second_surface.pointer());
        std::shared_ptr<SDL_Surface> pointer = first_surface.pointer();

        // One for the copy here, and the one that belongs to first_surface
        REQUIRE(pointer.use_count() == 2UL);

        first_surface = second_surface;

        REQUIRE(first_surface.pointer() == second_surface.pointer());

        // One for the copy only, the one in first surface be destroyed
        REQUIRE(pointer.use_count() == 1UL);
    }
}

TEST_CASE("Surface move assignment operator")
{
    SECTION("Use of move assignment operator results in identical objects")
    {
        Surface source_surface(TEST_PNG_200X200_WHITE);
        Surface destination_surface(nullptr);

        destination_surface = std::move(source_surface);

        REQUIRE(source_surface.height() == ZERO_PIXELS);
        REQUIRE(source_surface.width()  == ZERO_PIXELS);

        // Ownership of the pointer should be moved away from source_surface
        REQUIRE(source_surface.pointer().use_count() == 0UL);

        REQUIRE(destination_surface.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(destination_surface.width()  == TWO_HUNDRED_PIXELS);

        // Owner of the pointer should be destination_surface
        REQUIRE(destination_surface.pointer().use_count() == 2UL);
    }
}

TEST_CASE("load_image()")
{
    SECTION("load_image() doesn't throw an exception if the file exists")
    {
        Surface surface(nullptr);
        REQUIRE_NOTHROW(surface.load_image(TEST_PNG_200X200_WHITE));
    }

    SECTION("load_image() throws an exception if the file doesn't exist")
    {
        Surface surface(nullptr);
        REQUIRE_THROWS(surface.load_image(""));
    }

    SECTION("load_image() different images will change the dimmensions of the image")
    {
        Surface surface(TEST_PNG_200X200_WHITE);
        std::shared_ptr<SDL_Surface> surface_pointer = surface.pointer();

        REQUIRE(surface.height() == TWO_HUNDRED_PIXELS);
        REQUIRE(surface.width()  == TWO_HUNDRED_PIXELS);

        // One in surface, and one in surface_pointer
        REQUIRE(surface_pointer.use_count() == 2UL);

        surface.load_image(TEST_PNG_400X400_WHITE);

        REQUIRE(surface.height() == FOUR_HUNDRED_PIXELS);
        REQUIRE(surface.width()  == FOUR_HUNDRED_PIXELS);

        // Only one in surface_pointer, the one in surface should have been destroyed
        REQUIRE(surface_pointer.use_count() == 1UL);
    }
}

TEST_CASE("set_color_key()")
{
    SECTION("set_color_key() returns false when it's internal pointer is null")
    {
        Surface surface(nullptr);
        SDL_Color color = { 0x00U, 0x00U, 0x00U, 0x00U };

        REQUIRE(surface.set_color_key(color) == false);
    }
}

TEST_CASE("blit()")
{
    SECTION("blit() returns false when it's pointer is null and it's passed a null surface")
    {
        Surface first_surface(nullptr);
        Surface second_surface(nullptr);

        REQUIRE(first_surface.blit(second_surface) == false);
    }

    SECTION("blit() returns false when it's pointer is null and it's passed a valid surface")
    {
        Surface first_surface(nullptr);
        Surface second_surface(TEST_PNG_200X200_WHITE);

        REQUIRE(first_surface.blit(second_surface) == false);
    }

    SECTION("blit() returns false when it's pointer is valid and it's passed a null surface")
    {
        Surface first_surface(TEST_PNG_400X400_WHITE);
        Surface second_surface(nullptr);

        REQUIRE(first_surface.blit(second_surface) == false);
    }

    SECTION("blit() returns true when it's pointer is valid and it's passed a valid surface")
    {
        Surface first_surface(TEST_PNG_400X400_WHITE);
        Surface second_surface(TEST_PNG_200X200_WHITE);

        REQUIRE(first_surface.blit(second_surface) == true);
    }
}
