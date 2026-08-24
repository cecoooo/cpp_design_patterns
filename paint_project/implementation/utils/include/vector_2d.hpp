#pragma once
#include <SFML/System/Vector2.hpp>
#include <cmath>

class Vector2D
{
private:
    float  X;
    float  Y;
public:
    Vector2D() = default;
    Vector2D(float  x, float  y);
    Vector2D(const Vector2D& other);
    Vector2D(Vector2D&& other) noexcept;

    float  x() const;
    float  y() const;
    float distance(const Vector2D& other) const;

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(float  scalar) const;
    Vector2D operator/(float  scalar) const;
    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator*=(float  scalar);
    Vector2D& operator/=(float  scalar);

    Vector2D& operator=(const Vector2D& other); 
    Vector2D& operator=(Vector2D&& other) noexcept;

    bool operator==(const Vector2D& other) const;
    bool operator!=(const Vector2D& other) const;
    bool operator<(const Vector2D& other) const;
    bool operator>(const Vector2D& other) const;
    bool operator<=(const Vector2D& other) const;
    bool operator>=(const Vector2D& other) const;

    operator sf::Vector2f() const;
};