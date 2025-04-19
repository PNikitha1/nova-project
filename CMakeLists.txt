cmake_minimum_required(VERSION 3.10)
project(MobileAppManagerTests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add the main source files
add_library(MobileAppManagerLib App.cpp MobileAppManager.cpp)

# Add test executable
add_executable(runTests tests.cpp)

# Link libraries
target_link_libraries(runTests MobileAppManagerLib GTest::gtest GTest::gtest_main pthread)

# Enable testing
enable_testing()
add_test(NAME MobileAppManagerTests COMMAND runTests)