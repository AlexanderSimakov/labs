#include "Programm.hpp"

Programm::Programm(){ }

Programm::Programm(std::string name, std::string version)
{
    this->name = name;
    this->version = version;
}

void Programm::set_name(std::string name)
{
    this->name = name; 
}

void Programm::set_description(std::string description)
{
    this->description = description;
}

void Programm::set_size(double size)
{
    this->size = size;
}

void Programm::set_version(std::string version)
{
    this->version = version;
}

void Programm::set_last_verison_date(std::string last_verison_date)
{
    this->last_verison_date = last_verison_date;
}

std::string Programm::get_name()
{
    return name;
}

std::string Programm::get_description()
{
    return description;
}

double Programm::get_size()
{
    return size;
}

std::string Programm::get_version()
{
    return version;
}

std::string Programm::get_last_verison_date()
{
    return last_verison_date;
}

void Programm::print_full_info()
{
    std::cout << "------ " << name << " " << version << " ------" << std::endl;
    std::cout << description << std::endl;
    std::cout << "Date: " << last_verison_date << std::endl;
    std::cout << "Size: " << size << "Gb" << std::endl;
}
