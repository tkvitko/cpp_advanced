cmake_minimum_required(VERSION 3.20)

add_subdirectory(/Users/tkvitko/c/netology/cpp_advanced/testing_catch2_linked_list_01/testing_catch2_linked_list_01/Catch2 Catch2-build) 
add_executable(List-test test-main.cpp List.cpp)
target_link_libraries(List-test PRIVATE Catch2::Catch2)
