#pragma once
#ifndef MATH_HPP
#define MATH_HPP

namespace cpml
{
    // constants
    const double pi = 3.14159265358979323846; // PI
    const double e = 2.71828182845904523536; // Euler's constant

    template <typename T> double floor(T n)
    {
        return n > 0 ? (int)n : (int)(n - 0.9999999999999999);
    }

    template <typename T, typename U> double fmod(T a, U b)
    {
        return (a - b * floor(a / b));
    }

    template <typename T> double frac(T n)
    {
        if (n == 0)
        {
            return 1;
        }
        return n * (frac(n - 1));
    }

    template <typename T, typename U> double pow(T base, U ex);

    double nth_root(double A, int n)
    {
        const int K = 6;
        double x[K] = {1};
        for (int k = 0; k < K - 1; k++)
            x[k + 1] = (1.0 / n) * ((n - 1) * x[k] + A / pow(x[k], n - 1));
        return x[K-1];
    }

    template <typename T, typename U> double pow(T base, U ex)
    {
        if (base == 0)
        return 0;

        if (ex == 0)
        {
            return 1;
        }
        else if(ex < 0)
        {
            return 1 / pow(base, -ex);
        }
        else if (ex > 0 && ex < 1)
        {
            return nth_root(base, 1 / ex);
        }
        else if ((int)ex % 2 == 0)
        {
            float half_pow = pow(base, ex / 2);
            return half_pow * half_pow;
        }
        else
        {
            return base * pow(base, ex - 1);
        }
    }

    template <typename T> double sin(T n)
    {
        n = fmod(n, 2 * pi);
        if (n < 0)
        {
            n = 2 * pi - n;
        }
        char sign = 1;
        if (n > pi)
        {
            n -= pi;
            sign = -1;
        }
        double result = n;
        double coefficient = 3.0;
        for (int i = 0; i < 10; i++)
        {
            double power = pow(n, coefficient);
            double factorial = frac(coefficient);
            if (i % 2 == 0)
            {
                result = result - (power / factorial);
            }
            else
            {
                result = result + (power / factorial);
            }
            coefficient += 2;
        }
        return sign * result;
    }
    
    template <typename T> double abs(T n)
    {
        return n < 0 ? -n : n;
    }

    template <typename T, typename U> double max(T x, U y)
    {
        if (x > y)
            return x;
        else
            return y;
    }

    template <typename T, typename U> double min(T x, U y)
    {
        if (x < y)
            return x;
        else
            return y;
    }

    template <typename T> double trunc(T x)
    {
        return (int)x;
    }

    template <typename T> double round(T x)
    {
        return (int)(x + 0.5);
    }

    template <typename T> double sqrt(T num)
    {
        if (num == 0)
            return 0;

        float x = 1;

        while(abs(x * x - num) >= 0.001 )
            x = ((num/x) + x) / 2;

        return x;
    }

    // Converts Radians to Degrees
    template <typename T> double RadToDeg(T x)
    {
        return (x * (180 / pi));
    }

    // Converts Degrees to Radians
    template <typename T> double DegToRad(T x)
    {
        return (x * (pi / 180));
    }

    // Raise given number to Euler's constant
    template <typename T> double exp(T x)
    {
        return pow(e, x);
    }

    // Raise given number to the second power
    template <typename T> double exp2(T x)
    {
        return pow(2, x);
    }

    // Maps one rage of values to another
    template <typename T> double map(T x, T input_start, T input_end, T output_start, T output_end)
    {
        return (x - input_start) / (input_end - input_start) * (output_end - output_start) + output_start;
    }

} // cpml namespace

#endif // MATH_HPP