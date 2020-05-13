#pragma once

#if defined(WIN32) && defined(PF_Debug_EXPORTS)
    #define PFDEBUG_API __declspec(dllexport)
#else
    #define PFDEBUG_API
#endif
