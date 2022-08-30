#pragma once
#ifndef MAT2_HPP
#define MAT2_HPP

#include <iostream>
#include "vec2.hpp"

namespace cpml
{
    class mat2
    {
        private:
            double arr[2][2];

        public:
            mat2() : arr{0.0, 0.0, 0.0, 0.0} {}

            template <typename T> mat2(T a) : arr{(double)a, (double)a, (double)a, (double)a} {}

            mat2(vec2 a, vec2 b) : arr{a.x, a.y, b.x, b.y} {}

            template <typename T> mat2(T a, T b, T c, T d) : arr{(double)a, (double)b, (double)c, (double)d} {}

            const double& operator()(int x, int y) const
            {
                return arr[x][y];
            }
    };

    std::ostream& operator<<(std::ostream &out, const mat2 &a)
    {
        out << "{" << a(0, 0) << ", " << a(0, 1) << "}" << std::endl;
        out << "{" << a(1, 0) << ", " << a(1, 1) << "}";
        return out;
    }

    mat2 operator+(const mat2 a, const mat2 b)
    {
        return mat2(a(0, 0) + b(0, 0),
                    a(0, 1) + b(0, 1),
                    a(1, 0) + b(1, 0),
                    a(1, 1) + b(1, 1));
    }

    mat2 operator-(const mat2 a, const mat2 b)
    {
        return mat2(a(0, 0) - b(0, 0),
                    a(0, 1) - b(0, 1),
                    a(1, 0) - b(1, 0),
                    a(1, 1) - b(1, 1));
    }

    mat2 operator*(const mat2 a, const mat2 b)
    {
        return mat2(a(0, 0) * b(0, 0),
                    a(0, 1) * b(0, 1),
                    a(1, 0) * b(1, 0),
                    a(1, 1) * b(1, 1));
    }

    mat2 operator/(const mat2 a, const mat2 b)
    {
        return mat2(a(0, 0) / b(0, 0),
                    a(0, 1) / b(0, 1),
                    a(1, 0) / b(1, 0),
                    a(1, 1) / b(1, 1));
    }
} // namespace cpml

#endif // MAT2_HPP