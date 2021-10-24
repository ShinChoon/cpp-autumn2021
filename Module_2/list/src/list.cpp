#include "list.hpp"
#include <iostream>

// Implement the functions here

/** Read all lines from the stream into the list. Newline characters are not
 * stored in the list. Returns the stream. **/
std::istream &GetLines(std::istream &is, std::list<std::string> &list){
    std::string str = "";
    list.clear();
    while(getline(is, str)){
        list.push_back(str);
        if (str == "\n")
            break;
    }

    return is;
}

/** Print the list, with a newline after each entry. **/
void Print(const std::list<std::string> &list){
    for( auto i : list){
        std::cout << i << std::endl;
    }

}

/** Sort the list and remove all duplicate entries. **/
void SortAndUnique(std::list<std::string> &list){
    list.sort();
    list.unique();
}