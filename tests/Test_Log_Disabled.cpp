#include <PF_Test/UnitTest.hpp>

#undef PFDEBUG_LOG_ENABLED
#include <PF_Debug/Log.hpp>

using namespace pf::debug;

PFTEST_CREATE(Log_Disbled)
{
    static bool s_in_log = false;
    set_log_handler([](Severity, const char*) { s_in_log = true; });

    PFDEBUG_LOG_DEBUG("");
    PFTEST_EXPECT(!s_in_log);

    PFDEBUG_LOG_INFO("");
    PFTEST_EXPECT(!s_in_log);

    PFDEBUG_LOG_WARN("");
    PFTEST_EXPECT(!s_in_log);

    PFDEBUG_LOG_ERROR("");
    PFTEST_EXPECT(!s_in_log);
}
