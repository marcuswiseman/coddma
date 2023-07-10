#include <iostream>

class Vector3 {
public:
    float x, y, z;

    // Default constructor
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

    // Parameterized constructor
    Vector3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

    // Copy constructor
    Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {}

    // Addition operator
    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    // Subtraction operator
    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    // Scalar multiplication operator
    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    // Dot product function
    float dotProduct(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product function
    Vector3 crossProduct(const Vector3& other) const {
        return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
};

class Vector2 {
public:
    float x, y;

    // Default constructor
    Vector2() : x(0.0f), y(0.0f) {}

    // Parameterized constructor
    Vector2(float xVal, float yVal) : x(xVal), y(yVal) {}

    // Copy constructor
    Vector2(const Vector2& other) : x(other.x), y(other.y) {}

    // Addition operator
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // Subtraction operator
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    // Scalar multiplication operator
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    // Dot product function
    float dotProduct(const Vector2& other) const {
        return x * other.x + y * other.y;
    }
};