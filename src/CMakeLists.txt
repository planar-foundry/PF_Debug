add_library(PF_Debug
    PF_Debug/Assert.cpp PF_Debug/Assert.hpp
    PF_Debug/Log.cpp PF_Debug/Log.hpp)

target_include_directories(PF_Debug PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(PF_Debug PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic>)

if (${PFDEBUG_ENABLE_ASSERT})
    target_compile_definitions(PF_Debug PUBLIC "PFDEBUG_ASSERT_ENABLED")
endif()

if (${PFDEBUG_ENABLE_ASSERT})
    target_compile_definitions(PF_Debug PUBLIC "PFDEBUG_LOG_ENABLED")
endif()
