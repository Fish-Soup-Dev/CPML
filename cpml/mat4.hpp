#pragma once
#ifndef MAT4_HPP
#define MAT4_HPP

#include <iostream>
#include "vec4.hpp"

namespace cpml
{
    class mat4
    {
        private:
            double arr[4][4];

        public:
            mat4() : arr{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0} {}
            
            template <typename T> mat4(T a) : arr{(double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a, (double)a} {}

            mat4(vec4 a, vec4 b, vec4 c, vec4 d) : arr{a.x, a.y, a.z, a.w, b.x, b.y, b.z, b.w, c.x, c.y, c.z, c.w, d.x, d.y, d.z, d.w} {}
            
            template <typename T> mat4(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p) : arr{(double)a, (double)b, (double)c, (double)d, (double)e, (double)f, (double)g, (double)h, (double)i, (double)j, (double)k, (double)l, (double)m, (double)n, (double)o, (double)p} {}

            const double& operator()(int x, int y) const
            {
                return arr[x][y];
            }
    };

    std::ostream& operator<<(std::ostream &out, const mat4 &a)
    {
        out << "{" << a(0, 0) << ", " << a(0, 1) << ", " << a(0, 2) << ", " << a(0, 3) << "}" << std::endl;
        out << "{" << a(1, 0) << ", " << a(1, 1) << ", " << a(1, 2) << ", " << a(1, 3) << "}" << std::endl;
        out << "{" << a(2, 0) << ", " << a(2, 1) << ", " << a(2, 2) << ", " << a(2, 3) << "}" << std::endl;
        out << "{" << a(3, 0) << ", " << a(3, 1) << ", " << a(3, 2) << ", " << a(3, 3) << "}";
        return out;
    }

    mat4 operator+(const mat4 a, const mat4 b)
    {
        return mat4(a(0, 0) + b(0, 0), a(0, 1) + b(0, 1), a(0, 2) + b(0, 2) ,a(0, 3) + b(0, 3),
                    a(1, 0) + b(1, 0), a(1, 1) + b(1, 1), a(1, 2) + b(1, 2) ,a(1, 3) + b(1, 3),
                    a(2, 0) + b(2, 0), a(2, 1) + b(2, 1), a(2, 2) + b(2, 2) ,a(2, 3) + b(2, 3),
                    a(3, 0) + b(3, 0), a(3, 1) + b(3, 1), a(3, 2) + b(3, 2) ,a(3, 3) + b(3, 3));
    }

    mat4 operator-(const mat4 a, const mat4 b)
    {
        return mat4(a(0, 0) - b(0, 0), a(0, 1) - b(0, 1), a(0, 2) - b(0, 2) ,a(0, 3) - b(0, 3),
                    a(1, 0) - b(1, 0), a(1, 1) - b(1, 1), a(1, 2) - b(1, 2) ,a(1, 3) - b(1, 3),
                    a(2, 0) - b(2, 0), a(2, 1) - b(2, 1), a(2, 2) - b(2, 2) ,a(2, 3) - b(2, 3),
                    a(3, 0) - b(3, 0), a(3, 1) - b(3, 1), a(3, 2) - b(3, 2) ,a(3, 3) - b(3, 3));
    }

    mat4 operator*(const mat4 a, const mat4 b)
    {
        return mat4(a(0, 0) * b(0, 0), a(0, 1) * b(0, 1), a(0, 2) * b(0, 2) ,a(0, 3) * b(0, 3),
                    a(1, 0) * b(1, 0), a(1, 1) * b(1, 1), a(1, 2) * b(1, 2) ,a(1, 3) * b(1, 3),
                    a(2, 0) * b(2, 0), a(2, 1) * b(2, 1), a(2, 2) * b(2, 2) ,a(2, 3) * b(2, 3),
                    a(3, 0) * b(3, 0), a(3, 1) * b(3, 1), a(3, 2) * b(3, 2) ,a(3, 3) * b(3, 3));
    }

    mat4 operator/(const mat4 a, const mat4 b)
    {
        return mat4(a(0, 0) / b(0, 0), a(0, 1) / b(0, 1), a(0, 2) / b(0, 2) ,a(0, 3) / b(0, 3),
                    a(1, 0) / b(1, 0), a(1, 1) / b(1, 1), a(1, 2) / b(1, 2) ,a(1, 3) / b(1, 3),
                    a(2, 0) / b(2, 0), a(2, 1) / b(2, 1), a(2, 2) / b(2, 2) ,a(2, 3) / b(2, 3),
                    a(3, 0) / b(3, 0), a(3, 1) / b(3, 1), a(3, 2) / b(3, 2) ,a(3, 3) / b(3, 3));
    }
} // namespace cpml

#endif // MAT4_HPP