cmake_minimum_required(VERSION 3.10)

project(awesome_cpp)

set(CMAKE_CXX_STANDARD 11)

# Add the Google Test library
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the executable
add_executable(test_main test/test_main.cpp test/test_isPossible.cpp)

# Link the Google Test library
target_link_libraries(test_main gtest_main)

# Add the test target
enable_testing()
add_test(NAME test_main COMMAND test_main)
