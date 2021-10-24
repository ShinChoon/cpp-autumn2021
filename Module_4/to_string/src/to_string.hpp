#ifndef AALTO_ELEC_CPP_TO_STRING_CLASS
#define AALTO_ELEC_CPP_TO_STRING_CLASS
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <set>
/* As an introduction to templates you will write and specialize a template function 
 * for formatting the contents of a container (string, vector, list, ...) into a string, 
 * assuming that the elements of the container are printable (with the << operator). 
 *
 * This function is called ToString and it returns the container contents in the following format 
 * (assuming a container of strings with three elements: "foo", "bar" and "baz"): 
{ foo, bar, baz }
 * (assuming a container of ints with three elements: 10, -5 and 4): 
{ 10, -5, 4 }
 * When passed a std::string, the function should, instead of returning a list of characters { f, o, o, b, a, r }, 
 * just put double quotes around the string:
"foobar"
 * Additionally, overload the function with a version that, instead of a container, 
 * takes begin and end iterators, and formats the contents in the format specified above for containers 
 * (no special handling for string iterators).
 *
 * Notes:
 * You may assume that std::strings have their regular interface. 
 * For other containers, only use the iterator interface (begin and end functions).
 * Your functions must work with at least bidirectional iterators. Note that such 
 * iterators do not have operators + and - (but they do have ++ and --).
 * If you'd really want to provide printing support for containers, 
 * you should write operator<< for them instead of a ToString function.
 * This would allow printing containers that contain other containers, etc.
 */


// process double/int sets
template <typename T>
std::string ToString(T a)
{
    std::string ans;
    typename T::iterator end_ = a.end();
    end_--;
    std::stringstream stream;
    stream << "{ ";
    typename T::iterator i = a.begin();
    for (; i != end_; i++)
    {
        stream << *i;
        stream << ", "; 
    }
    stream << *i << " }";
    ans = stream.str();
    return ans;
}

// Specialization for string
template<>
std::string ToString<std::string>(std::string s){
    std::string ans;
    for(auto i: s){
        ans += i;
    }
    ans  = '"' + ans + '"';
    return ans;
}

//overload for string iterator
template <typename T>
std::string ToString(T a, T b)
{
    std::string ans;
    T end_ = b;
    end_--;
    std::stringstream stream;
    stream << "{ ";
    T i = a;
    for (; i != end_; i++)
    {
        stream << *i << ", ";
    }
    stream << *i << " }";
    ans = stream.str();
    return ans;
}


#endif