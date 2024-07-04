# Automated Book Reservation System

The Library Management System is a comprehensive software solution designed to efficiently manage and organize the operations of a library. This project provides a user-friendly interface for library staff,admin and users to perform various tasks related to borrowing, returning, searching, and managing books, as well as handling user accounts and fines.

**This is a console base reservation system, it is well organized and check for every error that would be produced by consumer.**

**This system is made using concepts of fundamentals of software engineering, _SDLC(Specifications/Requirements,Design,Development,Testing) these phases are used. This system is made using agile approach, Requirement Gathering, Testing and Validation all is done in this project._**

**All SRS Document, SDS Document, Presentation, Project Proposal are attached in this repository**


## UML (USE-Case) Diagram

![USE_CASE_DIAGRAM](./assests/USE_CASE_DIAGRAM.JPG) 

## Features

The Library Management System project offers the following key features:

1. **Account Creation:**
      - In starting admin account will be created first, then admin will be creating accounts for librarian and users.

2. **User Management:**
   - Registration and login functionality for users, including staff and library members.
   - User roles and access levels to differentiate between staff and regular users.

3. **Book Management:**
   - Adding, editing, and deleting books from the library inventory.
   - Marking books as borrowed, reserved, lost, or available.
   - Tracking due dates for borrowed books.

4. **Borrowing and Returning:**
   - Users can borrow and return books through their accounts.
   - Automatic calculation of fines for lost book.
   - Handling reservations and requests for borrowing.

5. **Search and Display:**
   - Search functionality to find books based on title, author, or ISBN.
   - Display available, reserved, and borrowed books with detailed information.

6. **Reporting Lost Books:**
   - Users can report lost books, which will result in fines and updating the book's status.

7. **Fine Calculation:**
   - Automated calculation and display of fine amounts for late returns.

8. **User Dashboard:**
   - User-friendly dashboard for users to manage their borrowed and reserved books.

9. **Staff(Librarrian) Portal:**
   - Separate interface for library staff to manage book inventory, and user accounts, and handle administrative tasks.

## Prerequisites

Before you begin, ensure you have the following prerequisites:

- C++ compiler (compatible with C++11 or higher)
- IDE (Integrated Development Environment) for compiling and running the code

## Installation

1. Clone the repository to your local machine using:
```
git clone  https://github.com/sajadali01/Automated_Book_Reservation_System.git
`````
2. Open the project in your chosen IDE.
3. Compile and run the project using the appropriate build and execution options in your IDE.

## Instructions To Run Project

1. If using windows, then avoid makefile present in the directory, and just compile all the .cpp files then run output file.

2. It would be better if you use ubuntu/Linux, it will provide ease in compiling for you(makefile will do it for you) then run output.

3. In project, I have used system("clear"); which will clear screen in ubuntu(LINUX), so this command will not run in windows to clear screen, for that you have to make changes to system("cls");.