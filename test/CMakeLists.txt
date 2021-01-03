project(${CMAKE_PROJECT_NAME}Tests LANGUAGES CXX)

message(STATUS "Adding tests under ${CMAKE_PROJECT_NAME}Tests...")

add_executable(sample1_test sample1_unittest.cc)
target_link_libraries(sample1_test sample1 gtest_main)
add_test(NAME sample1_test COMMAND ${CMAKE_CURRENT_BINARY_DIR}/sample1_test
                                   --gtest_output=xml:${CMAKE_BINARY_DIR}/test_results/sample1_test.xml)
# https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#generating-an-xml-report

# cmake-format: off
# message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR} ")
# message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR} ")
# cmake-format: on

message(STATUS "Finished adding unit tests for ${CMAKE_PROJECT_NAME}.")
