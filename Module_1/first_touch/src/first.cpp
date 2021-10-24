#include <vector>
#include <iostream>
#include <deque>
#include <list>
#include "first.hpp"

void Hello() {
    std::string str = "Hello world!";
    std::cout << str << std::endl;
    return;
    }


int LongerLength(const std::string& a, const std::string& b){
    std::cout << "length a: " << a.length() << std::endl;
    std::cout << "length b: " << b.length() << std::endl;
    if(a.size()>b.size())
        return a.size();

    else
        return b.size();

}

int LargestNumbers(const std::vector<int> &v)
{
    int largest = -1000;
    for(unsigned int i=0; i<v.size(); i++){
        if(v[i]>largest){
            largest=v[i];
        }

    }
    return largest;
}