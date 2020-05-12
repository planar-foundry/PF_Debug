#pragma once

#include <stdio.h>

namespace pf::debug
{
    enum Severity
    {
        Debug = 0,
        Info = 1,
        Warn = 2,
        Error = 3
    };

    using LogFunc = void(*)(Severity severity, const char* message);
    void set_log_handler(LogFunc handler);
    LogFunc get_log_handler();

#if defined(PFDEBUG_LOG_ENABLED)
    #define PFDEBUG_LOG_DEBUG(format, ...) \
        ::pf::debug::format_log(::pf::debug::Severity::Debug, (format), ##__VA_ARGS__)

    #define PFDEBUG_LOG_INFO(format, ...) \
        ::pf::debug::format_log(::pf::debug::Severity::Info, (format), ##__VA_ARGS__)

    #define PFDEBUG_LOG_WARN(format, ...) \
        ::pf::debug::format_log(::pf::debug::Severity::Warn, (format), ##__VA_ARGS__)

    #define PFDEBUG_LOG_ERROR(format, ...) \
        ::pf::debug::format_log(::pf::debug::Severity::Error, (format), ##__VA_ARGS__)

    template <typename ... Args>
    void format_log(Severity severity, const char* format, Args ... args)
    {
        if (LogFunc handler = get_log_handler())
        {
            static char buffer[4096];
            snprintf(buffer, sizeof(buffer), format, args ...);
            handler(severity, buffer);
        }
    }

    void default_log_handler(Severity severity, const char* message);
#else
    #define PFDEBUG_LOG_DEBUG(format, ...) (void)0
    #define PFDEBUG_LOG_INFO(format, ...) (void)0
    #define PFDEBUG_LOG_WARN(format, ...) (void)0
    #define PFDEBUG_LOG_ERROR(format, ...) (void)0
#endif

}
