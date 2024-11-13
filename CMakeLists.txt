#-------------------------------------------------------------------------------------------
# Compile with GCC:
#   rm -rf build && CC=gcc CXX=g++ cmake -B build && cmake --build build --parallel
#
# Compile with Intel C++ Compiler:
#   rm -rf build && CC=icc CXX=icpc cmake -B build && cmake --build build --parallel
#-------------------------------------------------------------------------------------------


#-------------------------------------------------------------------------------------------
# Project configuration.
#-------------------------------------------------------------------------------------------

# Require a minimum version of cmake.
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# Set the name of the project.
project("addtofullpack_manager")

# Add a library target to be built from the source files.
add_library(${CMAKE_PROJECT_NAME} SHARED)

# Options
option(OPT_DEBUG "Build with debugging information and runtime checks." OFF)
option(OPT_NO_RTTI "Disable RTTI support." OFF)
option(OPT_NO_EXCEPTIONS "Disable exception handling table generation." OFF)

# Linking options
option(OPT_LINK_C "Linking with libc library." ON)
option(OPT_LINK_M "Linking with libm library." ON)
option(OPT_LINK_DL "Linking with libdl library." ON)
option(OPT_LINK_LIBGCC "Static linking with libgcc library." ON)
option(OPT_LINK_LIBSTDC "Static linking with libstdc++ library." ON)

# Set policies
cmake_policy(SET CMP0018 NEW)
cmake_policy(SET CMP0063 NEW)
cmake_policy(SET CMP0065 NEW)
cmake_policy(SET CMP0069 NEW)
cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0092 NEW)

# Settings
set(CMAKE_RULE_MESSAGES ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

include(cmake/Tools.cmake)
include(cmake/cmake-version4git.cmake)

PROJECT_VERSION_FROM_GIT()
add_definitions(${PROJECT_VERSION4GIT_CFLAGS})
set_build_type()
set_output_binary_name()
set_default_parallel_jobs()


#-------------------------------------------------------------------------------------------
# Add include directories.
#-------------------------------------------------------------------------------------------

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    "addtofullpack_manager/sdk/cssdk/include"
    "addtofullpack_manager/sdk/metamod/include"
    "addtofullpack_manager/sdk/amxx/include"
    "addtofullpack_manager/addtofullpack_manager/include"
)


#-------------------------------------------------------------------------------------------
# Add source files.
#-------------------------------------------------------------------------------------------

find_source_files("addtofullpack_manager/sdk/cssdk/src" sources_list)
find_source_files("addtofullpack_manager/sdk/metamod/src" sources_list)
find_source_files("addtofullpack_manager/sdk/amxx/src" sources_list)
find_source_files("addtofullpack_manager/addtofullpack_manager/src" sources_list)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${sources_list})


#-------------------------------------------------------------------------------------------
# Set definitions.
#-------------------------------------------------------------------------------------------

include(cmake/Definitions.cmake)


#-------------------------------------------------------------------------------------------
# Set compiler flags.
#-------------------------------------------------------------------------------------------

target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    VISIBILITY_INLINES_HIDDEN ON
    CXX_VISIBILITY_PRESET hidden
    INTERPROCEDURAL_OPTIMIZATION_DEBUG OFF
    INTERPROCEDURAL_OPTIMIZATION_RELEASE ON
    INTERPROCEDURAL_OPTIMIZATION_MINSIZEREL ON
    INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO OFF
)

if (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
    include(cmake/GCC.cmake)
elseif(${CMAKE_CXX_COMPILER_ID} MATCHES "Intel")
    include(cmake/Intel.cmake)
endif()
