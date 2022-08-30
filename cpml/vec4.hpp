#pragma once
#ifndef VEC4_HPP
#define VEC4_HPP

#include <iostream>
#include "vec2.hpp"
#include "vec3.hpp"

namespace cpml
{
    class vec4
    {
        public:
            double x;
            double y;
            double z;
            double w;

        public:
            vec4() : x(0.0), y(0.0), z(0.0), w(0.0) {}
            template <typename T> vec4(T X) : x((double)X), y((double)X), z((double)X), w((double)X) {}
            template <typename T> vec4(vec3 a, T W) : x(a.x), y(a.y), z(a.z), w((double)W) {}
            vec4(vec2 a, vec2 b) : x(a.x), y(a.y), z(b.x), w(b.y) {}
            template <typename T, typename U, typename O, typename S> vec4(T X, U Y, O Z, S W) : x((double)X), y((double)Y), z((double)Z), w((double)W) {}

            vec4 operator-() const
            {
                return vec4(-this->x, -this->y, -this->z, -this->w);
            }

            vec4& operator+=(const vec4& a)
            {
                this->x += a.x;
                this->y += a.y;
                this->z += a.z;
                this->w += a.w;
                return *this;
            }

            vec4& operator-=(const vec4& a)
            {
                this->x -= a.x;
                this->y -= a.y;
                this->z -= a.z;
                this->w -= a.w;
                return *this;
            }

            vec4& operator*=(const vec4& a)
            {
                this->x *= a.x;
                this->y *= a.y;
                this->z *= a.z;
                this->w *= a.w;
                return *this;
            }

            vec4& operator/=(const vec4& a)
            {
                this->x /= a.x;
                this->y /= a.y;
                this->z /= a.z;
                this->w /= a.w;
                return *this;
            }

    };

    std::ostream& operator<<(std::ostream &out, const vec4 &a)
    {
        out << a.x << ", " << a.y << ", "<< a.z << ", " << a.w;
        return out;
    }

    vec4 operator+(const vec4 a, const vec4 b)
    {
        return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
    }

    vec4 operator-(const vec4 a, const vec4 b)
    {
        return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    }

    vec4 operator*(const vec4 a, const vec4 b)
    {
        return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
    }

    vec4 operator/(const vec4 a, const vec4 b)
    {
        return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
    }

    template <typename T> vec4 operator+(const vec4 a, const T b)
    {
        return vec4(a.x + b, a.y + b, a.z + b, a.w + b);
    }

    template <typename T> vec4 operator-(const vec4 a, const T b)
    {
        return vec4(a.x - b, a.y - b, a.z - b, a.w - b);
    }
    
    template <typename T> vec4 operator*(const vec4 a, const T b)
    {
        return vec4(a.x * b, a.y * b, a.z * b, a.w * b);
    }

    template <typename T> vec4 operator/(const vec4 a, const T b)
    {
        return vec4(a.x / b, a.y / b, a.z / b, a.w / b);
    }
} // namespace cpml

#endif // VEC4_HPP