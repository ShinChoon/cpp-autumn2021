#include "boat.hpp"
//TODO: implement Boat's members
/* constructor
     * Initializes the corresponing members from the parameters.
    */
Boat::Boat(std::string register_number, 
            std::string owner,
            std::string name, double draft, 
            double power):Vehicle(register_number, owner){
        name_ = name;
        draft_ = draft;
        power_ = power;

}

/* Write
     * Writes the vehicle to the stream given as a parameter in the serialized format.
     * Format for Car:
B;<register number>;<owner>;<name>;<draft>;<power>\n
    */
void Boat::Write(std::ostream &stream){
    stream << "B;" << GetRegisterNumber() << ";"
           << GetOwner() << ";" << name_ << ";"
           << draft_ << ";" << power_ << std::endl;
}

/* Print
     * Writes the vehicle to the standard output in the serialized format (See Write).
    */
void Boat::Print(){
    Write(std::cout);
}

/* Read
     * Reads a Boat from the stream given as parameter, assuming that the vehicle
     * is stored in the serialized format (See Write) and starts immediately from 
     * the current position of the stream.
     * If the vehicle type (the first character) is wrong, returns NULL.
     * If the read was succesful, returns a pointer to a new Boat contructed with 
     * the data read. 
    */
Boat* Boat::Read(std::istream &stream)
{
    std::string register_number;
    std::string owner;
    std::string name;
    std::string input;
    std::string semicolon;
    double draft;
    double power;
    int length = stream.tellg();
    char *buffer = new char[length];
    stream.read(buffer, 1);
    if(*buffer != 'B')
    {
        delete[] buffer;
        std::cout << "NULL" << std::endl;
        return NULL;
    }
    else 
    {
        std::getline(stream, semicolon, ';');
        std::getline(stream, register_number, ';');

        std::getline(stream, owner, ';');
        std::getline(stream, name, ';');

        std::getline(stream, input, ';');
        draft = std::stod(input);

        std::getline(stream, input, ';');
        power = std::stod(input);
        Boat* temBoat =  new Boat(register_number, owner, name, draft, power);
        delete[] buffer;
        return temBoat;
    }
}