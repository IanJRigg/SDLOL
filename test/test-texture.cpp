#include "catch.hpp"
#include "constants.h"

#include "texture.h"
#include "renderer.h"

TEST_CASE("Texture API")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);

    SECTION("Texture's constructor creates a texture pointer")
    {

    }
}