#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include "StudentList/StudentList.hpp"
#include "Console/ConsoleOut.hpp"
#include "Console/ConsoleInp.hpp"
#include "Menu/menu.hpp"



void init_list(StudentList* list);
void init_menu(Menu* menu);
void show(StudentList* list);
void show_by_group(StudentList* list);
void add(StudentList* list);
void sort_by_average_grade_down_to_up(StudentList* list);
void sort_by_average_grade_up_to_down(StudentList* list);
void find_by_average_score(StudentList* list);
void find_by_age(StudentList* list);
void is_there_student_with_name(StudentList* list);
void is_empty_list(StudentList* list);
void remove(StudentList* list);
void remove_not_unique_names(StudentList* list);


int main(){
    StudentList students;
    init_list(&students);

    Menu menu;
    init_menu(&menu);

    while (true)
    {
        switch (menu.get_num_of_choisen_line())
        {
            case 0: show(&students); break;
            case 1: show_by_group(&students); break;
            case 2: add(&students); break;
            case 3: sort_by_average_grade_down_to_up(&students); break;
            case 4: sort_by_average_grade_up_to_down(&students); break;
            case 5: find_by_average_score(&students); break;
            case 6: find_by_age(&students); break;
            case 7: is_there_student_with_name(&students); break;
            case 8: is_empty_list(&students); break;
            case 9: remove(&students); break;
            case 10: remove_not_unique_names(&students); break;
            case 11: return 0;
            default: break;
        }
    } 

    return 0;
}

void init_list(StudentList* list)
{
    list->add("Alexander", "Ivanov",        12, "010901", 7.1);
    list->add("Boris",     "Esenin",        18, "010901", 8.7);
    list->add("Ivan",      "Mayakovskiy",   19, "010902", 9.8);
    list->add("Ivan",      "Roy",           25, "010902", 1.3);
    list->add("Dmitry",    "Pasternak",     31, "010902", 10.4);
    list->add("Daniil",    "Petrovich",     23, "010903", 5.8);
}

void init_menu(Menu* menu)
{
    menu->set_title("<-  Accouts Manage  ->");
    menu->set_lines({ " Show",
                      " Show by group",
                      " Add",
                      " Sort by average grade from down to up",
                      " Sort by average grade from up to down",
                      " Find students by average score",
                      " Find students by age",
                      " Is there student with name",
                      " Is empty",
                      " Remove",
                      " Remove student with not uniqe names",
                      " Exit" });
}

void show(StudentList* list)
{
    ConsoleOut::show_title("List");
    list->show();
    ConsoleOut::pause();
}

void show_by_group(StudentList* list)
{
    ConsoleOut::show_title("Show students by group");
    std::string group = ConsoleInp::get_group();
    StudentList l = list->get_students_by_group(group);

    if (l.is_empty())
        ConsoleOut::show_error("There are no such group");
    else
        l.show();

    ConsoleOut::pause();
    ConsoleOut::getchar();
}

void add(StudentList* list)
{
    ConsoleOut::show_title("Add new student");

    std::string first_name = ConsoleInp::get_name("\nFirst name: ");
    std::string last_name = ConsoleInp::get_name("\nLast name: ");
    std::string group = ConsoleInp::get_group();
    short age = ConsoleInp::get_number_from_range(16, 99, "\nAge: ");
    double average_score = ConsoleInp::get_score();

    list->add(first_name, last_name, age, group, average_score);
    ConsoleOut::show_info("Student was added");

    ConsoleOut::pause();
}

void sort_by_average_grade_down_to_up(StudentList* list)
{
    list->sort_by_average_grade_down_to_up();
    ConsoleOut::show_info("Students was sorted by average grade from down to up");
    ConsoleOut::pause();
}

void sort_by_average_grade_up_to_down(StudentList* list)
{
    list->sort_by_average_grade_up_to_down();
    ConsoleOut::show_info("Students was sorted by average grade from up to down");
    ConsoleOut::pause();
}

void find_by_average_score(StudentList* list)
{
    ConsoleOut::show_title("Find by average score");

    int start = ConsoleInp::get_number_from_range(0, 10, "\nFrom: ");
    int end = ConsoleInp::get_number_from_range(start, 10, "\nTo: ");

    StudentList l = list->get_students_by_avereage_score(start, end);
    l.show();

    ConsoleOut::pause();
}

void find_by_age(StudentList* list)
{
    ConsoleOut::show_title("Find by age");

    int start = ConsoleInp::get_number_from_range(16, 99, "\nFrom: ");
    int end = ConsoleInp::get_number_from_range(start, 99, "\nTo: ");

    StudentList l = list->get_students_by_age(start, end);
    l.show();

    ConsoleOut::pause();
}

void is_there_student_with_name(StudentList* list)
{
    ConsoleOut::show_title("Is there student with name");


    std::string name = ConsoleInp::get_name("\nName: ");
    if (list->is_there_students_with_name(name)) 
        ConsoleOut::show_info("YES");
    else 
        ConsoleOut::show_info("NO");

    ConsoleOut::pause();
}

void is_empty_list(StudentList* list)
{
    if (list->is_empty())
        ConsoleOut::show_info("There are no students");
    else
        ConsoleOut::show_info("There are some students");
    ConsoleOut::pause();
}

void remove(StudentList* list)
{
    ConsoleOut::show_title("Remove student");

    std::string first_name = ConsoleInp::get_name("\nFirst name: ");
    std::string last_name = ConsoleInp::get_name("\nLast name: ");
    std::string group = ConsoleInp::get_group();
   
    list->remove(first_name, last_name, group);
    ConsoleOut::show_info("Student was removed");
    ConsoleOut::pause();
    ConsoleOut::getchar();
}

void remove_not_unique_names(StudentList* list)
{
    list->remove_not_unique_names();
    ConsoleOut::show_info("Students with no uniqe names was removed");
    ConsoleOut::pause();
}
