#-------------------------------------------------------------------------------------------
# Set definitions.
#-------------------------------------------------------------------------------------------

if (UNIX)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        LINUX linux POSIX _LINUX

        # Build type Debug
        $<$<CONFIG:Debug>:
        DEBUG _DEBUG _GLIBCXX_DEBUG _GLIBCXX_DEBUG_PEDANTIC _GLIBCXX_ASSERTIONS _FORTIFY_SOURCE=2>

        # Build type Release, MinSizeRel, RelWithDebInfo
        $<$<OR:$<CONFIG:Release>,$<CONFIG:MinSizeRel>,$<CONFIG:RelWithDebInfo>>:
        NDEBUG RELEASE _RELEASE>
)
elseif(WIN32)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        WIN32 _WINDOWS _USRDLL _WINDLL _MBCS

        # Build type Debug
        $<$<CONFIG:Debug>:
        DEBUG _DEBUG>

        # Build type Release, MinSizeRel, RelWithDebInfo
        $<$<OR:$<CONFIG:Release>,$<CONFIG:MinSizeRel>,$<CONFIG:RelWithDebInfo>>:
        NDEBUG RELEASE _RELEASE>
)
endif()

# Set the DEFINE_SYMBOL property
string(TOUPPER ${CMAKE_PROJECT_NAME} EXPORTS)
string(APPEND EXPORTS "_EXPORTS")
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES DEFINE_SYMBOL ${EXPORTS})
