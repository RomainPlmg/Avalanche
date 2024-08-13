#pragma once

namespace AVL {
class Color {
   public:
    /* Attributes */
    float r, g, b, a;

    constexpr Color() : r(0.0f), g(0.0f), b(0.0f), a(255.0f) {};
    constexpr Color(float r, float g, float b, float a = 255) : r(r), g(g), b(b), a(a) {};

    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
};

inline const Color Color::Black = Color(0.0f, 0.0f, 0.0f);
inline const Color Color::White = Color(255.0f, 255.0f, 255.0f);
inline const Color Color::Red = Color(255.0f, 0.0f, 0.0f);
inline const Color Color::Green = Color(0.0f, 255.0f, 0.0f);
inline const Color Color::Blue = Color(0.0f, 0.0f, 255.0f);
}  // namespace AVL