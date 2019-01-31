#include "catch.hpp"
#include "constants.h"

#include "renderer.h"

TEST_CASE("Renderer Single Argument Constructor")
{
    Window window("Test Case!", NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);

    SECTION("Renderer can be constructed with a bitmap")
    {
        Renderer Renderer(window);

        REQUIRE(Renderer.pointer() != nullptr);
    }
}

TEST_CASE("Renderer Copy Constructor")
{
    Window window("Test Case!", NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);

    SECTION("Copy Construction results in identical classes")
    {
        Renderer first_renderer(window);
        Renderer second_renderer(first_renderer);

        REQUIRE(first_renderer.pointer() == second_renderer.pointer());

        // Check for 3 becuase the call to pointer() makes a copy of the shared pointer
        REQUIRE(first_renderer.pointer().use_count() == 3UL);
    }

    SECTION("Destroying a copy constructed Renderer doesn't destroy the original")
    {
        Renderer first_renderer(window);

        // Create a new scoped block ensure that the renderer destructor is called once
        {
            Renderer second_renderer(first_renderer);
        }

        // One for the copy of the renderer pointer, one for first_renderer
        REQUIRE(first_renderer.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Renderer Move Constructor")
{
    Window window("Test Case!", NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);

    SECTION("Move Construction with rvalue reference results in a valid Renderer")
    {
        Renderer source_renderer(window);
        Renderer destination_renderer(std::move(source_renderer));

        // Ownership of the pointer should be moved away from source_renderer
        REQUIRE(source_renderer.pointer().use_count() == 0UL);

        // Owner of the pointer should be destination_renderer
        REQUIRE(destination_renderer.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Renderer assignment operator")
{
    Window window("Test Case!", NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);

    SECTION("Use of the assignment operator results in identical objects")
    {
        Renderer first_renderer(window);
        Renderer second_renderer(window);

        REQUIRE(first_renderer.pointer() != second_renderer.pointer());
        std::shared_ptr<SDL_Renderer> pointer = first_renderer.pointer();

        // One for the copy here, and the one that belongs to first_renderer
        REQUIRE(pointer.use_count() == 2UL);

        first_renderer = second_renderer;

        REQUIRE(first_renderer.pointer() == second_renderer.pointer());

        // One for the copy only, the one in first Renderer be destroyed
        REQUIRE(pointer.use_count() == 1UL);
    }
}

TEST_CASE("Renderer move assignment operator")
{
    Window window("Test Case!", NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);

    SECTION("Use of move assignment operator results in identical objects")
    {
        Renderer source_renderer(window);
        Renderer destination_renderer(window);

        destination_renderer = std::move(source_renderer);

        // Ownership of the pointer should be moved away from source_renderer
        REQUIRE(source_renderer.pointer().use_count() == 0UL);

        // Owner of the pointer should be destination_renderer
        REQUIRE(destination_renderer.pointer().use_count() == 2UL);
    }
}

TEST_CASE("set_draw_color()")
{
    SECTION("")
    {

    }
}

TEST_CASE("clear_target()")
{
    SECTION("")
    {

    }
}

TEST_CASE("render_present()")
{
    SECTION("")
    {

    }
}