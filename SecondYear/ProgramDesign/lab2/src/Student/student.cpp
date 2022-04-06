#include "student.hpp"

Student::Student()
{
    first_name = "Ivan";
    last_name = "Ivanov";
    age = 18;
    group = "010101";
    average_score = 7.4;
}


Student::Student(std::string first_name, std::string last_name, short age, std::string group, double average_score)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
    this->group = group;
    this->average_score = average_score;
}



void Student::set_average_score(double average_score)
{
    this->average_score = average_score;
}



std::string Student::get_first_name()
{
    return first_name;
}


std::string Student::get_last_name()
{
    return last_name;
}


short Student::get_age()
{
    return age;
}


std::string Student::get_group()
{
    return group;
}


double Student::get_average_score()
{
    return average_score;
}

void Student::print_info()
{
    std::cout << first_name << " " << last_name << " " << age <<  " (" << group << ") " << average_score << std::endl; 
}
