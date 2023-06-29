#ifndef PULSAR_DEBUG_INCLUDED
#define PULSAR_DEBUG_INCLUDED

#include "setup.hpp"
#include "Math/Vector.hpp"
#include <iostream>

namespace Pulsar {
    PULSAR_INLINE void print() {
        std::cout << std::endl;
    }

    template<typename T, typename ...TAIL>
    PULSAR_INLINE void print(const T& t, TAIL... tail)
    {
        std::cout << std::fixed << t << " ";
        print(tail...);
    }

    template<typename T, typename ...TAIL>
    PULSAR_INLINE void print(const vec<1, T>& t, TAIL... tail)
    {
        std::cout << std::fixed << "X: " << t.x << " ";
        print(tail...);
    }

    template<typename T, typename ...TAIL>
    PULSAR_INLINE void print(const vec<2, T>& t, TAIL... tail)
    {
        std::cout << std::fixed << "X: " << t.x << ",  " << "Y: " << t.y << " ";
        print(tail...);
    }

    template<typename T, typename ...TAIL>
    PULSAR_INLINE void print(const vec<3, T>& t, TAIL... tail)
    {
        std::cout << std::fixed << "X: " << t.x << ",  " << "Y: " << t.y << ",  " << "Z: " << t.z << " ";
        print(tail...);
    }

    template<typename T, typename ...TAIL>
    PULSAR_INLINE void print(const vec<4, T>& t, TAIL... tail)
    {
        std::cout << std::fixed << "X: " << t.x << ",  " << "Y: " << t.y << ",  " << "Z: " << t.z << ",  " << "W: " << t.w << " ";
        print(tail...);
    }
}

#endif