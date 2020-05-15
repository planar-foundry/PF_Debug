#include <PF_Test/UnitTest.hpp>
#include <PF_Debug/Assert.hpp>

#include <string.h>

using namespace pf::debug;

PFTEST_CREATE(Assert_Enabled)
{
    static bool s_in_assert = false;
    static const char* s_condition;
    static const char* s_message;

    set_assert_handler([](const char* condition, const char*, int, const char* message)
    {
        s_in_assert = true;
        s_condition = condition;
        s_message = message;
    });

    PFDEBUG_ASSERT(false);
    PFTEST_EXPECT(s_in_assert);
    PFTEST_EXPECT(strcmp(s_condition, "false") == 0);
    s_in_assert = false;

    PFDEBUG_ASSERT(true);
    PFTEST_EXPECT(!s_in_assert);
    s_in_assert = false;

    PFDEBUG_ASSERT_MSG(false, "");
    PFTEST_EXPECT(s_in_assert);
    PFTEST_EXPECT(strcmp(s_condition, "false") == 0);
    PFTEST_EXPECT(*s_message == '\0');
    s_in_assert = false;

    PFDEBUG_ASSERT_MSG(true, "");
    PFTEST_EXPECT(!s_in_assert);
    s_in_assert = false;

    PFDEBUG_ASSERT_FAIL();
    PFTEST_EXPECT(s_in_assert);
    s_in_assert = false;

    PFDEBUG_ASSERT_FAIL_MSG("");
    PFTEST_EXPECT(s_in_assert);
    PFTEST_EXPECT(*s_message == '\0');
    s_in_assert = false;
}
