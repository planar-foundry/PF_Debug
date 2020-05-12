#include <PF_Debug/Assert.hpp>

#include <exception>

namespace pf::debug
{

AssertFunc g_assert_func =

#if defined(PFDEBUG_ASSERT_ENABLED)
    &default_assert_handler;
#else
    nullptr;
#endif

void set_assert_handler(AssertFunc handler)
{
    g_assert_func = handler;
}

AssertFunc get_assert_handler()
{
    return g_assert_func;
}

#if defined(PFDEBUG_ASSERT_ENABLED)

void default_assert_handler(const char* condition, const char* file, int line, const char* message)
{
    fputs(condition, stderr);
    fputs(" failured in ", stderr);
    fputs(file, stderr);
    fputs(" with message ", stderr);
    fputs(message, stderr);
    fflush(stderr);
    std::terminate();
}

#endif

}
