#ifndef STANDARD_PRINTER_H
#define STANDARD_PRINTER_H
#include "string_printer.hpp"

/* Add include guards here */

class StandardPrinter : public StringPrinter
{
public:
    StandardPrinter(std::ostream &os = std::cout) : StringPrinter(os) {}
    virtual StandardPrinter *Clone() const;
    virtual StringPrinter &operator()(const std::string &str);
};

/* TODO: class StandardPrinter
 * ------------
 * Description:
 * A minimal StringPrinter implementation with no special functionality.
 * ------------
 * Functions:
 * A constructor that takes a single parameter:
 *  - A reference to the output stream, which is std::cout by default
 *
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * StandardPrinter prints a string like one normally would but with a
 * newline at the end. For the string "like this":
like this\n
*/
#endif