#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Programm.hpp"


void show_map(const std::map<std::string, int> *mp);
std::map<std::string, int> get_map(int size, char* strs[]);

int main(int argc, char* argv[])
{
    std::ifstream file(argv[1]);

    if (file.is_open() && argc > 2)
    {
        std::map<std::string, int> mp = get_map(argc, argv);
        std::map<std::string, int>::iterator it;
        std::string text = ""; 
        int amount_before = 0, amount_after = 0;

        std::string str;
        while (file >> str)
        {
            amount_before++;
            it = mp.find(str);
            if (it != mp.end())
            {
                it->second++;
                if (it->second < 2)
                {
                    text += str + " ";
                }
                else
                {
                    amount_after--;
                }
                
            }else 
            {
                text += str + " ";
            } 
        }
        file.close();

        std::ofstream write_file(argv[1]);
        write_file << text;
        write_file.close(); 
        
        amount_after += amount_before;

        show_map(&mp); 
        std::cout << "\nAmount before: " << amount_before << std::endl;
        std::cout << "Amount after: " << amount_after << std::endl;
        
    }
    else if (!file.is_open()){
        std::cout << "Error, can't open file" << std::endl;
    }
    else
    {
        std::cout << "Error, There are no words for search." << std::endl;
        file.close();
    }



    std::cout << "\n\n";


    Programm pr("Star wars", "0.11.3");
    pr.set_last_verison_date("12.01.21");
    pr.set_size(3.2);
    pr.set_description("Game about stars and wars");
    pr.print_full_info();

    return 0;
}


void show_map(const std::map<std::string, int> *mp)
{
    std::cout << "\tResult:" << std::endl;
    for (auto p : *mp)
    {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}

std::map<std::string, int> get_map(int size, char* strs[])
{
    std::map<std::string, int> mp;
    for (int i = 2; i < size; i++)
    {
        mp.insert(std::pair<std::string, int>(strs[i], 0));
    }
    return mp;
}
