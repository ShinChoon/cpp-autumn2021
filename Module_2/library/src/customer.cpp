#include "customer.hpp"

/* Customer:
    * the constructor of the Customer class, takes the following parameters:
    * - the customer's name (reference to const string), 
    * - the customer number (reference to const string).
    */
Customer::Customer(const std::string& name, const std::string& number){
    name_ = name;
    customer_id_ = number;
}

/* GetName:
    * returns the Customer's name as a string, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */

const std::string& Customer::GetName() const
{
    return name_;
}

/* GetID:
    * returns the Customer's customer number as a string, takes no parameters. 
    * This function should not alter the Customer object's state, in other words the function should be const.
    */

std::string Customer::GetID() const
{
    return customer_id_;
}

/* GetLoanAmount:
    * returns the Customer's number of loans as an int, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */

int Customer::GetLoanAmount() const
{
    return books_.size();
}

/* GetLoans:
    * returns the Customer's loans as a vector<Book>, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */

Books Customer::GetLoans()const
{
    return books_;
}

/* LoanBook:
    * loans a book for the customer
    * takes a reference to a book as a parameter and returns the result of loaning (from Book loan-function).
    */

bool Customer::LoanBook(Book& book_)
{
    bool status = book_.Loan();
    if (status == true)
        books_.push_back(book_);
    return status;
}

/* ReturnBook:
    * returns a book from the customer
    * takes a reference to a book as a parameter and returns nothing.
    */
void Customer::ReturnBook(Book &book_)
{
    int ind = 0;
    for(auto i:books_){
        if (i.GetName() == book_.GetName())
        {
            book_.Restore();
            books_.erase(books_.begin()+ind);
        }
        else
            ind++;
            
    }
}

/* Print:
    * prints the customer's information to the standard output stream.
    * The function takes no parameters and returns nothing. 
    * The output format should be like the following (for 2 loans):
Customer: <name>, <customer_id>, has <number_of_loans> books on loan:\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
    * This function should not alter the Customer object's state, in other words the function should be const.
    */

void Customer::Print()const
{
    std::cout << "Customer: " << GetName() << ", " << GetID() << ", has "\
              << GetLoanAmount() << " books on loan:" << std::endl;
    for (auto it : books_)
    {
        std::cout << "- Book: " << it.GetName() << ", author: " << it.GetAuthor()\
                  << ", ISBN: " << it.GetISBN() << ", loaned " << (it.GetStatus() ? "true" : "false")\
                  << ", due date: " << it.GetDueDate().day << "." << it.GetDueDate().month\
                  << "." << it.GetDueDate().year << std::endl;
    }
}