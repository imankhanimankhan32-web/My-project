#include <iostream>
#include <string>
using namespace std;

// Structure to represent a book
struct Book {
    int bookID;
    string title;
    string author;
    bool isAvailable;
};

// Function declarations
void addBook(Book *library, int &bookCount);
void displayBooks(Book *library, int bookCount);
void searchBookByID(Book *library, int bookCount, int searchID);
void searchBookByTitle(Book *library, int bookCount, string searchTitle);
void checkoutBook(Book *library, int bookCount, int checkoutID);
void returnBook(Book *library, int bookCount, int returnID);
void displayAvailableBooks(Book *library, int bookCount);
void updateBookDetails(Book *library, int bookCount, int updateID);
void removeBook(Book *library, int &bookCount, int removeID);
void displayBookStatus(Book *library, int bookCount, int checkID);

int main() {
    const int MAX_BOOKS = 100;
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice, bookID;
    string title, author;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Search Book by Title\n";
        cout << "5. Checkout Book\n";
        cout << "6. Return Book\n";
        cout << "7. Display Available Books\n";
        cout << "8. Update Book Details\n";
        cout << "9. Remove Book\n";
        cout << "10. Display Book Status\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library, bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                cout << "Enter Book ID to search: ";
                cin >> bookID;
                searchBookByID(library, bookCount, bookID);
                break;
            case 4:
                cout << "Enter Book Title to search: ";
                cin.ignore();  // To ignore any leftover newline character
                getline(cin, title);
                searchBookByTitle(library, bookCount, title);
                break;
            case 5:
                cout << "Enter Book ID to checkout: ";
                cin >> bookID;
                checkoutBook(library, bookCount, bookID);
                break;
            case 6:
                cout << "Enter Book ID to return: ";
                cin >> bookID;
                returnBook(library, bookCount, bookID);
                break;
            case 7:
                displayAvailableBooks(library, bookCount);
                break;
            case 8:
                cout << "Enter Book ID to update details: ";
                cin >> bookID;
                updateBookDetails(library, bookCount, bookID);
                break;
            case 9:
                cout << "Enter Book ID to remove: ";
                cin >> bookID;
                removeBook(library, bookCount, bookID);
                break;
            case 10:
                cout << "Enter Book ID to check status: ";
                cin >> bookID;
                displayBookStatus(library, bookCount, bookID);
                break;
            case 11:
                cout << "Exiting the system. Thank you!";
                return 0;
            default:
                cout << "Invalid choice, please try again.";
        }
    }

    return 0;
}

// Function to add a new book
void addBook(Book *library, int &bookCount) {
    if (bookCount < 100) {
        cout << "Enter Book ID: ";
        cin >> library[bookCount].bookID;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, library[bookCount].title);
        cout << "Enter Author Name: ";
        getline(cin, library[bookCount].author);
        library[bookCount].isAvailable = true;  // New book is available
        bookCount++;
        cout << "Book added successfully!" << endl;
    } else {
        cout << "Library is full, cannot add more books." << endl;
    }
}

// Function to display all books
void displayBooks(Book *library, int bookCount) {
    if (bookCount == 0) {
        cout << "No books in the library." << endl;
    } else {
        for (int i = 0; i < bookCount; i++) {
            cout << "Book ID: " << library[i].bookID << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Available: " << (library[i].isAvailable ? "Yes" : "No") << endl;
            cout << "-----------------------------\n";
        }
    }
}

// Function to search a book by ID
void searchBookByID(Book *library, int bookCount, int searchID) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].bookID == searchID) {
            cout << "Book found!" << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Available: " << (library[i].isAvailable ? "Yes" : "No") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to search a book by title
void searchBookByTitle(Book *library, int bookCount, string searchTitle) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].title == searchTitle) {
            cout << "Book found!" << endl;
            cout << "Book ID: " << library[i].bookID << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Available: " << (library[i].isAvailable ? "Yes" : "No") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to checkout a book
void checkoutBook(Book *library, int bookCount, int checkoutID) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].bookID == checkoutID) {
            if (library[i].isAvailable) {
                library[i].isAvailable = false;
                cout << "Book checked out successfully!" << endl;
            } else {
                cout << "Book is already checked out." << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to return a book
void returnBook(Book *library, int bookCount, int returnID) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].bookID == returnID) {
            if (!library[i].isAvailable) {
                library[i].isAvailable = true;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "Book was not checked out." << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to display available books
void displayAvailableBooks(Book *library, int bookCount) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isAvailable) {
            cout << "Book ID: " << library[i].bookID << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "-----------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No available books." << endl;
    }
}

// Function to update book details
void updateBookDetails(Book *library, int bookCount, int updateID) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].bookID == updateID) {
            cout << "Enter new Title: ";
            cin.ignore();
            getline(cin, library[i].title);
            cout << "Enter new Author: ";
            getline(cin, library[i].author);
            cout << "Book details updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to remove a book
void removeBook(Book *library, int &bookCount, int removeID) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].bookID == removeID) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1]; // Shift books down
            }
            bookCount--;
            cout << "Book removed successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to display book status 
void displayBookStatus(Book *library, int bookCount, int checkID) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].bookID == checkID) {
            cout << "Book Status: " << (library[i].isAvailable ? "Available" : "Checked out") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

