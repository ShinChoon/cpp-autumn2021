#include <fstream>
#include <sstream>
#include "register.hpp"
#include "aircraft.hpp"
#include "boat.hpp"
//TODO: implement Register's members
/* destructor
     * Does what destuctors should.
    */
Register::~Register(){
    for (Vehicle *i : vehicles_)
    {
        delete i;
    }
    vehicles_.clear();
}

/* Add
     * Adds the parameter to the vehicle vector
    */
void Register::Add(Vehicle *v){
    if (v!=NULL)
        vehicles_.push_back(v);
}

/* Save
     * Saves the vehicles to the file named by the parameter with each vehicle on its
     * own line in the serialized format.
    */
void Register::Save(const std::string &filename) const{
    std::ofstream os(filename);
    for(auto i : vehicles_){
        // if (dynamic_cast<Aircraft *>(i) != nullptr)
        //     os << "A;"; 
        i->Write(os);

    }
    os.close();
}

/* ReadLine
     * Reads a vehicle from the stream given as a parameter assuming a serialized format, and 
     * adds it to the register. Reads a whole line from the stream whether or not constructing 
     * the vehicle was succesful.
     * Returns true if a vehicle was added, false otherwise.
    */
bool Register::ReadLine(std::istream &stream){
    if (stream)
    {
        std::string paralist;
        std::getline(stream, paralist);
        std::istringstream iss(paralist);
        if(paralist[0]=='A')
        {
            std::cout << "paralist: "<< paralist << std::endl;
            Add(Aircraft::Read(iss));
        }
        else if (paralist[0] == 'B')
        {
            std::cout << "paralist: " << paralist << std::endl;
            Add(Boat::Read(iss));
        }
        else
            return false;
        
        return true;


    }
    else
    {
        stream.clear((stream.rdstate() & ~std::ios::goodbit) | std::ios::failbit);
        return false;
    }
}

/* Load
     * Reads all vehicles from a file and adds them to the register.
     * Each vehicle is on a different line. On an error the line is discarded and reading is
     * continued from the next line.
     * Returns the number of vehicles added.
     * If file opening fails, the return value should be -1.
    */
int Register::Load(const std::string &filename){
    std::ifstream istr(filename);
    if (istr.rdstate() & (istr.failbit | istr.badbit))
        return -1;
    else
    {
        int count = 0;
        while (!istr.eof())
        {
            std::string line;
            std::getline(istr, line);
            std::istringstream iss(line);
            if (ReadLine(iss)==true)
                count++;
        }
        istr.close();
        
        
        return count;
    }
}

/* Print
     * Prints all the vehicles in the register to the standard output each on a different line
     * in the serialized format.
    */
void Register::Print(){
    for(auto i : vehicles_){
        i->Print();
    }
}

/* Size
     * Returns the number of vehicles in the register.
    */
size_t Register::Size() const{
    return vehicles_.size();
}