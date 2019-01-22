#include "catch.hpp"
#include "renderer.h"

TEST_CASE("Renderer API")
{
    Window window("Test Case!", 1920UL, 1080UL); // Needed for normal contstruction

    SECTION("Renderer's single argument constructor")
    {
        Renderer renderer(window);

        REQUIRE(renderer.pointer() != nullptr);
    }

    SECTION("Default state of the renderer flags is disable")
    {
        Renderer renderer(window);

        REQUIRE(renderer.pointer() != nullptr);
        REQUIRE(renderer.options_mask() == 0UL);

        Renderer::Enable_VSYNC();
        Renderer::Enable_Hardware_Acceleration();

        REQUIRE(renderer.options_mask() == 0UL);
    }

    SECTION("Enabling VSYNC and HW Acceleration changes the flags")
    {
        Renderer::Enable_VSYNC();
        Renderer::Enable_Hardware_Acceleration();

        Renderer renderer(window);

        REQUIRE(renderer.pointer() != nullptr);
        REQUIRE(renderer.options_mask() == (SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
    }

    SECTION("Enabling and then disabling VSYNC and HW Acceleration returns to the original state")
    {
        Renderer::Enable_VSYNC();
        Renderer::Enable_Hardware_Acceleration();

        Renderer::Disable_VSYNC();
        Renderer::Disable_Hardware_Acceleration();

        Renderer renderer(window);

        REQUIRE(renderer.pointer() != nullptr);
        REQUIRE(renderer.options_mask() == 0UL);

        Renderer::Enable_VSYNC();
        Renderer::Enable_Hardware_Acceleration();

        REQUIRE(renderer.options_mask() == 0UL);
    }
}