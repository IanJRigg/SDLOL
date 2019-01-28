#include "catch.hpp"
#include "constants.h"

#include "font.h"

TEST_CASE("Font API")
{
    SECTION("Font's default constructor creates a font pointer")
    {
        Font font(TEST_FONT, 28UL);

        // REQUIRE(font.pointer() != nullptr);
    }
}
