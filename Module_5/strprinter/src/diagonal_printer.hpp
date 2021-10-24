#ifndef DIAGONAL_PRINTER_H
#define DIAGONAL_PRINTER_H

#include <iterator>
#include <sstream>
#include "string_printer.hpp"
/* Add include guards here */
class DiagonalPrinter : public StringPrinter
{
public:
    DiagonalPrinter(std::string strf = "",
                    std::string strl = "",
                    std::ostream &os = std::cout) : StringPrinter(os), firstline(strf), lastline(strl) {}

    virtual DiagonalPrinter *Clone() const;
    virtual StringPrinter &operator()(const std::string &str);

private:
    std::string firstline;
    std::string lastline;
};
/* TODO: class DiagonalPrinter
 * ------------
 * Description:
 * A class that is used to print strings diagonally (see below).
 * The class inherits (public inheritance) class StringPrinter.
 * ------------
 * Functions:
 *
 * A constructor that takes three parameters:
 *  - The first line, which is "" by default, i.e. it is not printed at all
 *  - The last line, which is "" by default, i.e. it is not printed at all either
 *  - A reference to the output stream, which is std::cout by default
 *
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * DiagonalPrinter prints a string diagonally. For the string "like this":
<first line>\n
l        \n
 i       \n
  k      \n
   e     \n
         \n
     t   \n
      h  \n
       i \n
        s\n
<last line>\n
 * where <first line> and <last line> are replaced by the strings given in the
 * constructor. If the first line is empty, it is not printed. The same applies
 * to the last line.
 */

#endif