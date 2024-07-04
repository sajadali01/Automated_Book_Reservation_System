#include "User.h"
using namespace std;
// Function to validate whether a string has spaces or not
bool valid_Name_User(string name)
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
// Constructor for User class with Library_Database pointer
User::User (Library_Database* libraryDB) : l_db(libraryDB)
{
    name = "";
    id = 0;
}
// Function to verify user's name and ID
bool User::verify(string n, int i)
{
    return n == name && i == id;
}
// Getter function for user's ID
int User::get_id() { return id; }
// Getter function for user's name
string User::get_name() { return name; }
// Setter function for user's ID
void User::set_id(int i) { id = i; }
// Setter function for user's name
void User::set_name(string n) { name = n; }
// Setter function for user's type
void User::set_type(string t) { type = t; }
// Getter function for user's type
string User::get_type() { return type; }
// Function to handle the user's panel

void User::databasedelay()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void User::user_panel(User* user)
{
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t***** USER PORTAL *****\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n";
    while (1)
    {
        cout << "[1] CHECK RESERVED BOOKS\n";
        cout << "\n[2] CHECK LOST BOOKS\n";
        cout << "\n[3] CHECK BORROWED BOOKS\n";
        cout << "\n[4] CHECK ALL BOOKS\n";
        cout << "\n[5] SEARCH A BOOK\n";
        cout << "\n[6] BORROW A BOOK\n";
        cout << "\n[7] RETURN A BOOK\n";
        cout << "\n[8] REPORT A LOST BOOK\n";
        cout << "\n[9] LOGOUT AS USER\n";
        cout << "\nENTER YOUR OPTION HERE: ";
        int choice;
        while (!(cin >> choice)) {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
            cout << "\nPLEASE ENTER YOUR OPTION HERE AGAIN: ";
        }
        if (choice == 1)
        {
            cout << "\n=====================\n";
            cout << "| =========RESERVED BOOKS ARE========= |" << endl;
            cout << "TITLE          AUTHOR         ISBN           STATUS         DUE DATE" << endl;
            for (int i = 0; i < l_db->index; i++)
            {
                if(l_db->books[i].checkReserved())
                {
                    cout<< std::left << setw(15) << l_db->books[i].get_title() << setw(15) << l_db->books[i].get_author() << setw(15) << l_db->books[i].get_isbn() << setw(15) << l_db->books[i].reservationStatus() << setw(15) << l_db->books[i].get_due_date() << endl;
                }
            }
            cout << "=====================\n\n";
        }
        else if (choice == 2) {
            cout << "\n=====================\n";
            cout << "| =========LOST BOOKS ARE========= |" << endl;
            cout << "TITLE          AUTHOR         ISBN           STATUS         DUE DATE" << endl;
            for (int i = 0; i < l_db->index; i++)
            {
                if(l_db->books[i].checkLost())
                {
                    cout<< std::left << setw(15) << l_db->books[i].get_title() << setw(15) << l_db->books[i].get_author() << setw(15) << l_db->books[i].get_isbn() << setw(15) << l_db->books[i].reservationStatus() << setw(15) << l_db->books[i].get_due_date() << endl;
                }
            }
            cout << "=====================\n\n";
        }
        else if (choice == 3)
        {
            cout << endl;
            cout << "\n=========================\n";
            cout << "| =========BORROWED BOOKS ARE========= |" << endl;
            cout << "TITLE          AUTHOR         ISBN           STATUS         DUE DATE" << endl;
            for (int i = 0; i < l_db->index; i++)
            {
                if(l_db->books[i].checkBorrowed())
                {
                    cout<< std::left << setw(15) << l_db->books[i].get_title() << setw(15) << l_db->books[i].get_author() << setw(15) << l_db->books[i].get_isbn() << setw(15) << l_db->books[i].reservationStatus() << setw(15) << l_db->books[i].get_due_date() << endl;
                }
            }
            cout << "\n=========================\n\n";
        }
        else if (choice == 4) {
            cout << endl;
            l_db->disPlayBooks();
        }
        else if (choice == 5)
        {
            l_db->searchuser();
        }
        else if (choice == 6)
        {
            cout << endl;
            l_db->disPlayBooks();
            string typeU = user->type;
            l_db->borrow_book(typeU);
        }
        else if (choice == 7)
        {
            cout << endl;
            l_db->disPlayBooks();
            cout << "\nENTER ISBN OF BOOK YOU WANT TO RETURN [NO SPACE ALLOWED]: ";
            string isbn;
            getline(cin >> ws, isbn);
            while (valid_Name_User(isbn))
            {
                cout << "\nERROR! SPACES WERE DETECTED IN BOOK ISBN\n";
                cout << "\nPLEASE ENTER ISBN OF BOOK YOU WANT TO RETURN AGAIN [NO SPACE ALLOWED]: ";
                getline(cin >> ws, isbn);
            }
            bool exists = false;

            int z = 0,y;
            for(z = 0; z < l_db->index; z++)
            {
                if (l_db->books[z].get_isbn() == isbn)
                {
                    l_db->books[z].set_borrowed(false);
                    l_db->books[z].set_due_date("N/A");
                    cout << "\n==============================\n";
                    cout << "| BOOK RETURNED SUCCESSFULLY |\n";
                    cout << "==============================\n\n";
                    if(l_db->books[z].getReservation()){
                        l_db->books[z].set_borrowed(true);
                        l_db->books[z].setReservation(false);
                        string typeU = user->type;
                        string currentDate = l_db->getCurrentDateAsString();
                        string returnDate = l_db->calculateReturnDate(currentDate,typeU);
                        l_db->books[z].set_due_date(returnDate);
                        cout << "\n==============================\n";
                        cout << "| BOOK AGAIN BORROWED |\n";
                        cout << "| Book GIVEN TO USER [" << this->get_name() << "]\n";
                        cout << "==============================\n\n";
                    }
                    exists = true;
                    break;
                }
            }
            if(!exists){
                cout << "\n*** ERROR, BOOK DOES NOT EXIST IN THE DATABASE ***\n";
            }
        }
        else if (choice == 8) {
            acc.report_loss(l_db);
        }
        else if (choice == 9)
            return;
    }
}