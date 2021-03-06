cmake_minimum_required(VERSION 3.15)

# Set the project name to your project name, my project isn't very descriptive
project(randomProjects CXX)
include(cmake/StandardProjectSettings.cmake)

# print_all_variables()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# cmake-format: off
# standard compiler warnings
# include(cmake/CompilerWarnings.cmake)
# set_project_warnings(project_warnings)

# allow for static analysis options
#include(cmake/StaticAnalyzers.cmake)
# cmake-format: on

# Setup Google Test
if(ENABLE_TESTING)
  include(cmake/SetupGoogleTest.cmake)
  enable_testing()
  add_subdirectory(test)
endif()

add_subdirectory(smart_pointers)
add_subdirectory(lvalues_and_rvalues)
add_subdirectory(move_semantics)
add_subdirectory(pointers_references)
add_subdirectory(variant)
add_subdirectory(functional_programming/count-lines)
add_subdirectory(functional_programming/math)
add_subdirectory(google_test_samples)

# message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")
