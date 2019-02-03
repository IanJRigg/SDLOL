#include "catch.hpp"
#include "constants.h"

#include "label.h"

TEST_CASE("Label's Renderer + Font + String + Color constructor")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);
    Font font(TEST_FONT, 32UL);
    SDL_Color black = { 0x00U, 0x00U, 0x00U, 0x00U };

    SECTION("Label can be constructed with a bitmap")
    {
        Label label(renderer, font, ASCII_TEST_STRING, black);

        REQUIRE(label.pointer() != nullptr);
    }

    SECTION("Label can be constructed with a PNG")
    {
        Label label(renderer, font, ASCII_TEST_STRING, black);

        REQUIRE(label.pointer() != nullptr);
    }
}

TEST_CASE("Label Copy Constructor")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);
    Font font(TEST_FONT, 32UL);
    SDL_Color black = { 0x00U, 0x00U, 0x00U, 0x00U };

    SECTION("Copy construction results in identical classes")
    {
        Label first_label(renderer, font, ASCII_TEST_STRING, black);
        Label second_label(first_label);

        REQUIRE(first_label.pointer() == second_label.pointer());

        // Check for 3 becuase pointer() makes a copy of the shared pointer
        REQUIRE(first_label.pointer().use_count() == 3UL);

    }

    SECTION("Destroying a copy constructed label doesn't destroy the original")
    {
        Label first_label(renderer, font, ASCII_TEST_STRING, black);

        // Create a new scoped block ensure that the label destructor is called once
        {
            Label second_label(first_label);
        }

        // Check for 2 because pointer() makes a copy of the shared pointer
        REQUIRE(first_label.pointer().use_count() == 2UL);
    }
}

TEST_CASE("Label Move Constructor")
{
    Window window(WINDOW_TITLE, NINETEEN_TWENTY_PIXELS, ONE_THOUSDAND_EIGHTY_PIXELS);
    Renderer renderer(window);
    Font font(TEST_FONT, 32UL);
    SDL_Color black = { 0x00U, 0x00U, 0x00U, 0x00U };

    SECTION("Move Construction with rvalue reference results in a valid Label")
    {
        Label source_label(renderer, font, ASCII_TEST_STRING, black);
        Label destination_label(std::move(source_label));

        // Ownership of the pointer should be moved away from source_label
        REQUIRE(source_label.pointer().use_count() == 0UL);

        // Owner of the pointer should be destination_label
        REQUIRE(destination_label.pointer().use_count() == 2UL);
    }
}