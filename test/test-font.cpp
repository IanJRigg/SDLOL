#include "catch.hpp"
#include "font.h"

TEST_CASE("Font API")
{
    SECTION("Font's default constructor creates a font pointer")
    {
        Font font("", 28UL);

        REQUIRE(font.pointer() != nullptr);
    }
}
