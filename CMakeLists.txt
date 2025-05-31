
#/******************************************************************************
# *                    File Name: CMakeLists.txt
# *                    Description: CMake build configuration file for the 
# *                                 MobileAppManagerTests project. It sets up
# *                                 the project environment including C++ standard,
# *                                 finds and links Google Test libraries,
# *                                 compiles application source files into a library,
# *                                 builds the test executable, and registers
# *                                 unit tests to be run with CTest.
# *                    Created By: Nikitha, Karthikeya, Snigdha, Swetha
# *                    Created Date: 30/05/2025
# *****************************************************************************/

#/******************************************************************************
# *                  Minimum Required CMake Version
# *                  Description: Ensures that the CMake version is at least 3.10
# *****************************************************************************/
cmake_minimum_required(VERSION 3.10)

#/******************************************************************************
# *                  Project Declaration
# *                  Description: Names the project as 'MobileAppManagerTests'
# *****************************************************************************/
project(MobileAppManagerTests)

#/******************************************************************************
# *                  C++ Standard Configuration
# *                  Description: Sets the C++ standard to C++17 and makes it mandatory
# *****************************************************************************/
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#/******************************************************************************
# *                  Google Test Integration
# *                  Description: Finds and includes Google Test library headers
# *****************************************************************************/
find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})

#/******************************************************************************
# *                  Include Directories
# *                  Description: Adds current source directory for header file inclusion
# *****************************************************************************/
include_directories(${CMAKE_SOURCE_DIR})

#/******************************************************************************
# *                  Source Files
# *                  Description: Compiles core application source files into a library
# *****************************************************************************/
add_library(MobileAppManagerLib App.cpp MobileAppManager.cpp)

#/******************************************************************************
# *                  Test Executable
# *                  Description: Creates an executable from test source file
# *****************************************************************************/
add_executable(runTests tests.cpp)

#/******************************************************************************
# *                  Linking Libraries
# *                  Description: Links the test executable with:
# *                               - Application logic library
# *                               - Google Test libraries
# *                               - pthread (for threading support)
# *****************************************************************************/
target_link_libraries(runTests MobileAppManagerLib GTest::gtest GTest::gtest_main pthread)

#/******************************************************************************
# *                  Enable and Register Tests
# *                  Description: Enables test functionality in CMake and registers
# *                               the test executable as a test named 'MobileAppManagerTests'
# *****************************************************************************/
enable_testing()
add_test(NAME MobileAppManagerTests COMMAND runTests)

#/******************************** End of File ********************************/
