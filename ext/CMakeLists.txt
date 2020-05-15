if (NOT TARGET PF_Test AND ${PFDEBUG_BUILD_TESTS})
    add_subdirectory(PF_Test)
endif()
