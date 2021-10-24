#include "diagonal_printer.hpp"

DiagonalPrinter *DiagonalPrinter::Clone() const
{
    return new DiagonalPrinter(firstline, lastline, os_);
}

StringPrinter &DiagonalPrinter::operator()(const std::string &str)
{
    int linenum = str.size();
    if (firstline.size() != 0)
    {
        this->os_ << firstline << std::endl;
    }
    for (size_t sizeloop = 0; sizeloop < str.size(); sizeloop++)
    {
        for (size_t lnum = 0; lnum < sizeloop; lnum++)
        {
            this->os_ << " ";
        }
        this->os_ << str[sizeloop];
        for (size_t lnum = linenum - 1; lnum > 0; lnum--)
        {
            this->os_ << " ";
        }
        this->os_ << std::endl;
        linenum--;
    }
    if (lastline.size() != 0)
    {
        this->os_ << lastline << std::endl;
    }

    return *this;
}