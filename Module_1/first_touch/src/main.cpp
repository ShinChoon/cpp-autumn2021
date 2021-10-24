#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "first.hpp"
int main(void) {
    // Hello();
    std::string s1 = "Heasdfhsrdthi";
    std::string s2 = "Hello";

    std::cout << LongerLength(s1, s2) << std::endl;

    std::vector<int> numbers={100,2,40};
    numbers.push_back(5);
    numbers.push_back(6);
    std::cout << "Size of vector: " << numbers.size() << " Larget number is: " << LargestNumbers(numbers)<< std::endl;

    // double queue of integers, initialized as empty
    std::deque<std::string> queue;

    // Add three elements
    queue.push_back("Alvari");
    queue.push_back("Bemari");
    auto somename = "Cemmari";
    queue.push_back(somename);

    // Take out and delete the first element ("Alvari")
    // queue.pop_front();

    // check the status of the queue
    std::cout << "Size now: " << queue.size()
              << " -- is empty: " << (queue.empty() ? "true" : "false")
              << std::endl;
    std::cout << "First item: " << queue[0] << std::endl;

    // one way to walk through the queue
    // more info about 'size_type' below
    for (std::deque<std::string>::size_type i = 0; i < queue.size(); i++)
    {
        std::cout << i << ": " << queue[i] << std::endl;
    }
    return 0;
}
