# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE
      RelWithDebInfo
      CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui, ccmake
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

find_program(CCACHE ccache)
if(CCACHE)
  message("using ccache")
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
else()
  message("ccache not found cannot use")
endif()

# Generate compile_commands.json to make it easier to work with clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_IPO "Enable Iterprocedural Optimization, aka Link Time Optimization (LTO)" OFF)

if(ENABLE_IPO)
  include(CheckIPOSupported)
  check_ipo_supported(RESULT result OUTPUT output)
  if(result)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
  else()
    message(SEND_ERROR "IPO is not supported: ${output}")
  endif()
endif()

set(THIRDPARTY_SOURCES_DIR
    "${CMAKE_SOURCE_DIR}/3rdparty"
    CACHE PATH "Directory for third-party sources")
# message(STATUS "THIRDPARTY_SOURCES_DIR: ${THIRDPARTY_SOURCES_DIR}")

# TODO Where is this used?
option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" ON)
option(ENABLE_TESTING "Enable Test Builds" ON)

if(ENABLE_TESTING)
  set(GTEST_SOURCE_DIR ${THIRDPARTY_SOURCES_DIR}/googletest)
  set(GTEST_BINARY_DIR ${CMAKE_BINARY_DIR}/googletest)
  # https://github.com/facebook/fbthrift/blob/master/build/fbcode_builder/manifests/googletest
  set(GOOGLETEST_VERSION 1.10.0)
  set(GTEST_ARCHIVE_HASH 9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb)
  set(GTEST_LIBRARIES gtest gtest_main gmock)
  # cmake-format: off
  #message(STATUS "GTEST_SOURCE_DIR path: ${GTEST_SOURCE_DIR} ")
  #message(STATUS "GTEST_BINARY_DIR path: ${GTEST_BINARY_DIR} ")
  # cmake-format: on
endif()

# Display all CMake variables
macro(print_all_variables)
  message(STATUS "print_all_variables------------------------------------------{")
  get_cmake_property(_variableNames VARIABLES)
  foreach(_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
  endforeach()
  message(STATUS "print_all_variables------------------------------------------}")
endmacro()
