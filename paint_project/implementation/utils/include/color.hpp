#pragma once
#include <cstdint>

struct Color
{
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    std::uint8_t a;

    constexpr bool operator==(const Color& other) const
    {
        return r == other.r && g == other.g && b == other.b && a == other.a;
    }
};

inline constexpr Color BLACK       { 0,   0,   0,   255 };
inline constexpr Color WHITE       { 255, 255, 255, 255 };
inline constexpr Color RED         { 255, 0,   0,   255 };
inline constexpr Color GREEN       { 0,   255, 0,   255 };
inline constexpr Color BLUE        { 0,   0,   255, 255 };
inline constexpr Color YELLOW      { 255, 255, 0,   255 };
inline constexpr Color MAGENTA     { 255, 0,   255, 255 };
inline constexpr Color CYAN        { 0,   255, 255, 255 };
inline constexpr Color TRANSPARENT  { 0,   0,   0,   0   };