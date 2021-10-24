#include "aircraft.hpp"
#include <iostream>
#include <string>
//TODO: implement Aircraft's members
/* constructor
     * Initializes the corresponing members from the parameters.
    */
Aircraft::Aircraft(std::string register_number,
                   std::string owner,
                   std::string model, double wingspan, 
                   unsigned int cruise_speed) : Vehicle(register_number, owner)
{
    model_ = model;
    wingspan_ = wingspan;
    cruise_speed_ = cruise_speed;
}

/* Write
     * Writes the vehicle to the stream given as a parameter in the serialized format.
     * Format for AirCraft:
A;<register number>;<owner>;<model>;<wingspan>;<cruise_speed>\n
    */
void Aircraft::Write(std::ostream &stream){
    stream << "A;" << GetRegisterNumber() << ";"
           << GetOwner() << ";" << model_ << ";"
           << wingspan_ << ";" << cruise_speed_ << std::endl;
}

/* Print
     * Writes the vehicle to the standard output in the serialized format (See Write).
    */
void Aircraft::Print(){
    Write(std::cout);
}

/* Read
     * Reads an Aircraft from the stream given as parameter, assuming that the vehicle
     * is stored in the serialized format (See Write) and starts immediately from 
     * the current position of the stream.
     * If the vehicle type (the first character) is wrong, returns NULL.
     * If the read was succesful, returns a pointer to a new Aircraft contructed with 
     * the data read. 
    */
Aircraft* Aircraft::Read(std::istream &stream)
{
    std::string register_number;
    std::string owner;
    std::string model;
    std::string input;
    std::string semicolon;
    double wingspan;
    unsigned int cruise_speed;
    int length = stream.tellg();
    char *buffer = new char[length];
    stream.read(buffer, 1);
    if(*buffer != 'A')
    {
        delete[] buffer;
        return NULL;
    }
    else 
    {
        std::getline(stream, semicolon, ';');
        std::getline(stream, register_number, ';');

        std::getline(stream, owner, ';');
        std::getline(stream, model, ';');

        std::getline(stream, input, ';');
        wingspan = std::stod(input);

        std::getline(stream, input, ';');
        cruise_speed = std::stoul(input);
        Aircraft *temaircraft = new Aircraft(register_number, owner, model, wingspan, cruise_speed);
        delete[] buffer;
        return temaircraft;
    }
}