#include "printers.hpp"

void Printers::Add(std::string name, StringPrinter *printer)
{
    for (printersgroup::iterator j = printers_.begin(); j != printers_.end(); j++)
    {
        if (name == j->first)
        {
            throw std::invalid_argument("Duplicate index");
            // return;
        }
    }
    if (printer == nullptr)
    {
        throw std::invalid_argument("Invalid printer");
        // return;
    }
    
    printers_.insert(std::make_pair(name, printer));
}
StringPrinter &Printers::operator[](std::string name)
{
    bool findflag = false;
    for (printersgroup::iterator j = printers_.begin(); j != printers_.end(); j++)
    {
        if (name == j->first)
            findflag = true;
    }

    if (findflag == false)
    {
        throw std::invalid_argument("Unknown index");
    }
    return *(printers_[name]);
}

Printers &Printers::operator=(Printers &pr)
{
    for (auto i : pr.printers_)
    {
        std::string name = i.first;
        StringPrinter *printer = i.second->Clone();
        printers_.insert(std::make_pair(name, printer));
        // Add(name, SP);
    }
    return *this;
}

Printers::~Printers()
{
    for (auto i : printers_)
    {
        if (i.second)
        {
            delete i.second;
            i.second = nullptr;
        }
    }
    printers_.clear();
}