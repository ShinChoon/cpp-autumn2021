#include <iostream>
#include "book.hpp"
#include "customer.hpp"
#include "library.hpp"

/* Library:
    * the constructor of the Library class, takes following parameters:
    *  - the library's name (const reference to string)
    */
Library::Library(const std::string &Lname){
    name_ = Lname;
}

/* GetName:
    * returns the library's name as a string, takes no parameters.
    * This function should not alter the Library object's state, in other words the function should be const.
    */

const std::string Library::GetName(){
    return name_;
}

/* GetBooks:
    * returns the Library's books as a reference to a vector<Book>, takes no parameters.
    */

Books& Library::GetBooks(){
    return books_;
}

/* GetCustomers:
    * returns the Library's customers as a reference to a vector<Customer>, takes no parameters.
    */
Customers& Library::GetCustomers(){
    return customers_;
}

/* FindBookByName:
    * returns a Book, takes a const reference to a string as a parameter,
    * if a Book is not found, a new book with an empty strings as parameters 
    * for the name, author and isbn is returned.
    */

Book Library::FindBookByName(const std::string &Bname)
{
    for(auto i : books_){
        if (i.GetName() == Bname){
            return i;
        }
    }
    Book newbook("","","");
    return newbook;
}

/* FindBooksByAuthor:
    * returns a vector of Books, takes a const reference to a string as a parameter,
    * if no books are found, an empty vector is returned.
    */
Books Library::FindBooksByAuthor(const std::string &BAuthor){
    Books books_found;
    for(auto i : books_){
        if (i.GetAuthor() == BAuthor)
        {
            books_found.push_back(i);
        }
    }
    return books_found;
}

/* FindAllLoanedBooks():
    * returns a vector of Books, takes no parameters,
    * if no books are found, an empty vector is returned.
    */

Books Library::FindAllLoanedBooks(){
    Books loanedbooks;
    if(books_.size() <= 0)
    {
        Books emptyBooks;
        return emptyBooks;
    }
    for(auto i : books_){
        if (i.GetStatus()==true)
        {
            loanedbooks.push_back(i);
        }
    }
    return loanedbooks;
}

/* FindCustomer:
    * returns a Customer, takes a const reference to a string representing the Customer's id as a parameter,
    * if a Customer is not found, a new Customer with empty strings are parameters 
    * for name and id is returned.
    */
Customer Library::FindCustomer(const std::string &Customer_id){
    for(auto i : customers_){
        if (i.GetID() == Customer_id)
            return i;
    }
    Customer emptyCustomer("","");
    return emptyCustomer;

}
