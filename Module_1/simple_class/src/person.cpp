#include "person.hpp"
// define your Person class' functions here

Person::Person(std::string Name, int birthyear){
    Name_ = Name;
    birthyear_ = birthyear;
}

int Person::GetAge(int thisyear)
{
    int age = thisyear - birthyear_;
    return age;
}

const std::string& Person::GetName(){
    return Name_;
}