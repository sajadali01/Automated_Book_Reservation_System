#include "Book.h"
using namespace std;

// Constructor
Book::Book()
{
    // Initialize member variables to default values
    title = "";
    author = "";
    isbn = "";
    is_reserved = false;
    is_borrowed = false;
    deleted_book = false;
    lost_book = false;
    due_date = "";
}

// Setter method for 'is_borrowed' status
void Book::set_borrowed(bool s)
{
    is_borrowed = s;
}

// Setter method for 'deleted_book' status
void Book::set_deleted_book(bool t)
{
    deleted_book = t;
}

// Setter method for 'lost_book' status
void Book::set_lost_book(bool t)
{
    lost_book = t;
}

// Setter method for 'title'
void Book::set_title(string t)
{
    title = t;
}

// Setter method for 'author'
void Book::set_author(string a)
{
    author = a;
}

// Setter method for 'isbn'
void Book::set_isbn(string i)
{
    isbn = i;
}

// Setter method for 'due_date'
void Book::set_due_date(string dat)
{
    due_date = dat;
}

// Getter method for 'title'
string Book::get_title()
{
    return title;
}

// Getter method for 'author'
string Book::get_author()
{
    return author;
}

// Getter method for 'isbn'
string Book::get_isbn()
{
    return isbn;
}

// Getter method for 'due_date'
string Book::get_due_date()
{
    return due_date;
}

// Determine the reservation status of the book
bool Book::checkReserved()
{
    if (is_reserved)
    {
        return true;
    }
    else {
        return false;
    }
}
void Book::setReservation(bool s){
    is_reserved = s;
}

bool Book::getReservation(){
    return is_reserved;
}

// Display due date of the book
void Book::show_due_date()
{
    cout << "Book is due on " + due_date << endl;
}

// Display reservation status of the book
void Book::show_res_status()
{
    if (is_reserved)
        cout << "\n*** ERROR! THE BOOK IS RESERVED ***\n\n" << endl;
    else
        cout << "\n*** BOOK IS NOT RESERVED ***\n\n" << endl;
}

string Book::reservationStatus(){
    if(is_borrowed){
        return "BORROWED";
    }
    else if(is_reserved){
        return "RESERVED";
    }
    else if(lost_book){
        return "LOST";
    }
    else if(deleted_book)   
        return "DELETED";
    else 
        return "AVAILABLE";
}

// Process a book request
bool Book::book_request()
{
    if (is_borrowed)
    {
        cout << "\n*** BOOK IS ALREADY BORROWED ***\n\n" << endl;
        is_reserved = true;
        return false;
    }
    else
    {
        is_borrowed = true;
        return true;
    }
}

bool Book::checkBorrowed(){
    if (is_borrowed)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Book::checkLost()
{
    if (lost_book)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Renew book information
void Book::renew_info()
{
    due_date = "";
    is_borrowed = false;
}
