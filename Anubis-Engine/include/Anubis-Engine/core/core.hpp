#ifndef ANUBIS_ENGINE_CORE_HPP
#define ANUBIS_ENGINE_CORE_HPP

#include <memory>
#include <iostream>

// Platform detection
#ifdef _WIN32
    #define ABE_PLATFORM_WINDOWS
#else 
#error Platform not supported
#endif


#ifdef NDEBUG
#define ABE_ASSERT(c, msg)
#else
#define ABE_ASSERT(c, msg)                                                      \
    if(!(c)){                                                           \
        std::cerr << "-- Assertion failed --\n"                                 \
                  << "Condition : " << #c << "\n"                              \
                  << "File : " << __FILE__ << " (line " << __LINE__ << ")\n"    \
                  << "Function : " << __func__ << "\n"                          \
                  << "----------------------\n";                                \
        std::abort();                                                           \
    }
#endif // !NDEBUG

namespace ABE
{
    using uint = unsigned int;
    using uchar = unsigned char;
    using ushort = unsigned short;

    template <typename T> using Ref = std::shared_ptr<T>;
    template <typename T> using WeakRef = std::weak_ptr<T>;
    template <typename T> using Scope = std::unique_ptr<T>;
}

#endif // !ANUBIS_ENGINE_CORE_HPP
