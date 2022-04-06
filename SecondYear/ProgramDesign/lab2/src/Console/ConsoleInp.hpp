#pragma once 
#include <string>
#include <regex>
#include <iostream>
#include "ConsoleOut.hpp"


class ConsoleInp
{
public:
	static double get_score();
	static int get_age();
	static std::string get_name(std::string user_info);
	static std::string get_group();
	static int get_number(bool is_positive = false, std::string line_for_user = "\n> ");
	static int get_number_from_range(int min, int max, std::string out_line = "\n> ");
	static double get_number_from_range(double min, double max, std::string out_line = "\n> ");
};
