#ifndef ELEC_AS_CPP_LIBRARY
#define ELEC_AS_CPP_LIBRARY

#include <string>
#include <vector>
#include "book.hpp"
#include "customer.hpp"

typedef std::vector<Customer> Customers;

class Library {
public:
    /* Library:
    * the constructor of the Library class, takes following parameters:
    *  - the library's name (const reference to string)
    */
   Library(const std::string& Lname);    

    /* GetName:
    * returns the library's name as a string, takes no parameters.
    * This function should not alter the Library object's state, in other words the function should be const.
    */
    
    const std::string GetName();

    /* GetBooks:
    * returns the Library's books as a reference to a vector<Book>, takes no parameters.
    */

   Books& GetBooks();
    

    /* GetCustomers:
    * returns the Library's customers as a reference to a vector<Customer>, takes no parameters.
    */
   Customers &GetCustomers();

   /* FindBookByName:
    * returns a Book, takes a const reference to a string as a parameter,
    * if a Book is not found, a new book with an empty strings as parameters 
    * for the name, author and isbn is returned.
    */

   Book FindBookByName(const std::string& Bname);
    

    /* FindBooksByAuthor:
    * returns a vector of Books, takes a const reference to a string as a parameter,
    * if no books are found, an empty vector is returned.
    */
   Books FindBooksByAuthor(const std::string& BAuthor);
    

    /* FindAllLoanedBooks():
    * returns a vector of Books, takes no parameters,
    * if no books are found, an empty vector is returned.
    */

   Books FindAllLoanedBooks();
    

    /* FindCustomer:
    * returns a Customer, takes a const reference to a string representing the Customer's id as a parameter,
    * if a Customer is not found, a new Customer with empty strings are parameters 
    * for name and id is returned.
    */
   Customer FindCustomer(const std::string& Customer_id);
    

private:
    /* Make variables for:
    * name (string)
    * books (vector<Book>)
    * customers (vector<Customer>)
    */

   std::string name_;
   Books books_;
   Customers customers_;
};

#endif
