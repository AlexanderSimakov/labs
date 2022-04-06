#include "StudentList.hpp"


StudentList::StudentList(){ }


StudentList::StudentList(std::list<Student> student_list)
{
    this->student_list.assign(student_list.begin(), student_list.end());
}


void StudentList::add(std::string first_name, std::string last_name, short age, std::string group, double average_score)
{
    student_list.push_back(Student(first_name, last_name, age, group, average_score));
}


void StudentList::show()
{
    int i = 1;
    for (auto student : student_list)
    {
        std::cout << i++ << ") ";
        student.print_info();
    }
    std::cout << std::endl;
}


void StudentList::show_student_by_group(std::string group)
{ 
    std::list<Student>::iterator it = std::find_if(student_list.begin(), student_list.end(), 
        [group](Student st)
        { 
            return st.get_group() == group; 
        }); 

    if (it != student_list.end())
    {
        it->print_info();
    }
    else
    {
        std::cout << "<-- There are no such student or group -->" << std::endl;
    }
}


void StudentList::remove(std::string first_name, std::string last_name, std::string group)
{
    student_list.remove_if(
        [first_name, last_name, group] (Student s) 
        { 
            return s.get_first_name() == first_name && 
                   s.get_last_name() == last_name &&
                   s.get_group() == group;
        });
}


void StudentList::remove_not_unique_names()
{ 
    student_list.unique(
        [](Student s1, Student s2) 
        {
            return s1.get_first_name() == s2.get_first_name(); 
        }); 
}


StudentList StudentList::get_students_by_group(std::string group)
{  
    std::list<Student> new_student_list(student_list.size());
    auto it = std::copy_if(student_list.begin(), student_list.end(), new_student_list.begin(), 
        [group](Student s)
        { 
            return s.get_group() == group; 
        });

    new_student_list.resize(distance(new_student_list.begin(), it));
    return StudentList(new_student_list); 
}


bool StudentList::is_there_students_with_name(std::string first_name)
{
    return std::any_of(student_list.begin(), student_list.end(), 
        [first_name](Student s) 
        {
            return s.get_first_name() == first_name; 
        }); 
}


bool StudentList::is_there_students_with_name(std::string first_name, std::string last_name)
{
    return std::any_of(student_list.begin(), student_list.end(), 
        [first_name, last_name](Student s) 
        {
            return s.get_first_name() == first_name && s.get_last_name() == last_name; 
        }); 
}


bool StudentList::is_empty()
{
    return student_list.size() == 0;
}


void StudentList::sort_by_average_grade_up_to_down()
{
    student_list.sort(comp_up_down);
}


bool StudentList::comp_up_down(Student s1, Student s2)
{
    return s1.get_average_score() > s2.get_average_score();
}


void StudentList::sort_by_average_grade_down_to_up()
{
    student_list.sort(comp_down_up);
}


bool StudentList::comp_down_up(Student s1, Student s2)
{
    return s1.get_average_score() < s2.get_average_score();
}


StudentList StudentList::get_students_by_avereage_score(int start, int end)
{
    std::list<Student> new_student_list(student_list.size());
    auto it = std::copy_if(student_list.begin(), student_list.end(), new_student_list.begin(),
        [start, end](Student st)
        { 
            return st.get_average_score() >= start && st.get_average_score() <= end; 
        }); 

    new_student_list.resize(distance(new_student_list.begin(), it));
    return StudentList(new_student_list);
}


StudentList StudentList::StudentList::get_students_by_age(int start, int end)
{
    std::list<Student> new_student_list(student_list.size());
    auto it = std::copy_if(student_list.begin(), student_list.end(), new_student_list.begin(),
        [start, end](Student st)
        { 
            return st.get_age() >= start && st.get_age() <= end; 
        }); 

    new_student_list.resize(std::distance(new_student_list.begin(), it));
    return StudentList(new_student_list);
}
