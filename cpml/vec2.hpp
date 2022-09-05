#pragma once
#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>

namespace cpml
{
    class vec2
    {
        public:
            double x;
            double y;

        public:
            vec2() : x(0.0), y(0.0) {}
            template <typename T> vec2(T X) : x((double)X), y((double)X) {}
            template <typename T, typename U> vec2(T X, U Y) : x((double)X), y((double)Y) {}

            vec2 operator-() const
            {
                return vec2(-this->x, -this->y);
            }

            vec2& operator+=(const vec2& a)
            {
                this->x += a.x;
                this->y += a.y;
                return *this;
            }

            vec2& operator-=(const vec2& a)
            {
                this->x -= a.x;
                this->y -= a.y;
                return *this;
            }

            vec2& operator*=(const vec2& a)
            {
                this->x *= a.x;
                this->y *= a.y;
                return *this;
            }

            vec2& operator/=(const vec2& a)
            {
                this->x /= a.x;
                this->y /= a.y;
                return *this;
            }

            vec2& operator++()
            {
                this->x++;
                this->y++;
                return *this;
            }

            vec2& operator--()
            {
                this->x--;
                this->y--;
                return *this;
            }
    };

    std::ostream& operator<<(std::ostream &out, const vec2 &a)
    {
        out << a.x << ", " << a.y;
        return out;
    }

    bool operator==(const vec2 a, const vec2 b)
    {
        if (a.x == b.x && a.y == b.y)
            return true;

        return false;
    }

    bool operator!=(const vec2 a, const vec2 b)
    {
        if (a.x == b.x && a.y == b.y)
            return false;
        
        return true;
    }

    vec2 operator+(const vec2 a, const vec2 b)
    {
        return vec2(a.x + b.x, a.y + b.y);
    }

    vec2 operator-(const vec2 a, const vec2 b)
    {
        return vec2(a.x - b.x, a.y - b.y);
    }

    vec2 operator*(const vec2 a, const vec2 b)
    {
        return vec2(a.x * b.x, a.y * b.y);
    }

    vec2 operator/(const vec2 a, const vec2 b)
    {
        return vec2(a.x / b.x, a.y / b.y);
    }

    template <typename T> vec2 operator+(const vec2 a, const T b)
    {
        return vec2(a.x + b, a.y + b);
    }

    template <typename T> vec2 operator-(const vec2 a, const T b)
    {
        return vec2(a.x - b, a.y - b);
    }
    
    template <typename T> vec2 operator*(const vec2 a, const T b)
    {
        return vec2(a.x * b, a.y * b);
    }

    template <typename T> vec2 operator/(const vec2 a, const T b)
    {
        return vec2(a.x / b, a.y / b);
    }
} // namespace cpml

#endif // VEC2_HPP