#include "book.hpp"
#include <ctime>
#include <iostream>

Book::Book(const std::string &name, const std::string &author, const std::string &ISBN, bool state, Date duedate)
{
    this->name_ = name;
    this->author_ = author;
    this->isbn_ = ISBN;
    this->loaned_ = state;
    this->due_date_ = duedate;
}

/* GetName:
    * returns the Book's name as a string, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */

std::string Book::GetName() const
{
    return name_;
}

/* GetAuthor:
    * returns the Book's author as a string, takes no parameters. 
    * This function should not alter the Book object's state, in other words the function should be const.
    */
std::string Book::GetAuthor() const
{
    return author_;
}

/* GetISBN:
    * returns the Book's ISBN as a string, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */
std::string Book::GetISBN() const
{
    return isbn_;
}

/* GetStatus:
    * returns the Book's status as a bool, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */
bool Book::GetStatus() const
{
    return loaned_;
}

/* GetDueDate:
    * returns the Book's due date, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */
Date Book::GetDueDate() const
{
    return due_date_;
}

/* Loan:
    * sets the due date to current date + 1 month, e.g. loaned on 1.9. => due date 1.10.
    * sets the status to true
    * returns true if loaning was succesful and false if it was not
    * Hint: there is a function Today in the Date struct that returns the current date
    */
bool Book::Loan(){

    if (GetStatus()==false)
    {
        due_date_ = Date::Today();
        due_date_.month++;
        loaned_ = true;
        return true;
    }
    else
        return false;
}

/* Restore:
    * sets the due date to 0-0-0
    * sets the status to false
    * returns nothing
    */
void Book::Restore(){
    if(GetStatus() == true)
    {
        due_date_.day = 0;
        due_date_.month = 0;
        due_date_.year = 0;
        loaned_ = false;
    }

}

/* Print:
    * prints the book's information to the standard output stream.
    * The function takes no parameters and returns nothing. 
    * The output format should be like the following:
Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
    * This function should not alter the Book object's state, in other words the function should be const.
    */
void Book::Print()const{
    std::cout << "Book: " << GetName() << ", author: " << GetAuthor()\
         << ", ISBN: " << GetISBN() << ", loaned " << (GetStatus()? "true":"false") \
         << ", due date: " << due_date_.day << "." << due_date_.month \
         << "." << due_date_.year << std::endl;
}
