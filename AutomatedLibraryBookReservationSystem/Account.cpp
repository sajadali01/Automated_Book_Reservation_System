#include "Account.h"
using namespace std;

// Function to check if a name contains spaces
bool valid_Name_ACC(string name)
{
    for (int i = 0; i < name.length(); i++)
    {
        if (name.at(i) == ' ')
        {
            return true;
        }
    }
    return false;
}

// Constructor
Account::Account() {
    no_lost_books = 0;
    fine_amount = 0;
}

void Account::set_n_lost(int n) { no_lost_books = n; }


// Calculate fine for late returns
void Account::calculate_fine() {
    cout << "\n==========================\n";
    cout << "| ==========Reported Successfully!!==========\n";
    cout << "| FINE AMOUNT: " << setw(9) << fine_amount << " |\n";
    cout << "==========================\n\n";
}

// Getter methods for the number of borrowed, lost, and reserved books
int Account::get_n_lost() {
    return no_lost_books;
}

// Report a book as lost
bool Account::report_loss(Library_Database* ldb)
{
    cout << "ENTER ISBN OF THE BOOK YOU WANT TO REPORT FOR LOST [NO SPACE ALLOWED]: ";
    string isbn;
    getline(cin >> ws, isbn);
    while (valid_Name_ACC(isbn))
    {
        cout << "\nERROR! SPACES WERE DETECTED IN BOOK ISBN\n\n";
        cout << "\nPLEASE ENTER ISBN OF BOOK YOU WANT TO REPORT FOR LOST AGAIN [NO SPACE ALLOWED]: ";
        getline(cin >> ws, isbn);
    }
    for (int i = 0; i < ldb->index; i++)
    {
        if (isbn == ldb->books[i].get_isbn())
        {
            no_lost_books++;
            ldb->books[i].set_lost_book(true);
            ldb->books[i].set_due_date("N/A");
            ldb->books[i].set_borrowed(false);
            
            fine_amount += 2000;
            calculate_fine();
            return true;
        }
    }
    cout << "\n*** ERROR! INVALID ISBN ***\n\n";
    return false;
}
