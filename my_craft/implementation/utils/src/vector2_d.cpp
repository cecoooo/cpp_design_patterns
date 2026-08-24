#include "vector_2d.hpp"
#include "math.h"


Vector2D::Vector2D(float  x, float  y): X(x), Y(y){}

Vector2D::Vector2D(const Vector2D& other) : X(other.X), Y(other.Y) {}

Vector2D::Vector2D(Vector2D&& other) noexcept : X(other.X), Y(other.Y) {}

float  Vector2D::x() const
{
    return X;
}

float  Vector2D::y() const
{
    return Y;
}

float Vector2D::distance(const Vector2D& other) const
{
    float dx = static_cast<float>(X - other.X);
    float dy = static_cast<float>(Y - other.Y);
    return std::sqrt(dx * dx + dy * dy);
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(X + other.X, Y + other.Y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(X - other.X, Y - other.Y);
}

Vector2D Vector2D::operator*(float  scalar) const {
    return Vector2D(X * scalar, Y * scalar);
}

Vector2D Vector2D::operator/(float  scalar) const {
    if (scalar == 0) return *this;
    return Vector2D(X / scalar, Y / scalar);
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    X += other.X;
    Y += other.Y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    X -= other.X;
    Y -= other.Y;
    return *this;
}

Vector2D& Vector2D::operator*=(float  scalar) {
    X *= scalar;
    Y *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(float  scalar) {
    if (scalar != 0) {
        X /= scalar;
        Y /= scalar;
    }
    return *this;
}

Vector2D& Vector2D::operator=(const Vector2D& other) {
    if (this != &other) {
        X = other.X;
        Y = other.Y;
    }
    return *this;
}


Vector2D& Vector2D::operator=(Vector2D&& other) noexcept {
    if (this != &other) {
        X = other.X;
        Y = other.Y;
    }
    return *this;
}

bool Vector2D::operator==(const Vector2D& other) const {
    return X == other.X && Y == other.Y;
}

bool Vector2D::operator!=(const Vector2D& other) const {
    return !(*this == other);
}

bool Vector2D::operator<(const Vector2D& other) const {
    return distance(Vector2D(0, 0)) < other.distance(Vector2D(0, 0));
}

bool Vector2D::operator>(const Vector2D& other) const {
    return distance(Vector2D(0, 0)) > other.distance(Vector2D(0, 0));
}

bool Vector2D::operator<=(const Vector2D& other) const {
    return *this < other || *this == other;
}

bool Vector2D::operator>=(const Vector2D& other) const {
    return *this > other || *this == other;
}