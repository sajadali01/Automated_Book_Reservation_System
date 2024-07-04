#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Book.h"
#include "Library_database.h"
using namespace std;

class Account {
private:    
    int no_lost_books;          // Number of lost books
    float fine_amount;          // Amount of fine for late returns

public:
    // Constructor
    Account();

    void set_n_lost(int n);
    void set_n_reserved(int n);

    // Calculate fine for late returns
    void calculate_fine();

    // Getter methods for the number of borrowed, lost, and reserved books

    int get_n_lost();
    int get_n_reserved();

    // Return a borrowed book
    bool return_book(string isbn);

    // Report a book as lost
    bool report_loss(Library_Database* ldb);
};
