set(StudentList_source_files
    StudentList.hpp
    StudentList.cpp
)

add_library(StudentList ${StudentList_source_files})

target_link_libraries(StudentList Student)
