#include "catch.hpp"
#include "window.h"

TEST_CASE("Window API")
{
    static constexpr uint32_t WINDOW_WIDTH = 1920UL;
    static constexpr uint32_t WINDOW_HEIGHT  = 1080UL;

    static const std::string WINDOW_TITLE = "THIS IS A TEST CASE!";

    SECTION("Window's default constructor creates a window pointer")
    {
        Window window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

        REQUIRE(window.pointer() != nullptr);
        REQUIRE(window.title() == WINDOW_TITLE);
        REQUIRE(window.width() == WINDOW_WIDTH);
        REQUIRE(window.height() == WINDOW_HEIGHT);
    }
}