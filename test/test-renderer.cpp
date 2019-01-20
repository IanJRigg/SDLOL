#include "catch.hpp"
#include "renderer.h"

TEST_CASE("Renderer satisifies the Rule of 5")
{
    Window window; // Needed for normal contstruction

    SECTION("Renderer's single argument constructor creates a renderer pointer")
    {
        Renderer renderer(window);

        REQUIRE(renderer.pointer() != nullptr);
        REQUIRE(renderer.is_valid() == true);
    }

    SECTION("Renderer's copy constructor populates the new renderer, and nullifies the old renderer")
    {
        Renderer old_renderer(window);
        SDL_Renderer* old_renderer_pointer = old_renderer.pointer();

        Renderer new_renderer(old_renderer);

        REQUIRE(new_renderer.pointer() == old_renderer_pointer);
        REQUIRE(new_renderer.is_valid() == true);

        REQUIRE(old_renderer.pointer() == nullptr);
        REQUIRE(old_renderer.is_valid() == false);
        REQUIRE(old_renderer.is_invalid() == true);
    }

    SECTION("Renderer's move contructor populates the new renderer, and nullifies the old renderer")
    {

    }

    SECTION("Renderer's copy assignment operator populates the new renderer, and nullifies the old renderer")
    {
        Renderer old_renderer(window);
        Renderer new_renderer(window);

        SDL_Renderer* old_renderer_pointer = old_renderer.pointer();

        new_renderer = old_renderer;

        REQUIRE(new_renderer.pointer() == old_renderer_pointer);
        REQUIRE(new_renderer.is_valid() == true);

        REQUIRE(old_renderer.pointer() == nullptr);
        REQUIRE(old_renderer.is_valid() == false);
        REQUIRE(old_renderer.is_invalid() == true);
    }

    SECTION("Renderer's move assignment operator populates the new renderer, and nullifies the old renderer")
    {

    }
}