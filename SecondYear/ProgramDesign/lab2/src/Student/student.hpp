#pragma once
#include <string>
#include <iostream>


class Student
{
private:
    std::string first_name;
    std::string last_name;
    short age;
    std::string group;
    double average_score;

public:
    Student();
    Student(std::string first_name, std::string last_name, short age, std::string group, double average_score);

    void set_average_score(double average_score);

    std::string get_first_name();
    std::string get_last_name();
    short get_age();
    std::string get_group();
    double get_average_score();

    void print_info();
};
