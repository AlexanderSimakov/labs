#include <iostream>
#include <math.h>

using namespace std;

long double get_factorial(int num) 
{
	long double factorial = 1;

	for (int i = 1; i <= num; i++) 
    {
		factorial *= i;
	}

	return factorial;
}

double get_value() 
{
	double value;
	while (true) 
    {
		cout << "\n> ";
		cin >> value;

		if (cin.get() == '\n') 
        {
			break;
		}
		else 
        {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "<-- Wrong input -->" << endl;
		}
	}
	return value;
}

double get_value_more_than(double num) 
{
	double value;
	while (true) 
    {
		value = get_value();
		if (value > num) 
        {
			return value;
		}
		else 
        {
			cout << "Value should be more than " << num << " ..." << endl;
		}
	}
}

double get_value_less_than(double num) 
{
	double value;
	while (true) 
    {
		value = get_value();
		if (value < num) 
        {
			return value;
		}
		else 
        {
			cout << "Value should be less then " << num << " ..." << endl;
		}
	}
}

double get_value_from_range(int min, int max) 
{
	double value;

	while (true) 
    {
		value = get_value();
		if (value >= min && value <= max) 
        {
			return value;
		}
		else 
        {
			cout << "Value should be between [" << min << ", " << max << "]..." << endl;
		}

	}
}

int main() {
	double a, b, h;
	long double s, y, razn;
	int n;

	while (true) 
    {

		cout << "Enter range [a, b] and step h" << endl;
		cout << "Enter a: ";
		a = get_value();

		cout << "\nEnter b(b > a): ";
		b = get_value_more_than(a);

		cout << "\nEnter h(h < b-a): ";
		h = get_value_less_than(b - a);

		cout << "\nEnter n: ";
		n = get_value();

		cout << endl;

		for (; a <= b; a += h) 
        {
			s = 0;

			for (int k = 0; k <= n; k++) 
            {
				s += pow(-1, k) * (pow(a, 2 * k + 1)) / get_factorial(2 * k + 1);
			}
			y = sin(a);
			razn = abs(y - s);

			cout << "a = " << a << "    \tS(x) = " << s << "    \tY(x) = " << y << "    \t|Y(x) - S(x)| = " << razn << endl;

		}

		cout << "\nDo you want to continue?(1 - Yes, 2 - No):";
		if (get_value_from_range(1, 2) == 2) 
        {
			break;
		}
		else 
        {
			cout << "\n------------------------------" << endl;
			cout << "------------------------------\n" << endl;
		}
	}

	return 0;
}

