#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../Console/ConsoleOut.hpp"

enum Buttons {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
 	ENTER = 13,
	KEU_UP = 72,
	KEY_DOWN = 80,
	ESC = 27  
#elif __linux__
	ENTER = 105, // i
	KEU_UP = 107, // k
	KEY_DOWN = 106, // j
	ESC = 110 // n
#endif
};

class Menu {
public:
	Menu();
	Menu(std::vector<std::string> lines);
	Menu(std::string title, std::vector<std::string> lines);

	int get_num_of_choisen_line();
	void add_line(std::string line);
	void set_lines(std::vector<std::string> lines);
	void set_title(std::string title);
	void set_start_with_first_line(bool is_start_with_first_line);
	void set_pointer_to_start();

private:
	bool is_start_with_first_line = false;
	int num_of_choisen_line = 0;
	std::vector<std::string> lines;
	std::string title;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	HANDLE std_handle;
	DWORD cWrittenChars;
#endif
	void print_lines();
	void print_title();
	void print_pointer();
	void clear();
};
