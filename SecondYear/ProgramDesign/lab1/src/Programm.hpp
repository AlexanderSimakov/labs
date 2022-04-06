#pragma once
#include <string>
#include <iostream>


class Programm
{
public:
    Programm();
    Programm(std::string name, std::string version);

    void set_name(std::string name);
    void set_description(std::string description);
    void set_size(double size);
    void set_version(std::string version);
    void set_last_verison_date(std::string last_verison_date);

    std::string get_name();
    std::string get_description();
    double get_size();
    std::string get_version();
    std::string get_last_verison_date();

    void print_full_info();

private:
    std::string name = "";
    std::string description = "";
    double size = 0;
    std::string version = "";
    std::string last_verison_date = "";
};


