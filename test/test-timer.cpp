#include "catch.hpp"

#include "sdlol/timer.h"

#include <unistd.h>

TEST_CASE("Timer API")
{
    SECTION("Timer counts up for a duration")
    {
        Timer timer;
        timer.start();

        usleep(10000UL);

        REQUIRE(timer.current_time() >= 10UL);
    }

    SECTION("Timer doesn't count up while stopped")
    {
        Timer timer;

        usleep(10000UL);

        REQUIRE(timer.current_time() < 10UL);
    }

    SECTION("Timer doesn't count up when stopping after starting")
    {
        Timer timer;
        timer.start();

        usleep(10000UL);

        timer.stop();

        usleep(10000UL);

        REQUIRE(timer.current_time() < 20UL);
    }
}