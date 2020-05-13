#include <PF_Debug/Log.hpp>

namespace pf::debug
{

static LogFunc s_log_func =

#if defined(PFDEBUG_LOG_ENABLED)
    &default_log_handler;
#else
    nullptr;
#endif

void set_log_handler(LogFunc handler)
{
    s_log_func = handler;
}

LogFunc get_log_handler()
{
    return s_log_func;
}

#if defined(PFDEBUG_LOG_ENABLED)

void default_log_handler(Severity sev, const char* message)
{
    FILE* stream = sev == Error ? stderr : stdout;
    fputs(message, stream);
    fflush(stream);
}

#endif

}
