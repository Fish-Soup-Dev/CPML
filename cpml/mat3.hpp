#pragma once
#ifndef MAT3_HPP
#define MAT3_HPP

#include <iostream>
#include "vec3.hpp"

namespace cpml
{
    class mat3
    {
        private:
            double arr[3][3];
        
        public:
            mat3() : arr{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0} {}

            template <typename T> mat3(T a) : arr{(double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a} {}

            mat3(vec3 a, vec3 b, vec3 c) : arr{a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z} {}

            template <typename T> mat3(T a, T b, T c, T d, T e, T f, T g, T h, T i) : arr{(double)a, (double)b, (double)c, (double)d, (double)e, (double)f, (double)g, (double)h, (double)i} {}

            const double& operator()(int x, int y) const
            {
                return arr[x][y];
            }
    };

    std::ostream& operator<<(std::ostream &out, const mat3 &a)
    {
        out << "{" << a(0, 0) << ", " << a(0, 1) << ", " << a(0, 2) << "}" << std::endl;
        out << "{" << a(1, 0) << ", " << a(1, 1) << ", " << a(1, 2) << "}" << std::endl;
        out << "{" << a(2, 0) << ", " << a(2, 1) << ", " << a(2, 2) << "}";
        return out;
    }

    mat3 operator+(const mat3 a, const mat3 b)
    {
        return mat3(a(0, 0) + b(0, 0), a(0, 1) + b(0, 1), a(0, 2) + b(0, 2),
                    a(1, 0) + b(1, 0), a(1, 1) + b(1, 1), a(1, 2) + b(1, 2),
                    a(2, 0) + b(2, 0), a(2, 1) + b(2, 1), a(2, 2) + b(2, 2));
    }

    mat3 operator-(const mat3 a, const mat3 b)
    {
        return mat3(a(0, 0) - b(0, 0), a(0, 1) - b(0, 1), a(0, 2) - b(0, 2),
                    a(1, 0) - b(1, 0), a(1, 1) - b(1, 1), a(1, 2) - b(1, 2),
                    a(2, 0) - b(2, 0), a(2, 1) - b(2, 1), a(2, 2) - b(2, 2));
    }

    mat3 operator*(const mat3 a, const mat3 b)
    {
        return mat3(a(0, 0) * b(0, 0), a(0, 1) * b(0, 1), a(0, 2) * b(0, 2),
                    a(1, 0) * b(1, 0), a(1, 1) * b(1, 1), a(1, 2) * b(1, 2),
                    a(2, 0) * b(2, 0), a(2, 1) * b(2, 1), a(2, 2) * b(2, 2));
    }

    mat3 operator/(const mat3 a, const mat3 b)
    {
        return mat3(a(0, 0) / b(0, 0), a(0, 1) / b(0, 1), a(0, 2) / b(0, 2),
                    a(1, 0) / b(1, 0), a(1, 1) / b(1, 1), a(1, 2) / b(1, 2),
                    a(2, 0) / b(2, 0), a(2, 1) / b(2, 1), a(2, 2) / b(2, 2));
    }
} // namespace cpml

#endif // MAT3_HPP