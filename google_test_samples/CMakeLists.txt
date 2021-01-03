project(sample1)

# Generate the shared library from the library sources
add_library(${PROJECT_NAME} SHARED src/sample1.cc)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# message(STATUS "PROJECT_SOURCE_DIR path: ${PROJECT_SOURCE_DIR} ")
