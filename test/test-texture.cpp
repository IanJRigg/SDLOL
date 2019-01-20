#include "catch.hpp"
#include "texture.h"

TEST_CASE("Texture satisifies the Rule of 5")
{
    SECTION("Texture's default constructor creates a texture pointer")
    {
        // Texture texture;

        // REQUIRE(texture.pointer() != nullptr);
        // REQUIRE(texture.is_valid() == true);
    }

    SECTION("Texture's copy constructor populates the new texture, and nullifies the old texture")
    {
        // Texture old_texture;
        // SDL_Texture* old_texture_pointer = old_texture.pointer();

        // Texture new_texture(old_texture);

        // REQUIRE(new_texture.pointer() == old_texture_pointer);
        // REQUIRE(new_texture.is_valid() == true);

        // REQUIRE(old_texture.pointer() == nullptr);
        // REQUIRE(old_texture.is_valid() == false);
        // REQUIRE(old_texture.is_invalid() == true);
    }

    SECTION("Texture's move contructor populates the new texture, and nullifies the old texture")
    {

    }

    SECTION("Texture's copy assignment operator populates the new texture, and nullifies the old texture")
    {
        // Texture old_texture;
        // Texture new_texture;

        // SDL_Texture* old_texture_pointer = old_texture.pointer();

        // new_texture = old_texture;

        // REQUIRE(new_texture.pointer() == old_texture_pointer);
        // REQUIRE(new_texture.is_valid() == true);

        // REQUIRE(old_texture.pointer() == nullptr);
        // REQUIRE(old_texture.is_valid() == false);
        // REQUIRE(old_texture.is_invalid() == true);
    }

    SECTION("Texture's move assignment operator populates the new texture, and nullifies the old texture")
    {

    }
}