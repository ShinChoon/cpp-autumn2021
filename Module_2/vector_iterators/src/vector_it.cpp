#include <iostream>
#include <vector>
#include "vector_it.hpp"

// Implement the functions here

std::vector<int> ReadVector(){
    int value = 0;
    std::vector<int> example;
    std::cout << "Input value:" << std::endl;
    while(std::cin>> value)
    {
            if (*typeid(value).name() == 'i')//int type name() = i
                example.push_back(value);
            else
                break;
    }

    // for(auto i: example){
    //     std::cout << "example element : " << i << std::endl;
    // }
    return example;
}

// Prints the sum of each pair of adjacent elements: input: 1 2 3 4 !\n, output: 3 5 7 \n
// The vector should not be modified and is thus declared as a const
void PrintSum1(const std::vector<int>& example){
    int value = 0;
    int postvalue = 0;
    std::vector<int> result;
    std::vector<int>::const_iterator it = example.begin();
    value = *it;
    postvalue = *(++it);
    for (; it != example.end();)
    {
        value += postvalue;
        result.push_back(value);
        value = *it;
        postvalue = *(++it);
    }

// //input
    // std::cout << "input: ";
    // for (auto i : example)
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << " !,";

    for(auto i : result)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
void PrintSum2(const std::vector<int>& example)
{
    int value = 0;
    int postvalue = 0;
    std::vector<int> result;
    std::vector<int>::const_iterator ib = example.begin();
    std::vector<int>::const_iterator ie = example.end();
    value = *ib;
    postvalue = *--ie;
    for (; ib < ie;)
    {

        value += postvalue;
        result.push_back(value);
        value = *++ib;
        postvalue = *--ie;
        
    }

    // //input
    // std::cout << "input: ";
    // for (auto i : example)
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << " !\n,";

    for (auto i : result)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
