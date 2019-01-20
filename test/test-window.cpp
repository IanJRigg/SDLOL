#include "catch.hpp"
#include "window.h"

TEST_CASE("Window satisifies the Rule of 5")
{
    SECTION("Window's default constructor creates a window pointer")
    {
        Window window;

        REQUIRE(window.pointer() != nullptr);
        REQUIRE(window.is_valid() == true);
    }

    SECTION("Window's copy constructor populates the new window, and nullifies the old window")
    {
        Window old_window;
        SDL_Window* old_window_pointer = old_window.pointer();

        Window new_window(old_window);

        REQUIRE(new_window.pointer() == old_window_pointer);
        REQUIRE(new_window.is_valid() == true);

        REQUIRE(old_window.pointer() == nullptr);
        REQUIRE(old_window.is_valid() == false);
        REQUIRE(old_window.is_invalid() == true);
    }

    SECTION("Window's move contructor populates the new window, and nullifies the old window")
    {

    }

    SECTION("Window's copy assignment operator populates the new window, and nullifies the old window")
    {
        Window old_window;
        Window new_window;

        SDL_Window* old_window_pointer = old_window.pointer();

        new_window = old_window;

        REQUIRE(new_window.pointer() == old_window_pointer);
        REQUIRE(new_window.is_valid() == true);

        REQUIRE(old_window.pointer() == nullptr);
        REQUIRE(old_window.is_valid() == false);
        REQUIRE(old_window.is_invalid() == true);
    }

    SECTION("Window's move assignment operator populates the new window, and nullifies the old window")
    {

    }
}