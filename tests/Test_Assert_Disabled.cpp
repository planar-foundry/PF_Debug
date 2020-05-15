#include <PF_Test/UnitTest.hpp>

#undef PFDEBUG_ASSERT_ENABLED
#include <PF_Debug/Assert.hpp>

using namespace pf::debug;

PFTEST_CREATE(Assert_Disabled)
{
    static bool s_in_assert = false;
    set_assert_handler([](const char*, const char*, int, const char*) { s_in_assert = true; });

    PFDEBUG_ASSERT(false);
    PFTEST_EXPECT(!s_in_assert);

    PFDEBUG_ASSERT(true);
    PFTEST_EXPECT(!s_in_assert);

    PFDEBUG_ASSERT_MSG(false, "");
    PFTEST_EXPECT(!s_in_assert);

    PFDEBUG_ASSERT_MSG(true, "");
    PFTEST_EXPECT(!s_in_assert);

    PFDEBUG_ASSERT_FAIL();
    PFTEST_EXPECT(!s_in_assert);

    PFDEBUG_ASSERT_FAIL_MSG("");
    PFTEST_EXPECT(!s_in_assert);
}
