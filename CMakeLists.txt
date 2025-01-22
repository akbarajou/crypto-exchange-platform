# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(CryptoExchange VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable warnings for better code quality
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

# Include directories
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Create the main executable
add_executable(CryptoExchange ${SOURCES} ${HEADERS})

# Add tests
# enable_testing()

# Add testing executable
# add_executable(run_tests tests/test_main.cpp)mkdir build && cd build

# target_include_directories(run_tests PRIVATE include)
# add_test(NAME AllTests COMMAND run_tests)

# Optional: Link external libraries (if applicable)
# target_link_libraries(CryptoTradingPlatform PRIVATE some_library)


# Print project configuration
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Project Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
