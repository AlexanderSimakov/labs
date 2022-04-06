#pragma once
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include "../Student/student.hpp"


class StudentList
{
private:
    std::list<Student> student_list;

    static bool comp_up_down(Student s1, Student s2);
    static bool comp_down_up(Student s1, Student s2);

public:
    StudentList(); 
    StudentList(std::list<Student> Student_list); 

    void add(std::string first_name, std::string last_name, short age, std::string group, double average_score); 
    void show(); 
    void show_student_by_group(std::string group);
    void remove(std::string first_name, std::string last_name, std::string group);
    void remove_not_unique_names();

    StudentList get_students_by_group(std::string group);

    bool is_there_students_with_name(std::string first_name); 
    bool is_there_students_with_name(std::string first_name, std::string last_name); 
    bool is_empty();

    void sort_by_average_grade_up_to_down(); 
    void sort_by_average_grade_down_to_up(); 

    StudentList get_students_by_avereage_score(int start, int end);
    StudentList get_students_by_age(int start, int end);
};

