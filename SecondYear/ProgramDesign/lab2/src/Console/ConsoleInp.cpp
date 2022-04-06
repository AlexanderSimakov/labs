#include "ConsoleInp.hpp"

double ConsoleInp::get_score()
{
	double number;
	while (true) 
	{
		std::cout << "\nScore: ";
		std::cin >> number;

		if (std::cin.get() == '\n') 
		{
			if (number > 0 && number <= 10) return number;
			else ConsoleOut::show_error("Input number should be between [0, 10]");
		}
		else 
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			ConsoleOut::show_error("Wrong input");
		}
	}
	return number;
}

std::string ConsoleInp::get_name(std::string user_info)
{
	std::string name;
	while (true)
	{
		std::cout << user_info;
		std::cin >> name;

		if (std::regex_match(name, std::regex("[a-zA-Z]{2,20}"))){
			return name;
		}

		std::cout << "Invalid name" << std::endl;
	}
}

std::string ConsoleInp::get_group()
{
	std::string group;
	while (true)
	{
		std::cout << "\nGroup: ";
		std::cin >> group;

		if (std::regex_match(group, std::regex("[0-9]{6}"))){
			return group;
		}

		std::cout << "Invalid group" << std::endl;
	}
}

int ConsoleInp::get_number(bool is_positive, std::string line_for_user) 
{
	int number;
	while (true) 
	{
		std::cout << line_for_user;
		std::cin >> number;

		if (std::cin.get() == '\n') 
		{
			if (is_positive && number >= 0) break;
			else if (!is_positive) break;
			else ConsoleOut::show_error("Number should be positive");
		}
		else 
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			ConsoleOut::show_error("Wrong input");
		}
	}
	return number;
}

int ConsoleInp::get_number_from_range(int min, int max, std::string line_for_user) 
{
	int number;
	while (true) 
	{
		number = get_number(false, line_for_user);
		if (number >= min && number <= max) return number;
		else ConsoleOut::show_error("Input number should be between [" + std::to_string(min) + ", " + std::to_string(max) + "]");
	}
}
