#pragma once
#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>
#include "vec2.hpp"

namespace cpml
{
    class vec3
    {
        public:
            double x;
            double y;
            double z;

        public:
            vec3() : x(0.0), y(0.0), z(0.0) {}
            template <typename T> vec3(T X) : x((double)X), y((double)X), z((double)X) {}
            template <typename T> vec3(vec2 a, T Z) : x(a.x), y(a.y), z((double)Z) {}
            template <typename T, typename U, typename O> vec3(T X, U Y, O Z) : x((double)X), y((double)Y), z((double)Z) {}

            vec3 operator-() const
            {
                return vec3(-this->x, -this->y, -this->z);
            }

            vec3& operator+=(const vec3& a)
            {
                this->x += a.x;
                this->y += a.y;
                this->z += a.z;
                return *this;
            }

            vec3& operator-=(const vec3& a)
            {
                this->x -= a.x;
                this->y -= a.y;
                this->z -= a.z;
                return *this;
            }

            vec3& operator*=(const vec3& a)
            {
                this->x *= a.x;
                this->y *= a.y;
                this->z *= a.z;
                return *this;
            }

            vec3& operator/=(const vec3& a)
            {
                this->x /= a.x;
                this->y /= a.y;
                this->z /= a.z;
                return *this;
            }

            vec3& operator++()
            {
                this->x++;
                this->y++;
                this->z++;
                return *this;
            }

            vec3& operator--()
            {
                this->x--;
                this->y--;
                this->z--;
                return *this;
            }
    };

    std::ostream& operator<<(std::ostream &out, const vec3 &a)
    {
        out << a.x << ", " << a.y << ", "<< a.z;
        return out;
    }

    bool operator==(const vec3 a, const vec3 b)
    {
        if (a.x == b.x && a.y == b.y && a.z == b.z)
            return true;
            
        return false;
    }

    bool operator!=(const vec3 a, const vec3 b)
    {
        if (a.x == b.x && a.y == b.y && a.z == b.z)
            return false;
        
        return true;
    }

    vec3 operator+(const vec3 a, const vec3 b)
    {
        return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    vec3 operator-(const vec3 a, const vec3 b)
    {
        return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    vec3 operator*(const vec3 a, const vec3 b)
    {
        return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
    }

    vec3 operator/(const vec3 a, const vec3 b)
    {
        return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
    }

    template <typename T> vec3 operator+(const vec3 a, const T b)
    {
        return vec3(a.x + b, a.y + b, a.z + b);
    }

    template <typename T> vec3 operator-(const vec3 a, const T b)
    {
        return vec3(a.x - b, a.y - b, a.z - b);
    }
    
    template <typename T> vec3 operator*(const vec3 a, const T b)
    {
        return vec3(a.x * b, a.y * b, a.z * b);
    }

    template <typename T> vec3 operator/(const vec3 a, const T b)
    {
        return vec3(a.x / b, a.y / b, a.z / b);
    }
} // namespace cpml

#endif // VEC3_HPP