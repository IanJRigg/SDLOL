#include "catch.hpp"
#include "texture.h"

#include "renderer.h"

TEST_CASE("Texture API")
{
    static constexpr uint32_t WINDOW_WIDTH = 1920UL;
    static constexpr uint32_t WINDOW_HEIGHT  = 1080UL;

    static const std::string WINDOW_TITLE = "THIS IS A TEST CASE!";

    Window window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    Renderer renderer(window);

    SECTION("Texture's default constructor creates a texture pointer")
    {
        Texture texture(renderer);

        REQUIRE(texture.pointer() != nullptr);
    }
}