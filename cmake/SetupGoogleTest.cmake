configure_file(${CMAKE_CURRENT_LIST_DIR}/GoogleTest-CMakeLists.txt.in
               ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
)
if(result)
  message(FATAL_ERROR "Running CMake for Google Test failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
)
if(result)
  message(FATAL_ERROR "Downloading Google Test failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# message(STATUS "GTEST_SOURCE_DIR path: ${GTEST_SOURCE_DIR} ")
# message(STATUS "GTEST_BINARY_DIR path: ${GTEST_BINARY_DIR} ")

add_subdirectory(${GTEST_SOURCE_DIR} ${GTEST_BINARY_DIR} EXCLUDE_FROM_ALL)

# TODO This is from RCU template
# mark_as_advanced(FORCE
#                  BUILD_SHARED_LIBS
#                  gmock_build_tests
#                  gtest_build_samples
#                  gtest_build_tests
#                  gtest_disable_pthreads
#                  gtest_force_shared_crt
#                  gtest_hide_internal_symbols)
