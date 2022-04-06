cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Lab2)

add_subdirectory(Console)
add_subdirectory(Menu)
add_subdirectory(Student)
add_subdirectory(StudentList)

set(Lab2_source_files main.cpp)
add_executable(Lab2 ${Lab2_source_files})

target_link_libraries(Lab2 StudentList)
target_link_libraries(Lab2 Menu)
target_link_libraries(Lab2 Console)
target_link_libraries(Lab2 Student)
