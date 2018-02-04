cmake_minimum_required(VERSION 3.5)

project(fanControler)
project(fanControler_test)

add_definitions(-std=c++17)
add_subdirectory(googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(".")

file(GLOB allfiles *.cpp)
file(GLOB testfiles *_test.cpp)
file(GLOB mainfiles main.cpp)
list(REMOVE_ITEM allfiles ${testfiles})
list(REMOVE_ITEM allfiles ${mainfiles})
list(REMOVE_ITEM testfiles ${mainfiles})


message("appfiles: ${allfiles}")
message("testfiles: ${testfiles}")

# add the executable
add_executable(fanController ${allfiles} ${mainfiles})

add_executable(fanContoller_test ${allfiles} ${testfiles})
target_link_libraries(fanContoller_test gtest gtest_main)
add_test(fanContoller_test fanContoller_test)
