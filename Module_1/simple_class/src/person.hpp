#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON
#include <string>
// define your Person class here
class Person{
    public:
    Person(std::string Name, int birthyear);
    const std::string& GetName();
    int GetAge(int thisyear);
    private:
        std::string Name_;
        int birthyear_;

};

#endif