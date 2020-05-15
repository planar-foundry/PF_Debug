if (${PFDEBUG_ENABLE_ASSERT})
    set(SOURCES ${SOURCES} Test_Assert_Enabled.cpp Test_Assert_Disabled.cpp)
endif()

if (${PFDEBUG_ENABLE_LOG})
    set(SOURCES ${SOURCES} Test_Log_Enabled.cpp Test_Log_Disabled.cpp)
endif()

add_executable(PF_Debug_UnitTests main.cpp ${SOURCES})
target_link_libraries(PF_Debug_UnitTests PF_Debug PF_Test)
target_compile_options(PF_Debug_UnitTests PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic>)
