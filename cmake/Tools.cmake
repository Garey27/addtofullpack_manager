#-------------------------------------------------------------------------------------------
# Set PREFIX and SUFFIX for output binary name.
#-------------------------------------------------------------------------------------------

function(set_output_binary_name)
    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PREFIX "")

    if (UNIX AND NOT APPLE)
        set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES SUFFIX "_amxx_i386.so")
    elseif(APPLE)
        set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES SUFFIX "_amxx.dylib")
    elseif(WIN32)
        set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES SUFFIX "_amxx.dll")
    endif()
endfunction()


#-------------------------------------------------------------------------------------------
# Set default build parallel jobs (multiprocessor compilation).
#-------------------------------------------------------------------------------------------

function(set_default_parallel_jobs)
    if (("x${CMAKE_BUILD_PARALLEL_LEVEL}" STREQUAL "x") AND UNIX)
        include(ProcessorCount)
        ProcessorCount(NCORES)
        message(STATUS "Defaulting to ${NCORES} parallel jobs.")
        set(CMAKE_BUILD_PARALLEL_LEVEL ${NCORES})
    endif()
endfunction()


#-------------------------------------------------------------------------------------------
# Set a developer-chosen build type (Debug, Release, RelWithDebInfo, MinSizeRel).
#-------------------------------------------------------------------------------------------

function(set_build_type)
    if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        if (OPT_DEBUG)
            message(STATUS "Setting build type to Debug.")
            set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
        else()
            message(STATUS "Setting build type to Release.")
            set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
        endif()
    endif()
endfunction()


#-------------------------------------------------------------------------------------------
# Set output directory for compiled files.
#-------------------------------------------------------------------------------------------

function(set_binary_output_directory _directory)
    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${_directory}/${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}/${CMAKE_BUILD_TYPE}"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${_directory}/${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}/${CMAKE_BUILD_TYPE}"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${_directory}/${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}/${CMAKE_BUILD_TYPE}")
endfunction()


#-------------------------------------------------------------------------------------------
# Find source files in given directory and subdirectories.
#-------------------------------------------------------------------------------------------

macro(find_source_files _base_dir _return_list)
    file(GLOB_RECURSE _found_list
        "${_base_dir}/*.c"   "${_base_dir}/*.cc"
        "${_base_dir}/*.C"   "${_base_dir}/*.cpp"
        "${_base_dir}/*.c++" "${_base_dir}/*.cxx"
        "${_base_dir}/*.asm" "${_base_dir}/*.asmx")
	list(APPEND ${_return_list} ${_found_list})
endmacro()
