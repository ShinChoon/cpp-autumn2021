
//commments
#include <vector>
#include <string>
#include <iostream>

int main() {
    // double queue of integers, initialized as empty
    std::deque<std::string> queue;

    // Add three elements
    queue.push_back("Alvari");
    queue.push_back("Bemari");
    queue.push_back("Cemmari");

    // Take out and delete the first element ("Alvari")
    queue.pop_front();

    // check the status of the queue
    std::cout << "Size now: " << queue.size()
            << " -- is empty: " << (queue.empty() ? "true" : "false")
            << std::endl;
    std::cout << "First item: " << queue[0] << std::endl;

    // one way to walk through the queue
    // more info about 'size_type' below
    for (std::deque<std::string>::size_type i = 0; i < queue.size(); i++) {
        std::cout << i << ": " << queue[i] << std::endl;
    }
}
