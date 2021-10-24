#include "aviary.hpp"

void Aviary::Add(Bird* bird_){
    if(bird_ != NULL)
        inhabitants_.push_back(bird_);
    else
        throw std::logic_error("pointer is empty");
}

void Aviary::SpeakAll(std::ostream &os) const{
    for(auto i : inhabitants_){
        i->Speak(os);
    }
}

birdsnum Aviary::Size() const{
    return inhabitants_.size();
}

const Bird* Aviary::operator[](size_t which)const {
    try
    {
        return inhabitants_[which];
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
        throw; // rethrows the exception object of type std::length_error
    }
}

Bird* Aviary::operator[](size_t which)
{
    // if (which < inhabitants_.size())
    //     return inhabitants_[which];
    // else
    //     throw std::out_of_range("index is out of bounds");
    try
    {
        return inhabitants_[which];
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
        throw; // rethrows the exception object of type std::length_error
    }
}

Aviary::~Aviary(){
    for(auto i : inhabitants_){
        delete i;
    }
}


Aviary& Aviary::operator=(const Aviary& avi){
    avi.Size();
    return *this;
}

