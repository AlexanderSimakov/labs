#include <iostream>
#include <math.h>

using namespace std;

double get_value() 
{
	double value;
	while (true) 
    {
		cout << "> ";
		cin >> value;

		if (cin.get() == '\n') 
        {
			break;
		}
		else 
        {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "<-- Wrong input -->\n" << endl;
		}
	}
	return value;
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
			cout << "Input number should be between [" << min << ", " << max << "]...\n" << endl;
		}
	}
}


int main()
{
	int user_choise;
	double func, x = 0, z, y, a;

	while (true) 
    {
		cout << "Enter z: " << endl;
		z = get_value();

		cout << "\n\nEnter a: " << endl;
		a = get_value();

		cout << "\n\n1)2x 2)x^2 3)x/3 : " << endl;
		user_choise = get_value_from_range(1, 3);


		if (z < 1) x = z * z;
		else if (z >= 1) x = z + 1;

		switch (user_choise)
		{
		case 1: func = x * 2; break;
		case 2: func = x * x; break;
		case 3: func = x / 3; break;
		default:
			break;
		}

		y = a * log(1 + pow(x, 1. / 5)) + pow(cos(func + 1), 2);
		cout << "\n\ny = " << y << endl;

		cout << "\nDo you want to continue?(1 - yes, 2 - no):" << endl;
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
