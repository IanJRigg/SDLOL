#include "catch.hpp"
#include "surface.h"

TEST_CASE("Surface API")
{
    SECTION("Surface's default constructor creates a surface pointer")
    {
        Surface surface("");

        REQUIRE(surface.pointer() != nullptr);
    }
}
