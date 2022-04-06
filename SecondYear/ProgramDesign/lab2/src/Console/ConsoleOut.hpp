#pragma once
#include <string>
#include <iostream>

#if __linux__
#include <termios.h>
#include <stdio.h>

static struct termios old, current;
#endif


enum Color 
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	Black = 0, Blue = 1,    Green = 2,   Cyan = 3,
	Red = 4,   Magenta = 5, Yellow = 14, White = 15  
#elif __linux__
	Black = 30, Blue = 34,    Green = 32,  Cyan = 36,
	Red = 31,   Magenta = 35, Yellow = 33, White = 37
#endif
};

class ConsoleOut
{
#if __linux__
private:
	static void initTermios();
	static void resetTermios(void);
#endif

public:
    static void pause();
    static char getchar();
    static void clear();
    
    static void show_error(std::string message, std::string pref = "\t", std::string post = "\n");
	static void show_title(std::string title, std::string pref = "\t", std::string post = "\n");
	static void show_info(std::string info, std::string pref = "\t", std::string post = "\n");
	static void set_color(Color color);
	static void set_default_color();
};
