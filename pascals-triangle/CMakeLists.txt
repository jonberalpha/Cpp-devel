cmake_minimum_required(VERSION 3.0.0)
project(pascal VERSION 0.1.0)

# add pascal to library
add_library(pascal src/pascal.cpp)
target_include_directories(pascal PUBLIC include)

# A demo-executable which takes a line number from command line and prints out the pascals triangle
add_executable(pascal-demo src/pascal_demo.cpp)
target_link_libraries(pascal-demo PRIVATE pascal)

# A testing-executable to test the pascal library
find_package(Catch2 REQUIRED)
add_executable(pascal-test test/pascal.test.cpp)
target_link_libraries(pascal-test PRIVATE pascal Catch2::Catch2)

include(Catch)
catch_discover_tests(pascal-test)
