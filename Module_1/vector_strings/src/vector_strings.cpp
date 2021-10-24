#include "vector_strings.hpp"

#include <iostream>
#include <vector>
std::string nameInput="";
std::vector<std::string> str_vector;
void Adder(std::vector<std::string>& names) {
    std::cout << "Enter a name:" << std::endl;
    std::cin >> nameInput;
    names.push_back(nameInput);
    std::cout << "Number of names in the vector:" << std::endl;
    std::cout << names.size() << std::endl;
}

void Remover(std::vector<std::string>& names) {
    std::cout << "Removing the last element:" << std::endl;
    std::cout << names.back() << std::endl;
    names.pop_back();
}

void Printer(std::vector<std::string>& names) {
    for (unsigned int i = 0; i < names.size(); i++)
    {
        std::cout << names[i] << std::endl;
    }
}

void CMDReader() {

    std::string instru = "";
    std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl;
    while(1)
    {
        std::cout << "Enter a command:" << std::endl;
        std::cin >> instru;
        if (instru == "ADD")
            Adder(str_vector);
        else if (instru == "REMOVE")
            Remover(str_vector);

        else if (instru == "PRINT")
            Printer(str_vector);

        else if (instru == "QUIT") break;
    }
}
