cmake_minimum_required(VERSION 3.0.0)
project(automatic-seat-assignment VERSION 0.1.0)

# add asa to library
add_library(asa src/asa.cpp)
target_include_directories(asa PUBLIC include)

# A demo-executable
add_executable(asa-demo src/asa_demo.cpp)
target_link_libraries(asa-demo PRIVATE asa)

# A testing-executable to test the asa library
find_package(Catch2 REQUIRED)
add_executable(asa-test test/asa.test.cpp)
target_link_libraries(asa-test PRIVATE asa Catch2::Catch2)

include(Catch)
catch_discover_tests(asa-test)
