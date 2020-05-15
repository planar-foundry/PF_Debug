#include <PF_Test/UnitTest.hpp>
#include <PF_Debug/Log.hpp>

using namespace pf::debug;

PFTEST_CREATE(Log_Enabled)
{
    static bool s_in_log = false;
    static Severity s_sev;
    static const char* s_message;

    set_log_handler([](Severity severity, const char* message)
    {
        s_in_log = true;
        s_sev = severity;
        s_message = message;
    });

    PFDEBUG_LOG_DEBUG("");
    PFTEST_EXPECT(s_in_log);
    PFTEST_EXPECT(s_sev == Severity::Debug);
    PFTEST_EXPECT(*s_message == '\0');
    s_in_log = false;

    PFDEBUG_LOG_INFO("");
    PFTEST_EXPECT(s_in_log);
    PFTEST_EXPECT(s_sev == Severity::Info);
    PFTEST_EXPECT(*s_message == '\0');
    s_in_log = false;

    PFDEBUG_LOG_WARN("");
    PFTEST_EXPECT(s_in_log);
    PFTEST_EXPECT(s_sev == Severity::Warn);
    PFTEST_EXPECT(*s_message == '\0');
    s_in_log = false;

    PFDEBUG_LOG_ERROR("");
    PFTEST_EXPECT(s_in_log);
    PFTEST_EXPECT(s_sev == Severity::Error);
    PFTEST_EXPECT(*s_message == '\0');
    s_in_log = false;
}
