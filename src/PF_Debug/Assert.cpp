#include <PF_Debug/Assert.hpp>

namespace pf::debug
{

static AssertFunc s_assert_func =

#if defined(PFDEBUG_ASSERT_ENABLED)
    &default_assert_handler;
#else
    nullptr;
#endif

void set_assert_handler(AssertFunc handler)
{
    s_assert_func = handler;
}

AssertFunc get_assert_handler()
{
    return s_assert_func;
}

#if defined(PFDEBUG_ASSERT_ENABLED)

void default_assert_handler(const char* condition, const char* file, int, const char* message)
{
    fputs(condition, stderr);
    fputs(" failured in ", stderr);
    fputs(file, stderr);
    fputs(" with message ", stderr);
    fputs(message, stderr);
    fflush(stderr);
}

#endif

}
