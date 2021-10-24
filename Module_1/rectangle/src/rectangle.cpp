#include "rectangle.hpp"

#include <iostream>

// Write you function here and test it with the main.

void Rectangle() {
    double width=0;
    double height = 0;
    std::cout << "Please enter width and height" << std::endl;
    std::cin >> width;
    std::cin >> height;
    
    double area = width * height;
    double circumference = (width + height) * 2;

    std::cout << "Area: "<< area <<std::endl;
    std::cout << "Circumference: " << circumference << std::endl;
}

