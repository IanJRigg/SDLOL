#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <cstdint>

static const std::string PATH_TO_INVALID_FILE = "";

static const std::string TEST_BMP_200X200_WHITE = "./test-media/test-200x200-white.bmp";
static const std::string TEST_PNG_200X200_WHITE = "./test-media/test-200x200-white.png";

static const std::string TEST_BMP_400X400_WHITE = "./test-media/test-400x400-white.bmp";
static const std::string TEST_PNG_400X400_WHITE = "./test-media/test-400x400-white.png";

static const std::string TEST_FONT = "./test-media/test.ttf";

static const std::string WINDOW_TITLE = "THIS IS A TEST CASE!";

static const std::string ASCII_TEST_STRING = " !\"#$%&\'()*+,-./0123456789:;<=>?"
                                             "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
                                             "`abcdefghijklmnopqrstuvwxyz{|}~";

static constexpr uint32_t ZERO_PIXELS = 0UL;

static constexpr uint32_t TWO_HUNDRED_PIXELS = 200UL;
static constexpr uint32_t FOUR_HUNDRED_PIXELS = 400UL;

static constexpr uint32_t NINETEEN_TWENTY_PIXELS = 1920UL;
static constexpr uint32_t ONE_THOUSDAND_EIGHTY_PIXELS = 1080UL;

#endif