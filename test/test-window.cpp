#include "catch.hpp"
#include "constants.h"

#include "window.h"

TEST_CASE("Window Single Argument Constructor")
{
    SECTION("Window can be constructed with a bitmap")
    {
        Window window("Test Case!",
                      NINETEEN_TWENTY_PIXELS,
                      ONE_THOUSDAND_EIGHTY_PIXELS);

        REQUIRE(window.pointer().get() != nullptr);
        REQUIRE(window.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Window Copy Constructor")
{
    SECTION("Copy Construction results in identical classes")
    {
        Window first_window("Test Case!",
                            NINETEEN_TWENTY_PIXELS,
                            ONE_THOUSDAND_EIGHTY_PIXELS);

        Window second_window(first_window);

        REQUIRE(first_window.pointer() == second_window.pointer());

        // Check for 3 becuase the call to pointer() makes a copy of the shared pointer
        REQUIRE(first_window.pointer().use_count() == 3UL);

        REQUIRE(first_window.title()  == second_window.title());
        REQUIRE(first_window.height() == second_window.height());
        REQUIRE(first_window.width()  == second_window.width());
    }

    SECTION("Destroying a copy constructed Window doesn't destroy the original")
    {
        Window first_window("Test Case!",
                            NINETEEN_TWENTY_PIXELS,
                            ONE_THOUSDAND_EIGHTY_PIXELS);

        // Create a new scoped block ensure that the window destructor is called once
        {
            Window second_window(first_window);
        }

        // One for the copy of the window pointer, one for first_window
        REQUIRE(first_window.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Window Move Constructor")
{
    SECTION("Move Construction with rvalue reference results in a valid Window")
    {
        Window source_window("Test Case!",
                             NINETEEN_TWENTY_PIXELS,
                             ONE_THOUSDAND_EIGHTY_PIXELS);
        Window destination_window(std::move(source_window));

        // Ownership of the pointer should be moved away from source_window
        REQUIRE(source_window.pointer().use_count() == 0UL);

        // Owner of the pointer should be destination_window
        REQUIRE(destination_window.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Window assignment operator")
{
    SECTION("Use of the assignment operator results in identical objects")
    {
        Window first_window("First Test Case!",
                            NINETEEN_TWENTY_PIXELS,
                            ONE_THOUSDAND_EIGHTY_PIXELS);

        Window second_window("Second Test Case!",
                             NINETEEN_TWENTY_PIXELS,
                             ONE_THOUSDAND_EIGHTY_PIXELS);

        REQUIRE(first_window.pointer() != second_window.pointer());
        std::shared_ptr<SDL_Window> pointer = first_window.pointer();

        // One for the copy here, and the one that belongs to first_window
        REQUIRE(pointer.use_count() == 2UL);

        first_window = second_window;

        REQUIRE(first_window.pointer() == second_window.pointer());

        // One for the copy only, the one in first Window be destroyed
        REQUIRE(pointer.use_count() == 1UL);
    }
}

TEST_CASE("Window move assignment operator")
{
    SECTION("Use of move assignment operator results in identical objects")
    {
        Window source_window("First Test Case!",
                             NINETEEN_TWENTY_PIXELS,
                             ONE_THOUSDAND_EIGHTY_PIXELS);

        Window destination_window("Second Test Case!",
                                  NINETEEN_TWENTY_PIXELS,
                                  ONE_THOUSDAND_EIGHTY_PIXELS);

        destination_window = std::move(source_window);

        // Ownership of the pointer should be moved away from source_window
        REQUIRE(source_window.pointer().use_count() == 0UL);

        // Owner of the pointer should be destination_window
        REQUIRE(destination_window.pointer().use_count() == 2UL);
    }
}

TEST_CASE("update()")
{
    SECTION("")
    {

    }
}
