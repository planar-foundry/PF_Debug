#pragma once

#include <stdio.h>

namespace pf::debug
{
    using AssertFunc = void(*)(const char* condition, const char* file, int line, const char* message);
    void set_assert_handler(AssertFunc handler);
    AssertFunc get_assert_handler();

#if defined(PFDEBUG_ASSERT_ENABLED)
    #define PFDEBUG_ASSERT(condition) \
        do \
        { \
            if (!(condition)) ::pf::debug::format_assert((#condition), __FILE__, __LINE__, "%s", "(no message)"); \
        } while (0)

    #define PFDEBUG_ASSERT_MSG(condition, format, ...) \
        do \
        { \
            if (!(condition)) ::pf::debug::format_assert((#condition), __FILE__, __LINE__, (format), ##__VA_ARGS__); \
        } while (0)

    #define PFDEBUG_ASSERT_FAIL() \
        ::pf::debug::format_assert("(no condition)", __FILE__, __LINE__, "%s", "(no message)")

    #define PFDEBUG_ASSERT_FAIL_MSG(format, ...) \
        ::pf::debug::format_assert("(no condition)", __FILE__, __LINE__, (format), ##__VA_ARGS__)

    template <typename ... Args>
    void format_assert(const char* condition, const char* file, int line, const char* format, Args ... args)
    {
        if (AssertFunc handler = get_assert_handler())
        {
            static char buffer[4096];
            snprintf(buffer, sizeof(buffer), format, args ...);
            handler(condition, file, line, buffer);
        }
    }

    void default_assert_handler(const char* condition, const char* file, int line, const char* message);
#else
    #define PFDEBUG_ASSERT(condition) (void)0
    #define PFDEBUG_ASSERT_MSG(condition, format, ...) (void)0
    #define PFDEBUG_ASSERT_FAIL() (void)0
    #define PFDEBUG_ASSERT_FAIL_MSG(format, ...) (void)0
#endif

}
