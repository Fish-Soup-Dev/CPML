#pragma once
#ifndef RAND_HPP
#define RAND_HPP

#include "math.hpp"

namespace cpml
{
    class random
    {
        private:
            unsigned long next;

        public:
            random() : next(1) {}
            random(int seed) : next(seed) {}

            // Generate random number from 0 to RAND_MAX
            int rand()
            {
                next = next * 1103515245 + 12345;
                return((unsigned)(next / 65536) % 32768);
            }

            // Generate random number from min to max
            int rand(int min, int max)
            {
                return rand() % max + min;
            }

            // Sets random number seed
            void srand(unsigned int seed)
            {
                next = seed;
            }
    };
} // namespace cpml

#endif // RAND_HPP