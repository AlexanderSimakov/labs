#include <iostream>
#include <math.h>

using namespace std;


double get_value() {
    double value;
    while (true) {
        cout << "\n> ";
        cin >> value;

        if (cin.get() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "<-- Неправильный ввод -->" << endl;
        }
    }
    return value;
}

double get_value_from_range(int min, int max) {
    double value;

    while (true) {
        value = get_value();
        if (value >= min && value <= max) {
            return value;
        }
        else {
            cout << "Введенное значение должно принадлежать промежутку [" << min << ", " << max << "]..." << endl;
        }

    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double x, y, z, result;

    while (true) {
        cout << "Введите x: ";
        x = get_value();

        cout << "\nВведите y: ";
        y = get_value();

        cout << "\nВведите z: ";
        z = get_value();

        result = (2 * cos(x - 2. / 3) * (1 + pow(z, 2) / (3 - pow(z, 2) / 5))) / (1. / 2 + pow(sin(y), 2));

        cout << "\nРезультат: " << result << endl;


        cout << "\nЖелаете продолжить?(1 - да, 2 - нет):";
        if (get_value_from_range(1, 2) == 2) {
            break;
        }
        else {
            cout << "\n--------------------------------" << endl;
            cout << "--------------------------------\n" << endl;
        }
    }

    return 0;
}

